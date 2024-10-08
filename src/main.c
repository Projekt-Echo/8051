/*************************************
 * 
 *        89c52 sdcc blink demo
 * 
 * CPU: 89C52
 * FREQ: 11.0592MHz //失准
 * PIN: P00
 * 
 * ***********************************
*/

#include <reg52.h>
#include <stdio.h>

// Main函数
void main(void) {
    Timer0_Init(); // 初始化定时器0
    while (1) { // 主循环
        if (flag_1ms) { // 10ms标志，计时。
            flag_1ms = 0;
            timer();
        }
        
        if (flag_button) { // 按键扫描标志，扫描按键
            flag_button = 0;
            Key_Scan();
        }
        Nixie_Buffer_Setter();
        Update_Display();
    }
}