#include<lpc21xx.h>
#include"header.h"

volatile u32 count2;
void EINT0_Handler(void) __irq
{
uart0_string("EINT0 WORKING\n");
count2++;
if(count2%2==0){
IOCLR0=1<<17;
}
else{
IOSET0=1<<17;
}
EXTINT=1;
VICVectAddr=0;
}

void config_vic_for_eint0(void){
PINSEL1|=1;//P0.16->EINT0
EXTMODE=1;//EINT0->EDGE TYPE
EXTPOLAR=0;//EINTO->ACTIVE LOW
EXTINT = 1;
VICVectAddr0 = (u32)EINT0_Handler;
VICVectCntl0 = (1<<5)|14;
VICIntSelect=0;//all interrups are IRQ
VICIntEnable|=(1<<14);//enable EINT0
}