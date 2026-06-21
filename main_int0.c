#include"header.h"

u32 count1;
main(){
IODIR0=1<<17;
uart0_init(9600);
config_vic_for_eint0();
while(1){
count1++;
}

}
