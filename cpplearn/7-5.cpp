
#include <iostream>
class A{
    int i;
    public:
    virtual void f1()=0;
    void f2(){
        printf("f2");
    }
};

class B:public A{
    // void A::f1();
    // void f1();
};

void A::f1(){
    printf("f1");
}
// void B::f1(){
//     printf("hhh\n");
// }
int main(int argc, char const *argv[])
{
    // B  b; 
    B b;
    A * p;
    printf("begin");
    // p->f2();
    printf("%p",p);
    p->A::f1();
    printf("aaaa");
    return 0;
}