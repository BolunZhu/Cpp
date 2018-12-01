// 普通友元
// 包括main函数在内的所有函数都可以定义为类的普通友元
// 重载函数中只有声明了的能够访问 没声明的就不是友元 
// 但是友元函数的参数是可以缺省和省略的 这不影响

// static 和 virtual 用于定义函数成员 故他们不能和friend同时使用

// 在类中定义函数的函数体是可以的  这个时候函数会变成全局普通函数 作用于在当前程序文件
#include <iostream>
class A{
    int i;
    public:
    friend int get(A & a){return a.i;}
    //在类中定义函数体的普通友元缺省为内联函数 存储类为static 
    // main 为 extern 所以不能在类体中定义main的函数体
    A(int x){i =x;};
};

int main(int argc, char const *argv[])
{
    A a(1);
    std::cout<<get(a);
    return 0;
}

// 如果在类里面定义了一个main函数体 则这个函数只是一个局部于这个程序文件的局部函数

class B{
    int i;
    friend int main(void){//其实编译器还是会报错 
        // ...
        return 1;
    }
}
