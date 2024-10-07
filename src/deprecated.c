// 该文件下，所有内容均为已经废弃的函数，不再使用，仅作为参考
#include <reg52.h>
// 延时函数
// Deprecated: 使用delay函数代替
// Replace with delay function(Defined by regx52.h)
/*
Author: Shiro1sa
Date: 2024-10-02
Description: 延时函数
Parameters: None
Note :Generate by STC-ISP Ver6.94L
*/
void delayDeprecated(void)	//@12.000MHz
{
	unsigned char i, j;

	i = 4;
	j = 185;
	do
	{
		while (--j);
	} while (--i);
}


// 数码管显示函数
// Deprecated: 使用display函数代替
// Replace with display function(Defined by nixie.c)
/*
Author: Shiro1sa
Date: 2024-10-02
Description: 数码管显示函数
Parameters: 
    position: 数码管位置，7-0(从左到右)
    number: 数码管显示的数字，0-9, 10为减号
*/
void displayDeprecated(int position, int number) {
    // 清除数码管位置相关的引脚
    P2 &= 0xE3; // 清除第2、3、4位
    
    // 设置数码管位置
    // 原始代码如图
    switch (position) {
        case 0:
            P2 &= ~(1 << 2); // 清除第2位
            P2 &= ~(1 << 3); // 清除第3位
            P2 &= ~(1 << 4); // 清除第4位
            break;
        case 1:
            P2 |= (1 << 2);  // 设置第2位
            P2 &= ~(1 << 3); // 清除第3位
            P2 &= ~(1 << 4); // 清除第4位
            break;
        case 2:
            P2 &= ~(1 << 2); // 清除第2位
            P2 |= (1 << 3);  // 设置第3位
            P2 &= ~(1 << 4); // 清除第4位
            break;
        case 3:
            P2 |= (1 << 2);  // 设置第2位
            P2 |= (1 << 3);  // 设置第3位
            P2 &= ~(1 << 4); // 清除第4位
            break;
        case 4:
            P2 &= ~(1 << 2); // 清除第2位
            P2 &= ~(1 << 3); // 清除第3位
            P2 |= (1 << 4);  // 设置第4位
            break;
        case 5:
            P2 |= (1 << 2);  // 设置第2位
            P2 &= ~(1 << 3); // 清除第3位
            P2 |= (1 << 4);  // 设置第4位
            break;
        case 6:
            P2 &= ~(1 << 2); // 清除第2位
            P2 |= (1 << 3);  // 设置第3位
            P2 |= (1 << 4);  // 设置第4位
            break;
        case 7:
            P2 |= (1 << 2);  // 设置第2位
            P2 |= (1 << 3);  // 设置第3位
            P2 |= (1 << 4);  // 设置第4位
            break;
        default:
            // 默认情况下清除所有位
            P2 &= ~(1 << 2);
            P2 &= ~(1 << 3);
            P2 &= ~(1 << 4);
            break;
    }
    // 使用位操作优化数码管位置设置
    P2 = (P2 & 0xE3) | ((position & 0x07) << 2);

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
}