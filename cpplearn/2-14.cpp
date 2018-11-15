//通过使函数返回函数的局部变量的引用的左值可以改变函数内部的局部变量的值。、

#include <stdio.h>

char * & weekday(int & day)
{
    static char * week[7]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    return week[day++];
}

int main(int argc, char const *argv[])
{
    int day=0;
    printf(weekday(day)); //OK print SUN  .day=1
    weekday(day)=  "Moo";   //OK week[1] = "Mon"
    //! Notice 只是将week[1]指向了新的moo 原来的mon没有被修改
    weekday(day)[1]='h'; //Tue->The 这次的确修改了里面的值
    printf(weekday(day+2)); //OK day+2 = rvalue So temp = day+2 weekday(temp) 
    //Since weekday(tmp=3) So day is still 3 
    return 0;
}
