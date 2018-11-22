// 名字空间
// 同一个名字空间内的标识符唯一，不同空间标识符可以不同
// 使用名字空间加作用域运算符限定成员避免同名
// namespace 用于定义名字空间 必须在程序的全局作用域定义 不能在函数及函数成员内定义 
// 最外层名字空间的名称必须在从程序的全局作用域内唯一 没有名字的名字空间为匿名名字空间 每个程序只能有一个匿名名字空间
// 名字空间可以多次定义 不断拓展
// using 用于声明程序要引用的名字空间成员 或者名字空间
// 在using某个成员之前这个成员必须已经在名字空间中声明了原型或者定义
// 如下程序展示了名字空间如何使用
#include <iostream>

namespace A
{
    extern int x;
    void g(int );
    void g(long ){
        std::cout<<"long argu\n";
    }
} // A

using A::x;
using A::g;
namespace A{
    int x = 5;
    void g(int){
        std::cout<<"int augu\n";
    }
    void g(void){
        std::cout<<"void augu\n";
    }
}
// using A::g;
int main(void){
    g(4); //void g(int)
    g(4L); //void g(long)
    std::cout<<"X="<<x;
    // g(); //cannot call g(void) . No define before using g;
    //上面这行会报错 如果在下面using则不报错
    return 0;
}
/*
➜  cpplearn git:(master) ✗ g++ 4-2.cpp
➜  cpplearn git:(master) ✗ ./a.out
int augu
long argu
X=5%
*/