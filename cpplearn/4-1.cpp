// 作用域
// 面向过程的传统c作用域按作用范围分为 1表达式 2函数 3文件 4整个程序
// 例如 1常量对象 2局部对象 函数参数 3静态变量 4全局变量
// 单目运算符限定存储累为static 和 extern 的全局变量、函数、类型、枚举元素等 3、4种变量可以用::单目运算符限定
// 面向对象的c++作用于按作用域分为 1表达式 2函数成员 3类、派生类 4基类 5虚基类
// 作用域越小 优先级越高
// 双目运算符用于限定类的数据成员、函数成员、类型成员
// 双目运算符还限定名字空间成员 恢复继承的成员的访问权限

// 如下程序 若在类A中定义一个类B 则类B的成员函数要么在B中定义 要么必须在A外定义 不能在A内B外定义
// 此时定义的时候应该用 A::B::fun
class A{
    class B{
        //some content
        int a;
        //...
        B(int b);
    } * Bp;
};

A::B::B(int b){
    a=b;
}

// 如下程序体现了作用域的使用方法
static int a=1;
extern int fun();
class A{
    int a;
    public:
    int fun();
};
int A::fun(){
    a++; // A.a ++
    ::a++;// static int a ++
    return ::fun();// extern fun  ,not A.fun
}

// 如果标识符和类名同名，则在名字前面加上class将其限定为类名
// 如下程序所示 定义了和类名同名的数据成员、构造函数成员 为了得到类名 使用单目::和class
class A{
    char * A;
    ::A * next;
    public:
    A(char * ,::A*);// equal to A(char * ,class A *)
};
//如果不加:: 或者 class 则这的A指的是数据成员A 因为他是函数的局部作用域 比类要小 从而要优先
#include <string.h>
A::A(char * name ,clss A * next =0)
{
    A = new char[strlen(name)+1];//A默认是数据成员A
    strcpy(A , name);//默认是数据成员A
    A::next = next;//限定A::next 为数据成员而非函数参数
}
int A; //定义整型变量A
class A w("aaa",0);//加上class用于表示这是个类A的声明
