#include <iostream>
#include <string>
#include "U201614788_2.hpp"


STACK::STACK(int n=1): elems(new int[n]) , max(n) , pos(0)
{
    
}
STACK::~STACK(){
    delete[](this->elems);
}

STACK::STACK(const STACK &s ) : elems(new int[s.max]) , max(s.max) ,pos(s.pos) //用栈s拷贝初始化栈
{
    
    for(int i = 0; i < pos; i++)
    {
        elems[i]=s.elems[i];
    }
    
}
int  STACK::size ( ) const		//返回栈的最大元素个数max
{
    return max;
}

int STACK::howMany ( ) const	//返回栈的实际元素个数pos
{
    return pos;
}

int  STACK::getelem (int x) const	//取下标x处的栈元素
{
    
    if (x>=pos) {
        throw("getelem overflow! cannot get elem out of range");
    }
    
    return elems[x];
}
STACK& STACK::push(int e) 	//将e入栈,并返回栈
{
    
    if (pos==max) {
        throw("pos==max ! cannot add elem to stack anymore");
    }
    elems[pos]=e;
    pos++;
    return *this;
} 
STACK& STACK::pop(int &e) 	//出栈到e,并返回栈
{
    
    if (pos==0) {
        throw("pos==0 ! cannot pop elemt from stack!");
    }
    pos--;
    e=elems[pos];
    return *this;
}

STACK& STACK::assign(const STACK&s) //赋s给栈,并返回被赋值的栈
{
    this->~STACK();
    new(this) STACK(s);
    return *this;
}

void STACK::print( ) const		//打印栈
{
    
    for(int i = 0; i < pos; i++)
    {
        printf("%d  ",elems[i]);
    }
    
}