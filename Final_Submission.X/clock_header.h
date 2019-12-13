/* 
 * File:   clock_header.h
 * Author: Onayo Moro
 *
 * Created on 22 November 2019, 16:00
 */
#include <pic.h> // include processor files - each processor file is guarded.

#ifndef CLOCK_H
#define	CLOCK_H

#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = ON // Power-up Timer Enable bit (PWRT disabled
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
//__CONFIG(0x1832);       
//__CONFIG _DEBUG_OFF&_CP_ALL&_WRT_HALF&_CPD_ON&_LVP_OFF&_BODEN_OFF&_PWRTE_ON&_WDT_OFF&_HS_OSC     

#define i_o   RB4                      //1302I_O           
#define sclk  RB0                      //1302 clock        
#define rst   RB5                      //1302 enable bit   

//Functions
void clock_init(void);
void port_init();                            //port initilize subroutine.
void ds1302_init();                          //DS1302 initilize subroutine.
void set_time_date();                        //set time and date subroutine.
void week(unsigned int w);                            //set week subroutine.
void get_time(void);                             //get time subroutine.
void display_clock(void);                        //display subroutine.
void start_time(void);
void start_date(void);
void time_write_1(unsigned char time_tx);    //write one byte subroutine.
void D(unsigned char * D,unsigned char * C,unsigned int i);
void T(unsigned char * T,unsigned char * C,unsigned int i);
void clock_setting(void);
void date_setting(void);

//Global variables
unsigned char table[]={0x55,0x29,0x08,0x27,0x02,0x07,0x22,0x00}; //define the time: sec,min,hour,day,month,week,year,control word.
unsigned char table1[7];                              //define the read time and date save table.
unsigned char time_read_1(void);                //read one byte subroutine.
unsigned char table2[]={'0','1','2','3','4','5','6','7','8','9'};  //the display code of 0-9
unsigned char wkd;                                    //week day identifier 

//const int table[]={0,8,12,8,3,6,6,0};

#endif	/* CLOCK_H */
    
