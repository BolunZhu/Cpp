#include <iostream>
// 2-7:常量指针
int main(void)
{
    // 指针指向的变量不能被修改，则定义时应该使用const char *
    // 指针本身不能修改，则使用char * const
    const char * ptc;
    char * const cp = "Const pointer";
    const char * const cptc = "Cstptc";
    ptc = "pointer to constant"; //正确 指针本身不是只读
    *ptc = 'P' ; //错误 指针指向的内容只读
    cp = "adas"; //错误 指针本身只读
    *cp="Array of char"[0]; //新的骚操作 你学会了吗？
    cptc = "asda";
    *cptc = 'a';//两个都不可以 
    return 0;
}