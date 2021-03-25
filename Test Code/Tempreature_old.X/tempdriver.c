#include "temp_header.h"
#include<pic.h>
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
 
#define  uch unsigned char                   //                                          
# define DQ RA0                              //define 18B20 data PORT                    
# define DQ_DIR TRISA0                       //define 18B20 D PORT direct register       
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
unsigned char baifen;                        //hundred cent bit                          
unsigned char qianfen;                       //thousand cent bit                         
unsigned char wanfen;                        //myriad cent bit                           
//unsigned char table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90}; 
unsigned char num[]={'0','1','2','3','4','5','6','7','8','9'};
//the display code of 0-9     

//void display()
//{
//    char tempnum = number[shi];
//    dispcmd(1,tempnum);
//    
////------------------------------------------------------------------------------    
////------------------------------------------------------------------------------    
//// TRISA=0X00;                           //set A PORT all OUTPUT                          
//// PORTD=table[shi];                     //display integer ten bit                        
//// PORTA=0x3e;                                                                            
//// delay(10,70);                                                                          
//// PORTD=table[ge]&0X7F;                 //display integer Entries bit and decimal dot    
//// PORTA=0x3d;                                                                            
//// delay(10,70);                                                                          
//// PORTD=table[shifen];                  //display decimal ten cent bit                    
//// PORTA=0x3b;                                                                            
//// delay(10,70);                                                                          
//// PORTD=table[baifen];                  //display decimal hundred cent bit               
//// PORTA=0x37;                                                                            
//// delay(10,70);                                                                          
//// PORTD=table[qianfen];                 //display decimal thousand  cent bit             
//// PORTA=0x2f;                                                                            
//// delay(10,70);                                                                          
//// PORTD=table[wanfen];                  //display decimal myriad cent bit                
//// PORTA=0x1f;
//// delay(10,70);
//}

void delay_temp(char x,char y) 
{
  char z;
  do{
      z=y;
      do{;}while(--z);
     }while(--x);
 }