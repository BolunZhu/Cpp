// 静态函数成员
// 静态函数成员在访问权限、继承规则等方面和普通成员没有区别
// 唯一的不同是静态函数成员没有隐含的this参数
// 以下程序大致说明他的用法

class A{
    static int i, f();
    protected:
    static int g();
    public:
    static int m();

};

int A::i=0;
int A::f(){return A::i;}
int A::g(){return A::f();}
int A::m(){return A::g();}

int main(int argc, char const *argv[])
{
    // int i= A::f(); //错误 main无法访问私有成员
    // i = A::g(); // 错误 main无法访问保护成员
    int b = A::m(); // 这是可以得
    return 0;
}
//注意： 构造 析构 虚函数都有this参数 此外 如果参数表后出现了const volatile则也有this参数
//这些函数就不能被定义为静态函数成员
//union虽然不能定义静态数据成员 但是可以定义静态函数成员
//因为静态函数成员也是全局的 所以也不可以static 不可以再其他函数里面定义  不过可以在局部类中定义