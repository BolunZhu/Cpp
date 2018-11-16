#include <string.h>
#include <iostream>

class STRING{
    char * str;
    public:
    STRING(char*);
    STRING(){str=0;};
    ~STRING(){if(str){std::cout<<"delete"<<str<<std::endl;delete str; str=0;}};
};
STRING::STRING(char * s){
    if(str=new char[strlen(s)+1]) strcpy(str,s);
}
int main(int argc, char const *argv[])
{
    STRING *a=new STRING("abc");
    STRING *b=new STRING[10];
    STRING (*c)[20]= new STRING[10][20];
    STRING d("abcd"); 
    delete a; // 这里不能用delete []a 因为delete [] 和delete其实是被重载的 具体实现是不一样的
    delete []b;
    delete []c;
    return 0;
}
//正是因为delete和delete[]是不同的 因此在传入一个参数STRING*给一个函数的时候会出现问题
//函数本身其实是不知道传入的这个指针它指向的是一个对象还是对象数组 因此无法确定调用哪一个delete
//要避免这种情况 可以考虑在构造的时候使用new a[1]这种

//下面是一个奇技淫巧
STRING x("hello"), *p = &x;
x.~STRING();
new (&x) STRING("The world"); //死而复生法～
new (p) STRING("The world");
