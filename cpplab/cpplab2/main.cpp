#include <iostream>
#include <string>
#include "lab2.cpp"
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