#include <reg52.h>


void UART_Init() {
    TMOD = 0x20;  // Timer1 in mode 2, 8-bit auto-reload
    TH1 = 0xFD;   // Load value for 9600 baud rate
    SCON = 0x50;  // Serial mode 1, 8-bit data, 1 stop bit, REN enabled
    TR1 = 1;      // Start Timer1
}

void UART_Send(unsigned char d) {
    SBUF = d;          // Load data into UART buffer
    while (TI == 0);      // Wait until transmission is complete
    TI = 0;               // Clear transmission interrupt flag
}

unsigned char UART_Receive() {
    while (RI == 0);      // Wait until reception is complete
    RI = 0;               // Clear reception interrupt flag
    return SBUF;          // Return received data
}