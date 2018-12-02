//
//  main.cpp
//  U201614788-4
//
//  Created by 朱博抡
//  Copyright © 2018年 朱博抡. All rights reserved.
//

#include <iostream>
#include <string>
#include "U201614788_4.h"
const int M=3;//male
const int F=5;//female
const int m=3;// man pos
const int f=5;// woman pos

//helper function
void init(QUEUE & m_q,QUEUE & f_q){
    for(int i =1 ; i <= M ; i++){
        m_q<<i;
    }
    for(int i=1; i <= F; i++){
        f_q<<i;
    }
}

int main(int argc, const char * argv[]) {
    QUEUE *p;
    QUEUE * temp;//store stack to be delete
    int i=0;
    
    if (argc>1) {
            try {
            for (i=1; i<argc; i++) {
                switch (argv[i][1]) {
                    case 'S':{
                        printf("S  ");
                        int size=atoi(argv[i+1]);
                        p=new QUEUE(size);
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
                            (*p)<<(temp);
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
                            (*p)>>(gab);
                        }
                        
                        p->print();
                        i++;//-O with #1 parameter
                        break;}
                    case 'C':
                    {
                        printf("C  ");
                        temp = p;
                        p=new QUEUE(*p);
                        p->print();
                        delete temp;
                        break;
                    }
                    case 'A':
                    {
                        printf("A  ");
                        temp = p;
                        int size=atoi(argv[i+1]);
                        p=new QUEUE(size);
                        *p=*temp;
                        p->print();
                        delete temp;
                        i++;
                        break;
                    }
                    case 'N':
                    {
                        printf("N  ");
                        printf("%d  ",int(*p) );
                        break;
                    }
                    case 'G':
                    {
                        printf("G  ");
                        printf("%d  ",(*p)[atoi(argv[i+1])] );
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
    }
    else {//solution
        QUEUE m_q = QUEUE(M);
        QUEUE f_q = QUEUE(F);
        init(m_q,f_q);
        int round = 0;
        int now_m , now_f;
        do{
            m_q>>now_m;
            f_q>>now_f;
            m_q<<now_m;
            f_q<<now_f;
            round++;
        }while(!(now_f==f && now_m==m));
        printf("%d\n",round);
    }
    
   
    return 0;
}