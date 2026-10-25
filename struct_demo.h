#ifndef STRUCT_DEMO_H
#define STRUCT_DEMO_H

struct MyStruct
{
    int myNum;
    float myAccount;
    char myLetter;
    char description[50];
};

struct NestedStruct
{
    struct MyStruct innerStruct;
    int additionalField;
};

int structDemo(void);





typedef struct {
    char brandp[30];
    int year;
} Cat;



void updateYear(struct Cat *cat, int newYear);

#endif
