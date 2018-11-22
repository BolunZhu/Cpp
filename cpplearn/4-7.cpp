// 实例成员指针
// 有时候我们想要一个指针指向一个类中的某个成员 我们可以声明一个成员指针 然后对于某一个具体的类的对象 使用运算符.* 或者 ->* 来访问这个类中的这个对象
// 如下代码
#include <iostream>

class A{
    public:
    int a,b,c;
};

int main(int argc, char const *argv[])
{
    A  a;
    A * pa = &a;
    //声明并定义了一个变量 pAa 他是一个指针 指向属于A类的一个int型数据成员 初始化值为A中的a
    int (A:: * pAa) = &A::a;//这里其实pAa中存的就是偏移
    //访问的方式有两种
    a.*pAa = 1;
    pa->*pAa= 2;
    return 0;
}
