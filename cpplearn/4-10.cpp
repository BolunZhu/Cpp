// mutable 1只能修饰类的普通数据成员 而volatile可以修饰类的任何成员、变量、函数等 2mutable修饰的普通数据成员的值不会自发更改。
// mutable修饰的数据成员为机动数据成员 此时不能用const volatile 以及 static修饰
// mutable修饰的机动数据成员可以被参数表后带const的函数成员修改

class A{
    int a;
    mutable int b;//机动数据成员 
    public:
    int get(int x) const;
};

int A::get(int x)const{
    b=b+x;
    return a; 
}
// a 不可以修改 b可以被修改