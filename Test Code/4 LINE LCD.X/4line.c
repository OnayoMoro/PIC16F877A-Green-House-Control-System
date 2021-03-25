#include <xc.h> 
//begin config
#include "4linelcdheader.h"
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = ON // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
//end config

#define rs RA5
#define rw RA4
#define e  RA3
#define pb RA2


//---------------------------------------
//main
void main()
{ 
    init();                //I/O init
    lcd_init();            //LCD init 
    writecmd(0x0F);
    while(1)
    {
//        char str[] = "Wus gud";        //This demonstrates how to 
//        yeet(str);                          //pass the array without pointers.
//        writecmd(0x90);
//        char *str2[] = {"bby cakes"};       //This is how to pass the array
//        yeet(*str2); 
        dispcmd (3,"Hello Wolrd");//with pointers.
        dispcmd (2,"Hi there");
        dispcmd (4, "Yo Yo");
        dispcmd (1, "Sweet Jesus");
        while(1);
     }
}

