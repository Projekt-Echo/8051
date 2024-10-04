#include "reg52.h"

// 按键检测函数
/*
Author: Shiro1sa
Date: 2024-10-03
Description: 按键检测函数
Parameters: 
    Key: 按键的引脚
*/
unsigned char isKeyPressed(__sbit Key) {
    // 按键按下时，Key 引脚为低电平
    if (Key == 0) {
        // 消抖延时
        delay(20);
        // 再次检查按键状态，确保按键确实被按下
        if (Key == 0) {
            return 1; // 按键被按下
        }
    }
    return 0; // 按键未被按下
}