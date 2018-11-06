/*
const T * p 指向只读对象的指针变量可以用如下表达式赋值：
1指向对象的指针
2对象的地址
3返回对象地址的函数调用
其中对象可以为只读对象也可以为普通对象
然而
T * p 指向普通对象的指针变量使用上述表达式赋值的时候对象只能为普通对象。
本例解释&const T 不能赋给普通对象指针T * p的原因
*/
int main(void){
    int i,*p=&i,*h();//普通对象
    const int j=8,*q=&i,*f();//只读对象
    q=&j;
    q=p;
    q=h();
    q=f();
    //q 只读对象指针可以指向普通对象和只读对象
    //p 普通对象指针却只可以指向普通对象
    p=&i;
    p=h();
    //所以以下三种都是错的
    p=&j;
    p=q;
    p=f();
    return 0;
}

/*
指针和枚举
指针和枚举都属于简单类型
任何类型指针被分配的内存都是同样大小。
枚举类型会被分配和int一样大小的汇编语言类型。
枚举类型由enum给出，编译程序往往使用int实现枚举。
*/
enum WEEKDAY {sun,mon,tue,wed,thu,fri,sat};
WEEKDAY a=sun;
WEEKDAY b(sun);//c++提倡的初始化方法 体现其面向对象的思想
//枚举类型的定义等价于类型为int 元素为只读int
typedef int WEEKDAY;
const int sun=0,mon=1,tue=2,wed=3,thu=4,fri=5,sta=6;
//枚举元素的作用域仅限在枚举类型名里面， 在其他地方使用是不会被识别的
enum round{a=5,b,c=-3,d}//b = 6 c = -2
//也可以指定枚举元素的值 其他元素在前一个元素的值上加一

/*
挥发变量 volatile
这个变量主要用于使得编译时不使用寄存器优化，从而保证并行多线程能够及时获得正确的挥发变量的值
一个对象可以是挥发+只读的，const volatile 可以修饰同一个对象。
挥发变量为同步提供了协调手段。
*/
volatile int x;
x=3;
if(x==4) cout<<"x changed by other routines";
