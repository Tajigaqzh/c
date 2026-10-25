#include <stdio.h>
#include <string.h>

#include "struct_demo.h"

int structDemo(void)
{

  struct MyStruct s1; // 声明结构体变量

  s1.myNum = 10;        // 设置结构体成员
  s1.myAccount = 220.5; // 设置结构体成员
  s1.myLetter = 'A';    // 设置结构体成员

  printf("myNum: %d\n", s1.myNum);           // 输出结构体成员
  printf("myAccount: %.2f\n", s1.myAccount); // 输出结构体成员
  printf("myLetter: %c\n", s1.myLetter);     // 输出结构体成员

  // 错误方式
  // s1.description = "This is a sample structure"; // 设置描述字段

  // 正确方式
  snprintf(s1.description, sizeof(s1.description), "%s", "This is a sample structure"); // 设置描述字段

  // 或者初始化的时候就赋值
  struct MyStruct s2 = {20, 330.75, 'B', "This is another sample structure"};
  printf("s2 - myNum: %d, myAccount: %.2f, myLetter: %c, description: %s\n", s2.myNum, s2.myAccount, s2.myLetter, s2.description);

  printf("--------------------------------嵌套结构体----------------------------------");

  struct NestedStruct ns;
  ns.innerStruct.myNum = 30;
  ns.innerStruct.myAccount = 440.25;
  ns.innerStruct.myLetter = 'C';
  snprintf(ns.innerStruct.description, sizeof(ns.innerStruct.description), "%s", "This is a nested structure");
  ns.additionalField = 50;

  printf("ns - innerStruct: myNum: %d, myAccount: %.2f, myLetter: %c, description: %s\n", ns.innerStruct.myNum, ns.innerStruct.myAccount, ns.innerStruct.myLetter, ns.innerStruct.description);
  printf("ns - additionalField: %d\n", ns.additionalField);

  printf("--------------------------------结构体指针----------------------------------");

   Cat myCat = {"Whiskers", 2020};

   Cat *catPtr = &myCat; // 创建结构体指针并指向 myCat

  // 使用 -> 运算符访问成员
  printf("catPtr - brand: %s, year: %d\n", catPtr->brandp, catPtr->year);


   Cat cat2 = {"Tom", 2019};


  updateYear(&cat2, 2021); // 更新结构体成员

  printf("cat2 - brand: %s, year: %d\n", cat2.brandp, cat2.year);


  return 0;
}



void updateYear(Cat *cat, int newYear) {
    if (cat != NULL) {
        cat->year = newYear; // 更新结构体成员
    }
}