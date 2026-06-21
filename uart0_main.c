#include<lpc21xx.h>
#include"header.h"

int main () {
unsigned int temp;
uart0_init(9600);
while(1){
temp=uart0_rx();
uart0_tx('\n');
uart0_tx(temp);
}
}