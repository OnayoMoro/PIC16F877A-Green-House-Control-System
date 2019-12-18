/* 
 * File:   temphead.h
 * Author: Onayo Moro
 *
 * Created on 12 November 2019, 20:54
 */
#include <xc.h> 

#ifndef TH
#define	TH
                                  
//__CONFIG(0x1832);
//begin config
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = ON // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
//end config

//THE configure of MCU,watchdog OFF,electrify delay OPEN,power down check OFF,
//LOW power programme OFF,encrypt,4M crystal HS surge.
 
# define  uch unsigned char                   //                                          
# define DQ RE0                              //define 18B20 data PORT                    
# define DQ_DIR TRISE0                       //define 18B20 E PORT direct register       
# define DQ_HIGH() DQ_DIR =1                 //set data PORT INPUT                       
# define DQ_LOW() DQ = 0; DQ_DIR = 0         //set data PORT OUTPUT                      
 unsigned char  TLV=0 ;                      //temperature high byte                     
 unsigned char  THV=0;                       //temperature low byte                      
 unsigned char TZ=0;                         //temperature integer after convert         
 unsigned char TX=0;                         //temperature decimal  after convert        
 unsigned int wd;                            //temperature BCD code  after convert       
                                                                     
unsigned char shi;                           //integer ten bit                           
unsigned char ge;                            //integer Entries bit                       
unsigned char shifen;                        //ten cent bit     

unsigned char day_ten_max = 2;
unsigned char day_one_max = 5;
unsigned char day_dec_max = 5;

unsigned char day_ten_min = 2;
unsigned char day_one_min = 4;
unsigned char day_dec_min = 5;

unsigned char night_ten_max = 2;
unsigned char night_one_max = 1;
unsigned char night_dec_max = 0;

unsigned char night_ten_min = 2;
unsigned char night_one_min = 0;
unsigned char night_dec_min = 0;

unsigned char pass = 0;
unsigned int buzz_count = 0;

unsigned char temp_p;
unsigned char temp_d;

unsigned char temp_sec;

void delay_temp(unsigned char x,unsigned char y);
void display_temp();
reset(void);
void write_byte(uch val);
uch read_byte(void);
void get_temp(void);
void temp_setting(void);
void set_day(void);
void set_night(void);
void temp_increment(void);
void temp_decrement(void);
void temp_day(void);
void temp_night(void);
void cool(void);
void heat(void);
void OK(void);
void temp_check_lower(void);
void temp_check_rise(void);

#endif	// TEMPHEAD_H 

