#include <xc.h> 
//begin config
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = ON // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF// Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial
//Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for 
//programming)
//end config
void delay () { 
for 
(unsigned i=0; i<50; i++); 
} 
void main () 
{ 
TRISA = 0x00;
TRISD = 0x00;
for (int i=0; i<10; i=0 )
{
    PORTA = 0xFE;
    PORTD = 0xF9;
    
    delay();
    
    PORTA = 0xFD;
    PORTD = 0xA4;
    
    delay();
    
    PORTA = 0xFB;
    PORTD = 0xB0;
    
    delay();
    
    PORTA = 0xF7;
    PORTD = 0x99;
    
    delay();
    
    PORTA = 0xEF;
    PORTD = 0x92;
    
    delay();
    
    PORTA = 0xDF;
    PORTD = 0x82;
    
    delay();
    
}
} 
