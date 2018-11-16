//  This 
// 类的普通函数成员其实都有一个隐含的参数this
// this的类型为 class_type * const
// 即 this是一个常量指针 这个指针指向一个该类类型的对象
// 因此this不能修改 但是 this指向的对象本身是可以被修改的
// 如果一个常量对象调用其普通成员函数 就会将对象与this绑定 此时会发现类型不一致
// 因为一个常量是不能绑定到一个指向普通类型的指针上的 否则常量将可能被修改
// 因此我们需要把this声明类型为 const class_type * const
// 方法是在函数声明的参数列表括号后面加上一个const来指定this指向一个常量对象
// int class_type1::fun(int para1,int para2,...) const;

//那么对于构造函数和析构函数 我们是否可以加const呢？
//直观想其实是不可以的 如果加const我们怎么修改他？不过这也不好说 还是写出来跑跑才知道结果
#include <string.h>
#include <iostream>

class STRING{
    char * str;
    public:
    STRING(char*);
    STRING()const {str=0;};
    ~STRING()const {if(str){std::cout<<"delete"<<str<<std::endl;delete str; str=0;}};
};
STRING::STRING(char * s)const {
    if(str=new char[strlen(s)+1]) strcpy(str,s);
}
int main(int argc, char const *argv[])
{
    return 0;
}
//可以发现 编译器会报error:这个类型修饰符不能修饰constructor/deconstructor
//那么const对象又是如何创建的呢？ 其实是先创建对象 然后使用对象的构造函数赋值 之后再赋予对象一个const的属性
