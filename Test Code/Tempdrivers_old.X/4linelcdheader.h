/* 
 * File:   4linelcdheader.h
 * Author: Onayo Moro
 *
 * Created on 08 November 2019, 16:00
 */
#include <xc.h> 
#ifndef oioi
#define	oioi



void yeet (char * array);
void dispcmd(int line, char * linetxt);
void init_4line();                   //I/O init
void lcd_init();               //LCD init
void writecmd_4line(char x);         //display one byte
void writechar(char x);        //LCD display setting.
void delay();                  //delay

#endif // 4LINELCDHEADER_H 