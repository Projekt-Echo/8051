#include "reg52.h"

unsigned int milliseconds = 0;
unsigned char seconds = 0;
unsigned char minutes = 0;
unsigned char running = 0; // 秒表初始运行状态


// 定时器初始化函数 1000微秒@11.0592MHz
/*
Author: Shiro1sa
Date: 2024-10-03
Description: 初始化Timer0
Parameters: None
*/
void Timer0_Init(void)		//1000微秒@11.0592MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x06;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0=1;
	EA=1;
	PT0=0;
}


// Timer函数
/*
Author: Shiro1sa
Date: 2024-10-05
Modified: 2024-10-06
Description: 秒表计时函数
*/
void timer() {
    if (running) {
        milliseconds++;
        if (milliseconds >= 100) {
            milliseconds = 0;
            seconds++;
            if (seconds >= 60) {
                seconds = 0;
                minutes++;
                if (minutes >= 60) {
                    minutes = 0;
                }
            }
        }
    }
}


