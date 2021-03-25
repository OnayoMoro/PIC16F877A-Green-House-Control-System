/*
 * File:   buzz_test.c
 * Author: onayo
 *
 * Created on 26 November 2019, 00:56
 */


#include <xc.h>
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = ON // Power-up Timer Enable bit (PWRT disabled
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)

#define buzzer RD2

void main() {
    int i;
    int j;
    ADCON1=0X07;
    TRISD=0X00;
    PORTD=0X00;
    for(;;){
        for (int i=0;i<5000;i++){
            buzzer = 1;
        }
        for (int i=0;i<5000;i++){
            buzzer = 0;
        }
        
    }
}
