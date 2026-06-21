#include<lpc21xx.h>
#include"header.h"

int main(){
int i;
Lcd_init();
while(1){
for(i=0;i<16;i++){
Lcd_cmd(0x80+i);
Lcd_string("Vector");
delay_ms(500);
Lcd_cmd(0x01);
}
}
}