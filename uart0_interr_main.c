#include<lpc21xx.h>
#include"header.h"
#define LED (1<<17)

u8 buf,flag,c;

main(){
uart0_init(9600);
Lcd_init();
config_vic_for_uart0();
IODIR0|=LED;
uart0_string("uart0 interrupt is initialized\n");
c=0;
while(1){
IOSET0=LED;
delay_ms(100);
if(flag==1){
flag=0;
uart0_integer(c);
uart0_string("=c\n");
uart0_tx(buf);
Lcd_string(buf);
c++;
}
}
}
