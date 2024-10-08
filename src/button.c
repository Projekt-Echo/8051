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
        // 再次检查按键状态，确保按键确实被按下
        if (Key == 0) {
            return 1; // 按键被按下
        }
    }
    return 0; // 按键未被按下
}

// 按键扫描函数
/*
Author: Shiro1sa
Date: 2024-10-04
Description: 按键扫描函数
*/
void Key_Scan(void) {
    static __bit lastKeyStartState = 1;
    static __bit lastKeyPauseState = 1;
    static __bit lastKeyResetState = 1;

    unsigned char currentKeyStartState = isKeyPressed(Key_Start);
    unsigned char currentKeyPauseState = isKeyPressed(Key_Pause);
    unsigned char currentKeyResetState = isKeyPressed(Key_Reset);

    if (currentKeyStartState && lastKeyStartState == 1) {
        running = 1; // 开始秒表
    }
    lastKeyStartState = currentKeyStartState;

    if (currentKeyPauseState && lastKeyPauseState == 1) {
        running = 0; // 暂停秒表
    }
    lastKeyPauseState = currentKeyPauseState;

    if (currentKeyResetState && lastKeyResetState == 1) {
        running = 0; // 暂停秒表
        milliseconds = 0;
        seconds = 0;
        minutes = 0; // 清零时间
    }
    lastKeyResetState = currentKeyResetState;
}