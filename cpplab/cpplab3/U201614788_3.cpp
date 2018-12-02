#include <iostream>
#include <string>
#include "U201614788_3.h"

//初始化栈：最多m个元素
STACK::STACK(int m): elems(new int[m]) , max(m) , pos(0)
{
}		
//用栈s拷贝初始化栈
STACK::STACK(const STACK&s): elems(new int[s.max]) , max(s.max) ,pos(s.pos)
{
  for(int i = 0; i < pos; i++)
    {
        elems[i]=s.elems[i];
    }
} 	
//返回栈的最大元素个数max		
int  STACK::size ( ) const
{
    return max;
}		
//返回栈的实际元素个数pos	
STACK::operator int ( ) const			
{
    return pos;
}
int STACK::operator[ ] (int x) const	//取下标x处的栈元素
{
    if (x>=pos) {
        throw("getelem overflow! cannot get elem out of range");
    }
    
    return elems[x];
}
STACK& STACK::operator<<(int e) 	//将e入栈,并返回栈
{
    if (pos==max) {
        throw("pos==max ! cannot add elem to stack anymore");
    }
    elems[pos]=e;
    pos++;
    return *this;
}
STACK& STACK::operator>>(int &e)	//出栈到e,并返回栈
{
    if (pos==0) {
        throw("pos==0 ! cannot pop elemt from stack!");
    }
    pos--;
    e=elems[pos];
    return *this;
}
STACK& STACK::operator=(const STACK&s) //赋s给栈,并返回被赋值的栈
{
    this->~STACK();
    new(this) STACK(s);
    return *this;
}
void STACK::print( ) const			//打印栈
{
    for(int i = 0; i < pos; i++)
        {
            printf("%d  ",elems[i]);
        }
}
STACK::~STACK( )					//销毁栈
{
    delete[](this->elems);
}