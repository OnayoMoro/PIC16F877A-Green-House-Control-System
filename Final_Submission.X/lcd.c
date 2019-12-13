#include <xc.h> 
#include "lcd_driver.h"

void write_str(unsigned char *array)
{
    char * p; int i = 0;
    for (p = array; *p != '\0'; p++){
        writechar(array[i]);   
        i++;
    } 
}

//--------------------------------------
//delay
void delay_lcd()
{
    int i;
for(i=0;i<60;i++);
}

//--------------------------------------
//write a byte to lcd.
void writechar(unsigned char x)
{
    rs=1;                      //is data not command.
    rw=0;                      //is write not read.
    e=0;                       //pull low enable signal.
    delay_lcd();                   //for a while.
    e=1;                       //pull high to build the rising edge.
    delay_lcd();
    PORTD=x;                   //data send to PORTD
    delay_lcd();
    e=0;
}

//--------------------------------------
//lcd display setting 
void writecmd_4line(unsigned char x)
{
    rs=0;                     //is command not data
    rw=0;                     //is write not read. 
    e=0;                       //pull low enable signal.
    delay_lcd();                   //for a while.
    e=1;                       //pull high to build the rising edge.
    delay_lcd();
    PORTD=x;                   //data send to PORTD
    delay_lcd();
    e=0;
}

//---------------------------------------
//LCD initialisation 
void lcd_init()
{
    //I/O init
    ADCON1=0X07;               //a port as ordinary i/o.
    TRISA=0X00;                //a port as output.
    TRISD=0X00;                //d port as output.
    pb = 1;
    
    //LCD init
    writecmd_4line(0x0e);              //display on,cursor on,blink on.
    writecmd_4line(0x1);               //clr screen 
    writecmd_4line(0x38);              //8 bits 2 lines 5*7 mode.  
}

//---------------------------------------


