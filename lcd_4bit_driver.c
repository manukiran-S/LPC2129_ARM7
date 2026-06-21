#include<lpc21xx.h>
#include"header.h"

void Lcd_data(unsigned char data){
unsigned int temp;
IOCLR1=0xFE<<16;
temp=((data&0xF0)<<16);
IOSET1=temp;
IOSET1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOSET1=1<<19;

IOCLR1=0xFE<<16;
temp=((data&0x0F)<<20);
IOSET1=temp;
IOSET1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOSET1=1<<19;
}

void Lcd_cmd(unsigned char cmd){
unsigned int temp;
IOCLR1=0xFE<<16;
temp=((cmd&0xF0)<<16);
IOSET1=temp;
IOCLR1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOSET1=1<<19;

IOCLR1=0xFE<<16;
temp=((cmd&0x0F)<<20);
IOSET1=temp;
IOCLR1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOSET1=1<<19;
}

void Lcd_init(){
IODIR1=0xFE<<16;
PINSEL2=0x0;
Lcd_cmd(0x02);
Lcd_cmd(0x28);
Lcd_cmd(0x0e);
Lcd_cmd(0x01);
}

void Lcd_integer(int num){

int a[10],i=0;

if(num==0)
Lcd_data('0');

if(num<0){
num=-num;
Lcd_data('-');
}

while(num>0){
a[i]=num%10+48;
num=num/10;
i++;
}
for(i=i-1;i>=0;i--){
Lcd_data(a[i]);
}


}

void Lcd_string(char *ptr){

while(*ptr!=0){
Lcd_data(*ptr);
ptr++;
}

}

void Lcd_float(float flo) {
int num;

if(flo==0)
Lcd_string("0.000000");

if(flo<0){
flo=-flo;
Lcd_data('-');
}
num=flo;
Lcd_integer(num);
num=flo-num*100000;
Lcd_integer(num);

}
