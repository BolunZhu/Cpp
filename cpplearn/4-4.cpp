// 在某个作用域使用using namespace 指定名字空间后 该名字空间的所有成员都能被该作用的程序访问
// 在指定名字空间的时候不会占用你的标识符，所以即使引用的名字空间中有一个变量名 你仍旧可以使用这个变量名定义其他的变量等
// 不过这张情况下又会出现名字的重复 当名字空间的成员与全局标识符同名 使用单目运算符::可以限定全局标识符 当其与程序的局部标识符同名，则默认先访问局部标识符
#include <iostream>
int f1(){//全局的
    int sum=0;
    for(int i=0;i<100;i++){
        sum=sum+i;
    }
    return sum;
}
namespace A{
    //变量、函数、命名空间在A里面声明、并且初始化是可以的 ，
    int a=0;
    int b=f1();
    namespace B{int a=0;int b=0;int h();int d=0;}
    namespace C{namespace D{}}
    namespace D{int j=0;}
    using namespace B;//using后B中的标识符对A可见 比如可以用B中的标识符初始化定义A中的标识符
    using namespace C;
    // using namespace D;//错误 因为此时C中的D和A中的D都可见 所以重名
    int e=d;//这里的d是B中的d 因为using了B所以才能看到 
}
using namespace A;
int a=5; //这里不会出现问题 你仍旧可以使用a去声明定义一个变量
// int b=a; //这里会出现问题 因为分不清是谁
int c=::a; //这里使用单目运算符限定了 所以也不会出错
// int g=j; //错误 虽然using A的命名空间 但是在A的命名空间中j还是不可见的
int l= d; //正确 因为A using 了B 所以B中的d作用域扩大到A 而我们又using了A

int main(){
    using namespace A;
    int a=7; //优先局部变量
    int d=A::b; //都正确
    std::cout<<"c="<<c<<"d="<<d;
    return 0;
}
//output c=5 d=7

// 所以namespace其实是将全局变量的作用域给限定了。凡是在其中声明定义的都是限定在该作用域内。
// 其他人使用名字的时候不会访问到他们
// 但是如果使用了using namespace 则会将namespace的作用域扩大到using的作用域
// 例如以上代码中 A内using b 可以使得B内的变量的作用域从B中到A中 从而A可以使用b初始化A的变量
// 此时如果再using A 则会将A中的所有包括刚刚扩大过来的B中的名字的作用域扩大到当前作用域
// 因此namespace中其实就是限定这些变量、函数、命名空间的作用域。
// 而嵌套的只是意味着命名空间的名字本身的限定
// 如 namespace A{namespace B{}}意味着namespace B这个命名空间的名字只在A中可见 你如果在外面声明一个namespace也用B是不会同名的
// 但是如果你using了A 那么你再声明B你会发现重名