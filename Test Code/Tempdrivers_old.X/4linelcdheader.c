#include "4linelcdheader.h"
#include <xc.h> 
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = ON // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)


#define rs RA5
#define rw RA4
#define e  RA3
#define pb RA2


void dispcmd(int line, char * linetxt){
    if (line == 0 || line == 1){
        writecmd_4line(0x80);     //address for the first line
        yeet(linetxt);
    }
    else if (line == 2){
        writecmd_4line(0x90);     //address for second line
        yeet(linetxt);
    }
    else if (line == 3){
        writecmd_4line(0x88);     //address for third line
        yeet(linetxt);
    }
    else if (line == 4){
        writecmd_4line(0x98);     //address for the forth line
        yeet(linetxt);
    }
    else if (line != 0 && line != 1 && line != 2 && line != 3 && line != 4){
        
        char error[] = "LINE DOES NOT EXIST";
        yeet(error);
    }
}


void yeet(char *array){
    char * p; int i = 0;
    for (p = array; *p != '\0'; p++){
        writechar(array[i]);   
        i++;
    } 
}

//--------------------------------------
//delay
void delay()
{
    int i;
for(i=0;i<5000;i++);
}

//--------------------------------------
//write a byte to lcd.
void writechar(char x)
{
    rs=1;                      //is data not command.
    rw=0;                      //is write not read.
    PORTD=x;                   //data send to PORTD
    e=0;                       //pull low enable signal.
    delay();                   //for a while.
    e=1;                       //pull high to build the rising edge.
}

//--------------------------------------
//lcd display setting 
void writecmd_4line(char x)
{
    rs=0;                     //is command not data
    rw=0;                     //is write not read. 
    PORTD=x; 
    e=0;                      //pull low enable signal.           
    delay();                  //for a while.                      
    e=1;                      //pull high to build the rising edge
}

//---------------------------------------
//LCD init
void lcd_init()
{
    pb = 1;
    writecmd_4line(0x0e);              //display on,cursor on,blink on.
    writecmd_4line(0x1);               //clr screen 
    writecmd_4line(0x38);              //8 bits 2 lines 5*7 mode.  
}

//---------------------------------------
//I/O init
void init_4line()
{
    ADCON1=0X07;               //a port as ordinary i/o.
    TRISA=0X00;                //a port as output.
    TRISD=0X00;                //d port as output.
}