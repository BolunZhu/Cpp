//函数的参数和局部非静态变量都在栈上分配空间
//因此引用栈的变量将导致应用程序的行为不确定。
//window中不同的程序会共用栈
#include <iostream> 
using namespace std;
int &f(int i)
{,
 int &j=i;
return j; 
}
int &g( ) 
{
int k=6,&m=k;
return m; 
}
int main(void){
    //引用需要每个标识符前面都加一个& 因此在这里x1为int变量 而非引用
    int &x=f(10),x1=x;
    int &y=g(),y1=y;
    cout<<"x="<<x<<"x1="<<x1<<endl;
    cout<<"y="<<y<<"y1="<<y1<<endl;
    //x!=x1 y!=y1 bcz local value has changed
    return 0;
}
