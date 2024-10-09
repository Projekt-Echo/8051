#include "reg52.h"

// 数码管显示表&缓存

unsigned char NixieTable[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x40, 0x00};
unsigned char Nixie_Buf[9] = {0, 0, 10, 0, 0, 10, 0, 0, 11}; // 包括虚位

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
    P0 = 0x00; // 清除段选

    // 位选
    P2 = (P2 & 0xE3) | ((position & 0x07) << 2);

    // 段选
    if (number >= 0 && number <= 10) {
        P0 = NixieTable[number];
    } else {
        P0 = NixieTable[11]; // 默认清除显示
    }
}

// Nixie_Buffer更新函数
/*
Author: Shiro1sa
Date: 2024-10-06
Description: 更新Nixie_Buffer
Parameters: 
    position: 数码管位置，7-0(从左到右)
    number: 数码管显示的数字，0-9, 10为减号
*/
void Nixie_Buffer_Setter() {
    Nixie_Buf[7] = minutes / 10;
    Nixie_Buf[6] = minutes % 10;
    Nixie_Buf[4] = seconds / 10;
    Nixie_Buf[3] = seconds % 10;
    Nixie_Buf[1] = milliseconds / 10;
    Nixie_Buf[0] = (milliseconds % 10);
}

// 更新数码管显示函数
/*
Author: Shiro1sa
Date: 2024-10-04
Description: 更新数码管显示函数
*/
void Update_Display(void) {
    static unsigned char position = 0;

    display(position, Nixie_Buf[position]);

    position = (position + 1) % 9; // 包括虚位
}

