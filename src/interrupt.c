#include<reg52.h>


unsigned int timer_count = 0; // 定义计数器变量
unsigned int refresh_count = 0; // 定义刷新计数器变量
unsigned int button_count = 0; // 定义按键扫描计数器变量
// 定时器0中断服务程序
/*
Author: Shiro1sa
Date: 2024-10-03
Modified: 2024-10-06
Description: 定时器0中断服务程序
*/
void Timer0_ISR(void) __interrupt(1) {
    TL0 = 0x06;   // 重装定时器初值
    TH0 = 0xFC;   // 重装定时器初值

    // 计时
    timer_count++;
    if (timer_count >= 10) { // 每10次中断（约10毫秒）刷新一次显示
        timer_count = 0; // 重置计数器
        timer();
    }
    
    // 刷新显示
    refresh_count++;
    if (refresh_count >= 1) { // 每1次中断（约1毫秒）刷新一次显示
        refresh_count = 0; // 重置计数器
        Nixie_Buffer_Setter();
        Update_Display();
    }
    
    // 按键扫描
    button_count++;
    if (button_count >= 5) { // 每5次中断（约5毫秒）执行一次按键判断
        button_count = 0; // 重置计数器
        Key_Scan();
    }
}