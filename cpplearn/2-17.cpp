//C++ 函数种类很多 包括普通函数 友元函数 成员函数 构造函数 析构函数等
//所有类型的函数都可做 原型声明和内联声明。
//成员函数可以声明为静态成员函数、虚函数、纯虚函数
//函数原型的声明只需要说明参数类型即可，可以不说明参数名
//若函数的参数个数或者类型有所不同，则同名函数被视为重载函数
//注意 const 是不影响类型的 fun(int ) 和fun(const int)是同一个函数
//析构函数必须是无参函数 所以没有重载函数
//全局main函数也不能重载
//除此之外任何函数包括静态main函数(这个时候main不再是入口)都可以重载
//参数和类型决定重载，与返回类型无关。所以同参数不同返回类型是不能重载的

//C 是弱类型的语言 调用函数时实参可以与函数原型不同
//C++ 是强类型的语言 调用的时候必须一致
//参数 返回值 都可以声明为 只读或者挥发的
//const & volatile

//缺省参数  除了析构以外其他都可以
// ret_type fun(type1,...);
// 需要注意的是 缺省参数只能放到不缺省的参数的右边
// int fun(int x=1, int y, int z=1) 是错的 因为 x z 为缺省参数 y为非缺省参数 x不能在y的左边
// 缺省参数的定义既可以放在声明 又可以放在定义 
// 如果没有必要 最好不要使用...来省略参数 可以考虑函数的重载
// 在C++primer中 称这种在声明／定义中赋初值并且可在调用中省略的参数为默认实参
// 默认实参的右边都只能是默认实参 同一个默认实参只能被声明一次 但是不同的可以分开几次声明 
int f1(int a,int b,int c, int d);
int f1(int a,int b,int c, int d=1);
int f1(int a,int b,int c=2, int d);
//以上的多次声明是可以的 但是下面这一行是错误的
int f1(int a=5,int b,int c, int d);
//原因是b还没有声明默认实参 因此a作为默认实参不能在b的左边

#include <iostream>
using namespace std;
int i =1;
int j =2;
int f(int & x);
int main(int argc, char const *argv[])
{
    int z = 5;
    //int y =f(z+5);
    return 0;
}
int f(int & x=j){
    x=x+5;
    return x;
}
//目前出现的问题就是 C++Primer上告诉我们不能够传右值到普通引用参数上 而我们原来的书上又说会使用匿名变量初始化 所以导致了矛盾 这个矛盾我目前还没有得到答案 只知道编译器是不能编译通过以上代码的
//暂时我认为的答案是， 右值不能传递给普通引用参数 编译无法通过 不会使用书上说的方式创建一个匿名变量来初始化
//如果要将右值传入 则需要使用右值引用&& 它只接受右值而不接受左值

