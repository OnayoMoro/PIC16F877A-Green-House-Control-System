/* 
 * File:   button_press.h
 * Author: Jennifer Lam
 *
 * Created on 08 November 2019, 16:00
 */
#include <xc.h> // include processor files - each processor file is guarded. 
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

//begin config
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = ON // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV onMCLR must be used for programming)
//end config

unsigned char SecondRC;
unsigned char FirstRC;
unsigned char OutputRC;

void initialisation (void);
void OutputPins (void);
void InputPins (unsigned int RC);
void button_reset(void);

#endif	/* XC_HEADER_TEMPLATE_H */

