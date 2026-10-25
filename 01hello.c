#include <stdio.h>
#include <string.h>
#include "getarea.h"
#include "traverse.h"
#include "functions.h"


int main()
{
    printf("hello world\n");

    int age = 20;

    printf("Age: %d\n", age);

    printf("%d\n", 20);

    int area = getArea(10, 20);

    printf("Area: %d\n", area);

    int a = 20, b = 30;

    printf("a>b:%d\n", a > b);

    int nums[5] = {
        1, 2, 3, 4, 5};

    printf("nums[0]:%d\n", nums[0]);

    printf("nums[1]:%d\n", nums[1]);

    printf("nums[2]:%d\n", nums[2]);

    printf("nums[3]:%d\n", nums[3]);

    printf("nums[4]:%d\n", nums[4]);

    // 输出数组大小和数组长度

    printf("sizeof(nums):%zu\n", sizeof(nums)); // 20  一个int是4个字节，5个int就是20个字节

    int length = sizeof(nums) / sizeof(nums[0]); // 5  20 / 4 = 5;  数组长度=数组大小/数组元素大小
    printf("length:%d\n", length);

    // printf("sizeof(nums[0]):%zu\n", sizeof(nums[0]));

    int sum = 0;
    float avg = 0.0;

    // 数组循环
    for (int i = 0; i < length; i++)
    {
        sum += nums[i];
        printf("nums[%d]:%d\n", i, nums[i]);
    }

    avg = (float)sum / length;

    printf("sum:%d\n", sum);
    printf("avg:%.2f\n", avg);

    // C语言中，字符串是以'\0'结尾的字符数组，所以在定义字符串时，需要预留一个额外的空间来存放'\0'，因此定义字符串时需要比实际字符数多一个字节。  它内部会补充一个\0,表示字符串的结束。
    char str[29] = "hello world! 你好啊世界";

    printf("str:%s\n", str);

    printf("sizeof(str):%zu\n", sizeof(str));   // 29  29个字节
    printf("length of str:%zu\n", strlen(str)); // 28  字符串长度不包括'\0'

    for (int i = 0; i < strlen(str); i++)
    {
        printf("str[%d]:%c\n", i, str[i]);
    }

    printf("traverseString:\n");

    traverseString(str);

    printf("getUtf8Char:\n");
    char output[5];
    if (getUtf8Char(str, 0, output) == 1)
    {
        printf("First character: %s\n", output);
    }

    int myAge = 26;

    int *pAge = &myAge;

    int hisAge = 30;
    int *pHisAge = &hisAge;

    int **ppage = &pHisAge;

    printf("myAge: %d\n", myAge);

    printf("%p\n", pAge); // 地址

    printf("%d\n", *pAge); // 26  解引用

    printf("\\\\\\\\\\\\\\\\---分割线---\\\\\\\\\\\\\\\\n");

    printf("hisAge: %d\n", hisAge);

    printf("%p\n", pHisAge); // 地址

    printf("%d\n", *pHisAge); // 30  解引用

    printf("%p\n", ppage);   // 地址
    printf("%p\n", *ppage);  // 地址
    printf("%d\n", **ppage); // 30  解引用

    int myNumbers[4] = {10, 20, 30, 40};

    printf("%p\n", myNumbers);     // 地址   数组名称实际上指向数组第一个元素
    printf("%p\n", &myNumbers[0]); // 地址   输出结果等于上一行

    // 获取第一个元素
    printf("%d\n", *myNumbers); // 10  解引用
    // 获取第二个元素
    printf("%d\n", *(myNumbers + 1)); // 20  解引用

    int *numberIndex = myNumbers; // 指针指向数组第一个元素

    // 遍历
    for (int i = 0; i < 4; i++)
    {
        printf("myNumbers[%d]:%d\n", i, *(numberIndex + i));
    }

    // 使用指针修改数组元素
    for (int i = 0; i < 4; i++)
    {
        *(numberIndex + i) += 5; // 将每个元素加5
    }

    // 遍历修改后的数组
    for (int i = 0; i < 4; i++)
    {
        printf("myNumbers[%d]:%d\n", i, *(numberIndex + i));
    }

    int sumResult = numSum(20);

    printf("sumResult: %d\n", sumResult); // 输出结果为 210，表示从 1 到 20 的整数之和。

    printf("numSum(-5): %d\n", numSum(-5)); // 输出结果为 -15，表示从 -5 到 0 的整数之和。


    fileOperation();
    
    return 0;
}

