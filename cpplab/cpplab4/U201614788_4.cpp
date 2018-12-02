#include <iostream>
#include <string>
#include "U201614788_4.h"

//初始化栈：最多m个元素
STACK::STACK(int m): elems(new int[m]) , max(m) , pos(0)
{
    if(!elems) throw("new elems error");
}		
//用栈s拷贝初始化栈
STACK::STACK(const STACK&s): elems(new int[s.max]) , max(s.max) ,pos(s.pos)
{
    if(!elems) throw("new elems error");
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
    if(elems) delete[](this->elems);
    
}

QUEUE::QUEUE(int m):STACK(m),s2(m){}
QUEUE::QUEUE(const QUEUE&s):STACK(s),s2(s.s2){}
QUEUE::operator int() const{
    return STACK::operator int()+int(s2);
}
int QUEUE::full()const{
    
    if (s2&&STACK::size()==STACK::operator int()) {
        return 1;
    }
    return 0;
}
int QUEUE::operator [](int x)const{
    
    if (x<s2) {
        return s2[s2-1-x];
    }
    else {
        return STACK::operator [](x-s2);
    }
    
}

QUEUE& QUEUE::operator<<(int e){
    if(full()){
        throw("Full when in queue!");
    }
    
    if (STACK::size()==STACK::operator int()) {
        /* in_queue full */
        // let in_queue into out_queue
        int temp=0;
        while(STACK::operator int()){
            STACK::operator>>(temp);
            s2<<(temp);
        }
    }
    STACK::operator<<(e);
    return *this;
}

QUEUE& QUEUE::operator>>(int &e){
    if(!s2){
        
        if (!STACK::operator int()) {
            //stack downflow
            throw("Cannot pop element from queue!");
        }
        else {
            // let in_queue into out_queue
            int temp=0;
            while(STACK::operator int()){
                STACK::operator>>(temp);
                s2<<(temp);
            }
        }
        
    }
    s2>>(e);
    return *this;
}
QUEUE::~QUEUE(){}
QUEUE& QUEUE::operator=(const QUEUE&s){
    this->~QUEUE();
    new (this) QUEUE(s);
    return *this;
}
void QUEUE::print()const{
    
    for(int i = 0; i < this->operator int(); i++)
    {
        printf("%d  ",(*this)[i]);
    }
}