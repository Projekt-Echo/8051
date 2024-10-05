#include <reg52.h>
// 定义外部函数接口

extern void delay(unsigned int ms);
extern void Timer0_Init(void);
extern void Timer0_ISR(void) __interrupt(1);
extern void Key_Scan(void);
extern void Update_Display(void);

// 定义按键
__sbit __at (0xB1) Key_Start; // P3.1 引脚
__sbit __at (0xB0) Key_Pause; // P3.0 引脚
__sbit __at (0xB2) Key_Reset; // P3.2 引脚
__sbit __at (0xB3) Key4; // P3.3 引脚

extern unsigned int milliseconds;
extern unsigned char seconds;
extern unsigned char minutes;
extern unsigned char hours;
extern unsigned char running;


// Debug
extern void UART_Init(void);
extern void UART_Send(unsigned char d);
extern unsigned char UART_Receive(void);