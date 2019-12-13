/*
 * File:   buzzer.c
 * Author: Onayo Moro
 *
 * Created on 25 November 2019, 21:50
 */

#include <xc.h>
#include "buzzer_header.h"
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = ON // Power-up Timer Enable bit (PWRT disabled
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)

void buzzer_init(){
    ADCON1=0X07;
    TRISE=0X00;
    PORTE=0X00;
}
