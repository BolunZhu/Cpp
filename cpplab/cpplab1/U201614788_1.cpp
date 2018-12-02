#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "U201614788_1.h"

void initSTACK(STACK * const p ,int m)//初始化p指向的栈：最多m个元素
{
    int * temp = (int *)malloc(sizeof(int)*m);
    p->elems=temp;
    p->max=m;
    p->pos=0;
    return;
}
void initSTACK(STACK *const p,const STACK &s)//用栈s初始化p指向的栈
{
    p->elems=(int *) malloc(sizeof(int)* (s.max));
    p->max=s.max;
    p->pos=s.pos;
    
    for(int i = 0; i < p->pos; i++)
    {
        p->elems[i]=s.elems[i];
    }
    
    return;
}
int size(const STACK *const p) //返回p指向的栈的最大元素个数max
{
    return p->max;
}

int howMany(const STACK * const p) //返回p指向的栈的实际元素个数pos
{
    return p->pos;
}
int getelem(const STACK * const p , int x) //取下标x处的栈元素
{
    if (x>=p->pos) {
        throw("getelem overflow! cannot get elem out of range");
    }
    return p->elems[x];
}
STACK * const push(STACK * const p,int e)  //将e入栈，并返回p
{
    if (p->pos==p->max) {
        throw("pos==max ! cannot add elem to stack anymore");
    }
    p->elems[p->pos]=e;
    p->pos++;
    return p;
}
STACK * const pop(STACK * const p, int &e) //出栈道e，并返回p
{
    if (p->pos==0) {
        throw("pos==0 ! cannot pop elemt from stack!");
    }
    p->pos--;
    e=p->elems[p->pos];
    return p;
}
STACK * const assign(STACK * const p , const STACK &s) //赋s给p指的栈，并返回p
{
    int * temp = p->elems;
    free(temp);
    initSTACK(p,s);
    return p;
}
void print(const STACK * const p)  //打印p指向的栈
{
    int i;
    for (i=0; i<p->pos; i++) {
        printf("%d  ",p->elems[i]);
    }
}
void destroySTACK(STACK*const p)   //销毁p指向的栈
{
    
    if (p) {  
        if (p->elems) {
           free(p->elems);
        }
    free(p);
    }
}
