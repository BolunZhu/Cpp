//对于有缺省参数时的函数重载
//在调用函数的时候会将实参与函数参数进行匹配，只要实参都满足，那么这些函数就满足
//因此如下代码中两个函数都会满足重载的条件
void f(int a,char * msg = "aa");
void f(int a,int b = 5);
int i =10
f(i);//f将会出错 因为无法确定该重载哪个函数
