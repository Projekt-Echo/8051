#include<reg52.h>

bit refresh_count = 0; // 定义刷新计数器变量
bit button_count = 0; // 定义按键扫描计数器变量

bit flag_10ms = 0; // 1ms标志
bit button_flag = 0; // 按键扫描标志

// 定时器0中断服务程序
/*
Author: Shiro1sa
Date: 2024-10-03
Modified: 2024-10-06
Description: 定时器0中断服务程序
*/
void Timer0_ISR(void) __interrupt(1) {
    TL0 = 0x00; // 重装定时器初值
    TH0 = 0xDC; // 重装定时器初值
    
    // 计时
    refresh_count++;
    button_count++;
    
    if (refresh_count >= 1) { // 每1次中断（约10毫秒）设置一次标志
        refresh_count = 0; // 重置计数器
        flag_10ms = 1; // 设置10ms标志
    }
    
    if (button_count >= 1) { // 每1次中断（约10毫秒）设置一次标志
        button_count = 0; // 重置计数器
        button_flag = 1; // 设置按键扫描标志
    }
}

