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
    
void main(void) {
    Timer0_Init(); // 初始化定时器
    while (1) {
        Display_Time(); // 刷新显示
    }
}