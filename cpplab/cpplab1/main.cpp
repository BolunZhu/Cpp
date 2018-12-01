//
//  main.cpp
//  U201614788-1
//
//  Created by 朱博抡 on 2018/10/11.
//  Copyright © 2018年 朱博抡. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "U201614788_1.h"
int main(int argc, const char * argv[]) {
    STACK s;
    s.pos=0;
    s.max=0;
    s.elems=NULL;
    STACK * p=&s;
    STACK * temp;
    int i=0;
    try {
        for (i=1; i<argc; i++) {
            switch (argv[i][1]) {
                case 'S':{
                    printf("S  ");
                    int size=atoi(argv[i+1]);
                    initSTACK(p, size);
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
                        push(p, temp);
                        i++;//-I with #n parameter
                    }
                    print(p);
                    break;
                }
                    
                case 'O':
                {
                    printf("O  ");
                    int poptimes=atoi(argv[i+1]);
                    int gab;
                    while (poptimes--) {
                        pop(p, gab);
                    }
                    
                    print(p);
                    i++;//-O with #1 parameter
                    break;}
                case 'C':
                {
                    printf("C  ");
                    temp = p;
                    p =(STACK *) malloc(sizeof(STACK));
                    initSTACK(p,*temp);
                    print(p);
                    destroySTACK(temp);
                    break;
                }
                case 'A':
                {
                    printf("A  ");
                    temp = p;
                    int size = atoi(argv[i+1]);
                    p =(STACK *) malloc(sizeof(STACK));
                    initSTACK(p,size);
                    p = assign(p,*temp);
                    print(p);
                    destroySTACK(temp);
                    i++;
                    break;
                }
                case 'N':
                {
                    printf("N  ");
                    printf("%d  ",howMany(p) );
                    break;
                }
                case 'G':
                {
                    printf("G  ");
                    printf("%d  ",getelem(p, atoi(argv[i+1]) ) );
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
