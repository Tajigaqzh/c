
#include <stdio.h>
#include <string.h>

#include "traverse.h"

void traverseString(const char *str)
{
    if (str == NULL)
    {
        return;
    }

    const unsigned char *text = (const unsigned char *)str;
    size_t byte_length = strlen(str);
    size_t byte_index = 0;
    size_t char_index = 0;

    while (byte_index < byte_length)
    {
        unsigned char first = text[byte_index];
        size_t char_bytes;

        if ((first & 0x80) == 0)
        {
            char_bytes = 1;
        }
        else if ((first & 0xE0) == 0xC0)
        {
            char_bytes = 2;
        }
        else if ((first & 0xF0) == 0xE0)
        {
            char_bytes = 3;
        }
        else if ((first & 0xF8) == 0xF0)
        {
            char_bytes = 4;
        }
        else
        {
            printf("str[%zu]:<invalid UTF-8 byte 0x%02X>\n",
                   char_index, (unsigned int)first);
            byte_index++;
            char_index++;
            continue;
        }

        if (byte_index + char_bytes > byte_length)
        {
            printf("str[%zu]:<incomplete UTF-8 character>\n", char_index);
            break;
        }

        int valid = 1;
        for (size_t i = 1; i < char_bytes; i++)
        {
            if ((text[byte_index + i] & 0xC0) != 0x80)
            {
                valid = 0;
                break;
            }
        }

        if (!valid)
        {
            printf("str[%zu]:<invalid UTF-8 character>\n", char_index);
            byte_index++;
            char_index++;
            continue;
        }

        printf("str[%zu]:", char_index);
        fwrite(text + byte_index, 1, char_bytes, stdout);
        putchar('\n');

        byte_index += char_bytes;
        char_index++;
    }
}

// 按字符下标获取一个 UTF-8 字符；成功返回 1，失败返回 -1。
int getUtf8Char(const char *str, size_t target_index, char output[5])
{
    // 检查输入字符串和输出数组是否为空指针。
    if (str == NULL || output == NULL)
    {
        // 参数无效，返回 -1 表示获取失败。
        return -1;
    }

    // 转成 unsigned char 指针，避免字节大于 127 时被当成负数。
    const unsigned char *p = (const unsigned char *)str;

    // 记录当前遍历到第几个 UTF-8 字符，下标从 0 开始。
    size_t current_index = 0;

    // 只要当前字节不是字符串结束符，就继续遍历。
    while (*p != '\0')
    {
        // 保存当前 UTF-8 字符占用的字节数。
        size_t char_bytes;

        // UTF-8 首字节以 0 开头时，这是一个单字节 ASCII 字符。
        if ((*p & 0x80) == 0)
        {
            // ASCII 字符占 1 个字节。
            char_bytes = 1;
        }
        // UTF-8 首字节以 110 开头时，当前字符占 2 个字节。
        else if ((*p & 0xE0) == 0xC0)
        {
            // 记录当前字符长度为 2 字节。
            char_bytes = 2;
        }
        // UTF-8 首字节以 1110 开头时，当前字符占 3 个字节。
        else if ((*p & 0xF0) == 0xE0)
        {
            // 常见中文字符通常占 3 个字节。
            char_bytes = 3;
        }
        // UTF-8 首字节以 11110 开头时，当前字符占 4 个字节。
        else if ((*p & 0xF8) == 0xF0)
        {
            // 许多 emoji 字符占 4 个字节。
            char_bytes = 4;
        }
        else
        {
            // 当前字节不是合法的 UTF-8 首字节，返回失败。
            return -1;
        }

        // 从第二个字节开始，检查当前字符的所有 UTF-8 后续字节。
        for (size_t i = 1; i < char_bytes; i++)
        {
            // 后续字节不能提前遇到字符串结尾，并且必须以二进制 10 开头。
            if (p[i] == '\0' || (p[i] & 0xC0) != 0x80)
            {
                // 当前 UTF-8 字符不完整或格式错误，返回失败。
                return -1;
            }
        }

        // 判断当前字符是不是调用者需要获取的目标字符。
        if (current_index == target_index)
        {
            // 把当前字符的全部 UTF-8 字节复制到输出数组。
            memcpy(output, p, char_bytes);

            // 在字符末尾添加 \0，使 output 成为合法的 C 字符串。
            output[char_bytes] = '\0';

            // 字符获取成功，返回 1。
            return 1;
        }

        // 跳过当前字符占用的全部字节，移动到下一个 UTF-8 字符。
        p += char_bytes;

        // 字符下标加 1。
        current_index++;
    }

    // 遍历到字符串末尾仍未找到，说明目标下标超出范围。
    return -1;
}

