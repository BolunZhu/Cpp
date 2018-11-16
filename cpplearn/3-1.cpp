// class struct union 都可以用来声明和定义类
// struct union 都是c原用的保留字 class是c++中的
// 构造函数与类名同名 析构函数在类名前加～ 没有自己定义会提供缺省的 缺省的会将数据成员都变成0\
// 这两个函数都没有返回类型
// 类的函数成员可以在类中定义也可以在类外面定义
// 如果在类中定义将默认为内联函数 如果在类外定义则需要显式调用才会成为inline 此时需要加上类名::来表示定义的函数属于哪个类
// 使用. -> :: .* ->* 等调用函数成员都是显式调用 除了构造和析构函数以外其他函数只能通过显式调用获得
// 其中构造函数是唯一不能被显式调用的函数 原因很简单 能够显式调用都说明对象已经存在 那还怎么构造
// 对象的作用域一旦结束 则系统自动调用其析构函数
// 程序如果非正常退出 则不一定会调用析构函数 此时应该自己显示调用来避免内存不被回收
// return是正常退出 而exit 和abort则是非正常退出 其中exit退出会调用收工函数 而abort则是什么都不干
#include <iostream>
#include <string>

string x("global");
int main(int argc, char const *argv[])
{
    short error=0;
    string y("local");
    switch(error){
        case 0: return;
        case 1: y.~string();
                exit(1);
        default: x.~string();
                y.~string();
                abort();
    }
}
// 需要注意的是 常量对象在构造的值表达式计算完成后马上析构
