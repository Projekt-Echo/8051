#include<reg52.h>

unsigned int timer_count = 0; // 定义计数器变量
unsigned int refresh_count = 0; // 定义刷新计数器变量
unsigned int button_count = 0; // 定义按键扫描计数器变量

bit flag_10ms = 0; // 10ms标志
bit flag_1ms = 0;  // 1ms标志
bit flag_button = 0; // 按键扫描标志

// 定时器0中断服务程序
/*
Author: Shiro1sa
Date: 2024-10-03
Modified: 2024-10-06
Description: 定时器0中断服务程序
*/
void Timer0_ISR(void) __interrupt(1) {
    TL0 = 0x06; // 重装定时器初值
    TH0 = 0xFC; // 重装定时器初值
    
    // 计时
    timer_count++;
    refresh_count++;
    button_count++;

    if (timer_count >= 10) { // 每10次中断（约10毫秒）设置一次标志
        timer_count = 0; // 重置计数器
        flag_10ms = 1;   // 设置10ms标志
    }
    
    if (refresh_count >= 1) { // 每1次中断（约1毫秒）设置一次标志
        refresh_count = 0; // 重置计数器
        flag_1ms = 1; // 设置1ms标志
    }
    
    if (button_count >= 10) { // 每10次中断（约10毫秒）设置一次标志
        button_count = 0; // 重置计数器
        flag_button = 1; // 设置按键扫描标志
    }
}