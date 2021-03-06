// 友元函数 不是 定义他的类的函数成员 但是能够像类的函数成员一样访问
// 友元分为两类 1普通友元 2成员友元
// 普通 是指将普通函数定义为类的友元
// 成员 是指将一个类的函数成员定义为另一个类的友元
// 友元用friend声明 因为他不是函数成员 所以可以随意放在 public protected private里面没有关系
// 使用它可以提高访问效率 如下程序

class A{
    int a;
    public:
    int geta();
    int getb();
    ~A();
};

int A::geta(){
    return a;
}

class B{
    //...
    int a;
    friend A::~A();
    friend int A::getb(){
        //...
    }
};

// 如果类B使用类A的内容赋值 则要访问A中的a只能通过提供的接口函数
// 这样每次访问都要调用函数
// 通过将需要经常调用访问的B中的那个函数定义为A的友元可以提高效率
// 类A的成员函数f 可以在类B中声明并顺手定义了

// 构造函数和析构函数也可以是其他类的友元 因为他们没有返回类型 所以在定义友元的时候可以随便写返回类型

// 静态函数成员也可以是友元 类的任何函数都可以是其他类的 且可以同时是多个类的
// 如果一个类的所有函数成员都是另外一个类的友元 则可以在另外一个类中声明 friend A / friend class A 