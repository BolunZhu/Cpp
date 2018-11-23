// const volatile mutable 
// const 和 volatile 都可以用来修饰类的数据成员、函数成员的返回值、参数
// 使用不同的参数修饰符 ，会导致函数被认为是不同的函数 从而导致函数重载
// 只是使用const修饰的话 就一定要有构造函数否则我们不知道如何初始化
// volatile随便用啦

// 普通对象是不可以调用带const和volatile的函数成员的 需要一一对应
// 普通调用普通的 只读就调用只读的 volatile就调用volatile的
#include <iostream>
using namespace std;
const volatile int a=1;//const volatile可以修饰同一个对象
// 凡是const能够出现的地方volatile也能出现 而且可以同时出现
// 他们不能修饰构造和析构函数

class A{
    int a;
    public:
    int f(){
        a++;
        return a; //a could be changed
    }
    int f()const {
        // a++; // a cannot be changed
        return a;
    }
    int f()volatile{
        a++;
        return a;
    }
    int f()const volatile {
        // a++; // a still can't be changed
        return a;
    }
    A(int b=0){
        a=b;
    }
};

int main(int argc, char const *argv[])
{
    A a1;
    volatile A a2;
    const A a3(1);
    const volatile  A a4(1);
    a1.f();
    a2.f();
    a3.f();
    a4.f();
    return 0;
}
