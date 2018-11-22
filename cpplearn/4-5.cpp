// 指定名字空间和声明成员引用是不同的
// 声明成员引用会把名字空间的成员加入当前作用域 从而不能再定义和引用名字空间成员同民的标识符
// 如以下程序
#include <iostream>
namespace A{
    float a=0,b=0;
    float d(float y){return y;}
}
namespace B{
    void g(){std::cout<<"B\n";}

}
int main(int argc, char const *argv[])
{
    // int a=1; // 如果先声明了a 就不能再using A::a 了 
    using A::a;
    using A::d;
    using B::g;
    // long a =1; // 错误 
    a = d(1.1);
    g();
    return 0;
}
