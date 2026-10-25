#ifndef TRAVERSE_H
#define TRAVERSE_H

// 按 UTF-8 字符逐个遍历并输出字符串内容。
void traverseString(const char *str);

// 按字符下标获取一个 UTF-8 字符；成功返回 1，失败返回 -1。
int getUtf8Char(const char *str, size_t target_index, char output[5]);

#endif
