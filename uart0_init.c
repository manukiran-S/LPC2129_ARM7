#include<lpc21xx.h>
#include"header.h"

extern u8 buf,flag;

void uart0_handler(void) __irq
{
s32 temp = U0IIR;
temp&=0x0e;
if(temp==4){
buf=U0RBR;
flag=1;
}
VICVectAddr=0;
}

void config_vic_for_uart0(void){
U0IER=1;
VICIntSelect=0;
VICVectCntl1=6|(1<<5);
VICVectAddr1=(u32)uart0_handler;
VICIntEnable=(1<<6);
}