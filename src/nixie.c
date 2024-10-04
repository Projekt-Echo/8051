#include "reg52.h"

// 数码管显示函数
/*
Author: Shiro1sa
Date: 2024-10-02
Description: 数码管显示函数
Parameters: 
    position: 数码管位置，7-0(从左到右)
    number: 数码管显示的数字，0-9, 10为减号
*/
void display(int position, int number) {
    // 清除数码管位置相关的引脚 - 消影的一部分
    P2 &= 0xE3; // 清除第2、3、4位
    
    // 位选
    // 使用位操作优化数码管位置设置
    P2 = (P2 & 0xE3) | ((position & 0x07) << 2);

    // 段选
    // 显示数字
    switch (number) {
        case 0: P0 = 0x3F; break; // 显示0
        case 1: P0 = 0x06; break; // 显示1
        case 2: P0 = 0x5B; break; // 显示2
        case 3: P0 = 0x4F; break; // 显示3
        case 4: P0 = 0x66; break; // 显示4
        case 5: P0 = 0x6D; break; // 显示5 
        case 6: P0 = 0x7D; break; // 显示6 
        case 7: P0 = 0x07; break; // 显示7 
        case 8: P0 = 0x7F; break; // 显示8 
        case 9: P0 = 0x6F; break; // 显示9 
        case 10: P0 = 0x40; break; // 显示- 
        default: P0 = 0x00; break; // 默认清除显示 
    }

    // 消影
    delay(32);
    // 清除数码管位置相关的引脚 - 消影的一部分
    P2 &= 0xE3; // 清除第2、3、4位 
}

void Display_Time(void) {
    display(7, hours / 10);
    display(6, hours % 10);
    display(5, 10); // 显示减号
    display(4, minutes / 10);
    display(3, minutes % 10);
    display(2, 10); // 显示减号
    display(1, seconds / 10);
    display(0, seconds % 10);
}