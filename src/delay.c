// 延时函数（简单的忙等待）
// 易造成CPU阻塞，不推荐使用
void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 120; j++);  // 简单延时循环，大约 1ms
    }
}