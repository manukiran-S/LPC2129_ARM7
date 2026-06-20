#include<lpc21xx.h>
#include"header.h"
#define sw1 ((IOPIN0>>14)&1)
#define sw2 ((IOPIN0>>17)&1)
#define sw3 ((IOPIN0>>16)&1)

int main(){
int i;
IODIR0=0XFF;
IOCLR0=0XFF;
Lcd_init();
while(1){

if(sw1==1){
Lcd_integer(2468);
IOSET0=1<<0|1<<2|1<<4|1<<6|1<<8;
delay_ms(500);
IOCLR0=1<<0|1<<2|1<<4|1<<6|1<<8;
Lcd_cmd(0x01);
Lcd_integer(1357);
IOSET0=1<<1|1<<3|1<<5|1<<7;
delay_ms(500);
IOCLR0=1<<1|1<<3|1<<5|1<<7;
delay_ms(1000);
IOCLR0=0XFF;
}

if(sw2==1){
Lcd_cmd(0x01);
for(i=0;i<8;i++){
IOSET0=1<<i;
Lcd_integer(i);
delay_ms(500);
}
//Lcd_cmd(0x01);
for(i=i-1;i>=0;i--){
Lcd_cmd(0x80+i);
Lcd_data(' ');
IOCLR0=1<<i;
delay_ms(200);
}
}
Lcd_cmd(0x01);
if(sw3==1){
for(i=0;i<256;i++){
Lcd_cmd(0x80);
Lcd_integer(i);
IOSET0=i;
delay_ms(200);
IOCLR0=i;
}
}

}
}