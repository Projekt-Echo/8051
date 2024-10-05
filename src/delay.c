#include<reg52.h>
// 延时函数（简单的忙等待）
// 易造成CPU阻塞，不推荐使用
void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 120; j++);  // 简单延时循环，大约 1ms
    }
}

// 0.1ms延时函数
void delay_0_1ms(unsigned int n) {
    unsigned int i;
    for (i = 0; i < n; i++) {
        // 设置定时器1为模式1（16位定时器模式）
        TMOD |= 0x10; // 设置定时器1为模式1
        // 设置定时器初值
        TH1 = 0xFF; // 高字节
        TL1 = 0xF6; // 低字节
        // 启动定时器1
        TR1 = 1;
        // 等待定时器溢出
        while (!TF1);
        // 停止定时器1
        TR1 = 0;
        // 清除定时器溢出标志
        TF1 = 0;
    }
}