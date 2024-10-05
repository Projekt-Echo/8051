/*************************************
 * 
 *        89c52 sdcc blink demo
 * 
 * CPU: 89C52
 * FREQ: 11.0592MHz
 * PIN: P00
 * 
 * ***********************************
*/

#include <reg52.h>
#include <stdio.h>

// Main函数
void main(void) {
    Timer0_Init(); // 初始化定时器0
    while (1) {
        Key_Scan(); // 按键扫描
        Update_Display(); // 更新数码管显示
    }
}