// 访问引用变量本质上就是访问被引用的对象。
// 一下程序中变量z的赋值以及返回普通引用的函数调用f(r)都是左值表达式。

int i ; //全局变量 缺省初始化为0
const int & j =2; //只读引用变量（需要右值）引用常量
int & x = ++ i;   //OK ++i=lvalue &x=i
int &y = i =0;  //ok i=0 = lvalue &y=i
int &z = y = 3; // OK y=3 = lvalue &z=i

int &f(int &v){
    return v+=5; //v=v+5 = lvalue return v
}

int main(int argc, char const *argv[])
{
    int i=0;
    const int k=10,&j=k; //ok k is rvalue
    const int &m=2; //得到一个匿名只读变量值为2
    const int &n=i; //使用左值进行初始化生成一个匿名只读变量
    int &x = i++; //编译器会警告 引用了一个匿名变量 使用i进行初始化
    int &y=++++i; // OK ++++i = lvalue y ref i
    int &z=i=4; //OK
    int &r=z=8; //OK
    i=3;
    x=6; //你会发现x和其他人不一样，i的值变化不会导致x变化 因为他引用的是一个匿名的变量而不是i
    r=12;
    ++y=10;//i from 12 to 13 to 10
    (z=10)=15;  
    (f(r)=1)=2; //ok
    return 0;
}
