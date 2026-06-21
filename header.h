#include<lpc21xx.h>

#define u32 unsigned int
#define u16 unsigned short int
#define u8 unsigned char
#define s32 int 

extern void config_vic_for_uart0(void);
extern void  uart0_handler(void) __irq;

extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx();
extern void uart0_string(char *ptr);

extern void delay_sec(unsigned int sec);
extern void delay_ms(unsigned int ms);