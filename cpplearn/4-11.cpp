// 引用对象
// 数据成员 函数成员的参数、返回类型 都可以为引用
// 被引用的对象可以是简单的类型 也可以是类的对象
// 引用变量是被引用对象的别名 因此引用不存在构造和析构。
// 如果使用 A & a = * new A(0); 的方式引用了一个对象，那么就需要我们手动delete掉。
// 只是调用a.~A()是没用的 因为析构并不会释放内存空间

// 如果将右值传入普通引用则会导致产生匿名变量  匿名变量只存在在产生该变量的函数中 和局部变量一样 在函数返回前析构

#include <iostream>
using namespace std;
class A{
    int i;
    public:
    A(int i){
        A::i=i; cout<<"A i"<<i<<endl;
        
    }
    ~A(){
        cout<<"~A i"<<i<<endl;
    }
};

int main(int argc, char const *argv[])
{
    A & p = A(3);
    A(4),cout<<"A4 cout\n";
    cout<<"call A5\n"<<A(5);
    cout<<"Main Exit\n";
    return 0;
}
