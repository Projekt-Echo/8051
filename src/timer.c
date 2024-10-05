#include "reg52.h"

unsigned int milliseconds = 0;
unsigned char seconds = 0;
unsigned char minutes = 0;
unsigned char hours = 0;
unsigned char running = 0; // 秒表运行状态
unsigned int timer_count = 0; // 定义计数器变量

// 定时器初始化
/*
Author: Shiro1sa
Date: 2024-10-03
Description: 初始化Timer0
Parameters: None
*/
void Timer0_Init(void)		//1000微秒@11.0592MHz
{
	TMOD |= 0x01; // 设置定时器0为模式1（16位定时器模式）
    TH0 = 0x63;   // 设置定时器初值高字节
    TL0 = 0xC0;   // 设置定时器初值低字节
    ET0 = 1;      // 使能定时器0中断
    EA = 1;       // 使能总中断
    TR0 = 1;      // 启动定时器0
}

// 定时器0中断服务程序
void Timer0_ISR(void) __interrupt(1) {
    TL0 = 0x18;   // 重装定时器初值
    TH0 = 0xFC;   // 重装定时器初值

    timer_count++;
    if (timer_count >= 1000) { // 每1000次中断（约1秒）刷新一次显示
        timer_count = 0; // 重置计数器
        if (running ==1)
        {
           seconds++;
            if (seconds == 60) {
                seconds = 0;
                minutes++;
                if (minutes == 60) {
                    minutes = 0;
                    hours++;
                    if (hours == 24) {
                        hours = 0;
                    }
                }
            } 

        }
        
        
    }
}

