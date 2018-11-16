// 访问权限
// 访问权限分为 private protected public
// private 只有自己和友元函数能够访问
// protected = private + 派生后代
// public = anyone

// class 默认的权限和继承为private
// struct  则为public
// class struct union 都可以有构造、析构和其他成员函数

//构造函数和析构函数通常声明为public 不过也可以声明为其他的权限并无大碍

//C++ 和 C 的强制类型转换提供了无限制的类型转换能力，因此通过类型转换便可以获得相应的访问权限
//比如一个类中的数据成员本来是private 但是通过将其强制转换成一个新的类型 其数据成员是public类型 则可以访问到原来的私有数据成员

//局部类就是在函数体内的类。 局部类有些编译器是不允许拥有函数成员的

//位段
//class struct union 都可以定义位段 不过其类型只能为char short int 不能为 long float 数组等

//new and delete
// malloc and free 不会调用构造和析构函数 而new和delete会
// free 和 delete 都会将指针 p 指向的对象释放 但是delete会先调用析构函数
// new可以申请对象数组 这个时候需要 new Type[] 也可以申请高维的new Type[][][]等
// 申请的对象数组最顶层的数量可以是一个任意整型表达式 ，而下面的则必须是常量整型
// delete也可以将对象数组给释放 这个时候需要 delete []p释放p指向的对象数组 无论数组有多少维
#include <iostream>
using namespace std;
class A{
    int i;
    public:
    A(int x){i=x;}
    A(){i=0;}
};
int main(int argc, char const *argv[])
{
    int x(3);
    cout<<"input x";
    cin>>x;
    int *m=new int(5) ; // *m = int 5
    int *n=new int[5] ; // *m = int tmp[5]
    int (*p)[10]= new int [x][10]; // *p =  tmp[x] tmp[i]=int a[10]
    int (*q)[10][20]= new int [x][10][20];  //其实就是说 p指向的对象本身可以是一个数组 这个数组的大小可以不确定 但是这个数组的元素的类型必须是确定的
    A *r = new A(5);
    A *s = new A[5];
    A (*a)[10] = new A[x][10];
    A (*b)[10][20] = new A[x][10][20];
    
    return 0;
}
