#include <iostream>
#include <string>
class STACK{
    int  *const  elems;	//申请内存用于存放栈的元素
    const  int   max;	//栈能存放的最大元素个数
    int   pos;			//栈实际已有元素个数，栈空时pos=0;
public:
STACK(int m);		//初始化栈：最多m个元素
STACK(const STACK&s); //用栈s拷贝初始化栈
int  size ( ) const;		//返回栈的最大元素个数max
int  howMany ( ) const;	//返回栈的实际元素个数pos
int  getelem (int x) const;	//取下标x处的栈元素
STACK& push(int e); 	//将e入栈,并返回栈
STACK& pop(int &e); 	//出栈到e,并返回栈
STACK& assign(const STACK&s); //赋s给栈,并返回被赋值的栈
void print( ) const;		//打印栈
~STACK( );				//销毁栈
};
int main(int argc, const char * argv[]) {
    STACK *p;
    int i=0;
    try {
        for (i=1; i<argc; i++) {
            switch (argv[i][1]) {
                case 'S':{
                    printf("S  ");
                    int size=atoi(argv[i+1]);
                    p=new STACK(size);
                    printf("%d  ",size);
                    i=i+1;//-s with #1 parameter
                    break;
                }
                    
                case 'I':
                {
                    printf("I  ");
                    int temp;
                    while ((i+1)<argc && argv[i+1][0]!='-') {
                        temp=atoi(argv[i+1]);
                        p->push(temp);
                        i++;//-I with #n parameter
                    }
                    p->print();
                    break;
                }
                    
                case 'O':
                {
                    printf("O  ");
                    int poptimes=atoi(argv[i+1]);
                    int gab;
                    while (poptimes--) {
                        p->pop(gab);
                    }
                    
                    p->print();
                    i++;//-O with #1 parameter
                    break;}
                case 'C':
                {
                    printf("C  ");
                    p->print();
                    break;
                }
                case 'A':
                {
                    printf("A  ");
                    p->print();
                    i++;
                    break;
                }
                case 'N':
                {
                    printf("N  ");
                    printf("%d  ",p->howMany() );
                    break;
                }
                case 'G':
                {
                    printf("G  ");
                    printf("%d  ",p->getelem(atoi(argv[i+1]) ) );
                    i++;
                    break;
                }
                default:
                {printf("error input\n");
                    break;}
            }
        }
        
    } catch (char const * e) {
        printf("E");
        return 1;
    }
    return 0;
}

STACK::STACK(int n): elems(new int[n]) , max(n) , pos(0)
{
    
    // for(int i = 0; i < n; i++)
    // {
    //     elems[i]=0;
    // }
    
}
STACK::~STACK(){
    delete[](this->elems);
}

STACK::STACK(const STACK &s ) : elems(s.elems) , max(s.max) ,pos(s.pos) //用栈s拷贝初始化栈
{
}
int  STACK::size ( ) const		//返回栈的最大元素个数max
{
    return this->max;
}

int STACK::howMany ( ) const	//返回栈的实际元素个数pos
{
    return this->pos;
}

int  STACK::getelem (int x) const	//取下标x处的栈元素
{
    return (this->elems)[x];
}
STACK& STACK::push(int e) 	//将e入栈,并返回栈
{
    
    if (this->pos==this->max) {
        throw("pos==max ! cannot add elem to stack anymore");
    }
    this->elems[pos]=e;
    pos++;
    return *this;
} 
STACK& STACK::pop(int &e) 	//出栈到e,并返回栈
{
    
    if (this->pos==0) {
        throw("pos==0 ! cannot pop elemt from stack!");
    }
    this->pos--;
    e=this->elems[this->pos];
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
    
    for(int i = 0; i < this->pos; i++)
    {
        printf("%d  ",this->elems[i]);
    }
    
}