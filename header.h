#include<lpc21xx.h>

#define u32 unsigned int
#define u16 unsigned short int
#define u8 unsigned char

extern void config_vic_for_eint0(void);
extern void EINT0_Handler(void) __irq;

extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx();
extern void uart0_string(char *ptr);
