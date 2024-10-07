#include<reg52.h>

void Update_Display_LCD(void){
    
    unsigned char min1, min2, sec1, sec2, ms1, ms2;
    // 更新数码管
    min1 = minutes/10;
    min2 = minutes%10;
    sec1 = seconds/10;
    sec2 = seconds%10;
    ms1 = milliseconds/10;
    ms2 = milliseconds%10;
    LCD_ShowChar(1, 1, '0');
    LCD_ShowChar(1, 2, '0');
    LCD_ShowChar(1, 3, '-');
    LCD_ShowChar(1, 4, '0');
    LCD_ShowChar(1, 5, '0');
    LCD_ShowChar(1, 6, '-');
    LCD_ShowChar(1, 7, '0');
    LCD_ShowChar(1, 8, '0');

}



void main(void) {
    LCD_Init();
    Timer0_Init();

    while (1) { // 主循环
        if (flag_10ms) { // 10ms标志，计时
            flag_10ms = 0;
            timer();
        }
        
        if (flag_1ms) { // 1ms标志，更新数码管
            flag_1ms = 0;
            Update_Display_LCD();
        }
        
        if (flag_button) { // 按键扫描标志，扫描按键
            flag_button = 0;
            Key_Scan();
        }
    }
}