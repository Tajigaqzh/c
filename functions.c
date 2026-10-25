#include <stdio.h>

#include "functions.h"

int numSum(int k)
{
    if (k > 0)
    {
        return k + numSum(k - 1);
    }
    else if (k == 0)
    {
        return 0;
    }
    else
    {
        return k + numSum(k + 1);
    }
}

void fileOperation(void)
{
    FILE *file = NULL;

    // a 以追加模式打开文件，如果文件不存在则创建新文件
    // w 以写入模式打开文件，如果文件不存在则创建新文件，如果文件存在则清空文件内容
    // r 以读取模式打开文件，如果文件不存在则返回错误
    if (fopen_s(&file, "test.txt", "w") != 0)
    {
        return;
    }

    fprintf(file, "Hello World\n");
    fclose(file);

    FILE *file2 = NULL;

    if (fopen_s(&file2, "test.txt", "r") != 0)
    {
        return;
    }

    char myString[100];
    while (fgets(myString, sizeof(myString), file2) != NULL)
    {
        printf("%s", myString);
    }

    fclose(file2);
}
