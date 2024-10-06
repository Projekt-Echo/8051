#include "reg52.h"

unsigned int milliseconds = 0;
unsigned char seconds = 0;
unsigned char minutes = 0;
unsigned char running = 0; // 秒表初始运行状态


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
    TH0 = 0xFC;   // 设置定时器初值高字节
    TL0 = 0x06;   // 设置定时器初值低字节
    ET0 = 1;      // 使能定时器0中断
    EA = 1;       // 使能总中断
    TR0 = 1;      // 启动定时器0
}


void timer() {
    if (running) {
        milliseconds++;
        if (milliseconds >= 100) {
            milliseconds = 0;
            seconds++;
        }
        if (seconds >= 60) {
            seconds = 0;
            minutes++;
        }
        if (minutes >= 60) {
            minutes = 0;
        }
    }
}


