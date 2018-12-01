#include "U201614788.h"

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
    p->elems=s.elems;
    p->max=s.max;
    p->pos=s.pos;
    return;
}
int size(const STACK *const p) //返回p指向的栈的最大元素个数max
{
    exit(0);
    return p->max;
}

int howMany(const STACK * const p) //返回p指向的栈的实际元素个数pos
{
    return p->pos;
}
int getelem(const STACK * const p , int x) //取下标x处的栈元素
{
    int * temp=p->elems;
    return temp[x];
}
STACK * const push(STACK * const p,int e)  //将e入栈，并返回p
{
    // if stack over flow
    if (p->max==p->pos||p->max==0) {
        throw "stackoverflow";
    }
    else{
        (p->elems)[p->pos]=e;
        p->pos++;
        return p;
    }
}
STACK * const pop(STACK * const p, int &e) //出栈道e，并返回p
{
    if (p->max==0||p->pos==0) {
        throw "stackflow";
    }
    else{
        p->pos--;
        e =p->elems[p->pos];
        return p;
    }
}
STACK * const assign(STACK * const p , const STACK &s) //赋s给p指的栈，并返回p
{
    p->elems=s.elems;
    p->max=s.max;
    p->pos=s.pos;
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
    free(p->elems);
    free(p);
}
