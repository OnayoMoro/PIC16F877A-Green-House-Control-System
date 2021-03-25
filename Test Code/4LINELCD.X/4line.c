#include <xc.h> 
#include "4llcddriver.h"
//begin config
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = ON // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
//end config

void init();                   //I/O init
//I/O init
void init()
{
    ADCON1=0X07;               //a port as ordinary i/o.
    TRISA=0X00;                //a port as output.
    TRISD=0X00;                //d port as output.
}
//---------------------------------------
//---------------------------------------
//main
void main()
{ 
    init();                //I/O init
    lcd_init();            //LCD init 
    writecmd(0x0F);
    while(1)
    {
        dispcmd(1, "Wus gud");
        dispcmd(2, "my G?");
        dispcmd(3, "I'm chill");
        dispcmd(3, "kill me");
        while(1);
     }
}