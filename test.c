#include<lpc21xx.h>
#include"header.h"

int main(){
int i;
IODIR0=0XFF;
IOCLR0=0XFF;

while(1){
for(i=0;i<255;i++){

IOSET0=i;
delay_ms(100);
IOCLR0=0xFF;


}

}
}
