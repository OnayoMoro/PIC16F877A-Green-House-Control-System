#include <xc.h> 
//begin config
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = ON // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
//end config

#define rs RA1
#define rw RA2
#define e  RA3

void init();                   //I/O init
void lcd_init();               //LCD init
void writecmd(char x);         //display one byte
void writechar(char x);        //LCD display setting.
void delay();                  //delay
void yeet(char *s);

//I/O init
void init()
{
    ADCON1=0X07;               //a port as ordinary i/o.
    TRISA=0X00;                //a port as output.
    TRISD=0X00;                //d port as output.
}
//---------------------------------------
//LCD init
void lcd_init()
{
    writecmd(0x0e);              //display on,cursor on,blink on.
    writecmd(0x1);               //clr screen 
    writecmd(0x38);              //8 bits 2 lines 5*7 mode.  
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
void writecmd(char x)
{
    rs=0;                     //is command not data
    rw=0;                     //is write not read. 
    PORTD=x; 
    e=0;                      //pull low enable signal.           
    delay();                  //for a while.                      
    e=1;                      //pull high to build the rising edge
}
//--------------------------------------
//delay
void delay()
{
    int i;
for(i=0;i<5000;i++);
}
//---------------------------------------
//main

void yeet(char *array){
    char * p; int i = 0;
    for (p = array; *p != '\0'; p++){
        writechar(array[i]);   
        i++;
    } 
}

void main()
{ 
    init();                //I/O init
    lcd_init();            //LCD init 
    writecmd(0x0F);
    while(1)
    {
        char str[] = "Wus gud";        //This demonstrates how to 
        yeet(str);                          //pass the array without pointers.
        writecmd(0xC0);
        char *str2[] = {"my G?"};       //This is how to pass the array
        yeet(*str2);                        //with pointers.
        while(1);
     }
}

