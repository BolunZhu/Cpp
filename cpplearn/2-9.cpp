//这是c++课本上的远古时期的代码 需要用turboc运行 这里就不说了
#include <dos.h>
#include <conio.h>
#include <stdio.h>
volatile int number=0;
void interrupt (*oldint1c)(...); 
static int freq[24]=
{32222, 262, 294, 330, 349,392, 440, 494,523, 587, 659, 698,
784, 880, 988, 1046, 1175, 1318, 1397, 1568, 1760, 1975, 0
};
static char snd[198]= {
8,6,0,1,8,2,1,0,5,4,0,1,8,2,0,2,9,2,10,2,8,8,0,3,12,4,0,1, 8,4,0,1,10,2,9,4,8,2,0,1,9,8,0,6,8,6,0,1,5,4,0,1,8,2,0,2, 9,2,10,2,8,8,0,3,12,4,0,1,8,4,0,1,13,2,12,4,0,1,12,2,0,1, 12,8,0,6,12,6,0,1,8,4,0,1,12,4,0,1,12,2,0,1,11,2,0,1,11,8, 0,6,11,5,0,1,8,4,0,1,10,2,0,1,9,4,0,1,8,2,0,1,9,2,10,8,0, 6,12,6,0,1,15,4,0,1,12,4,0,1,12,2,0,1,13,2,0,1,13,8,0,4, 12,2,0,1,11,3,0,1,10,4,0,1,10,2,0,1,8,2,0,1,9,5,0,1,9,2,0, 1,8,2,0,1,8,8,8,8,22,2
};

void interrupt int1c(...) {
    static int delays=0;
    enable( );
    (*oldint1c)( );
    if(delays){delays--;return ; }
    if(freq[snd[numbner]]==0){
        nosound();
        delays=180;
        number=0;
        return;
    }
    sound(freq[snd[number++]]);
    delays=snd[number++];
}

int main (void){
    printf("Asia Tornado\nPress any key to exit...\n");
    oldintlc=getvect(0x1c);
    setvect(0x1c,int1c);
    getch();
    while(freq[snd[number]]!=0){
        setvect(0x1c,oldint1c);
    }
    nosound();
}