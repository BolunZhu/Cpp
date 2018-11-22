// 访问名字空间的成员有三种方式: 1直接访问 2声明引用成员 3声明引用名字空间
// 1. A::a 2.using A::a 3.using namespace A
// 但是如果声明引用成员、名字空间后， 这些名字又可能会重复 这时候必须要用直接访问进行访问
// 此外 名字空间可以嵌套 形成多个层次的作用域 v 因此访问的时候也需要多个作用域运算符
#include <iostream>
namespace A{
    int x=0;
    void f(){std::cout<<"A 's f\n";}
    namespace B{
        int x=1;
        void g(){
            std::cout<<"B 's g\n";
        }
    }
}

using A::f;
using A::x;
using A::B::g;
using A::B::x;
int main(int argc, char const *argv[])
{
    f();
    g();
    std::cout<<x;//会报错 x定义重复了
    return 0;
}
