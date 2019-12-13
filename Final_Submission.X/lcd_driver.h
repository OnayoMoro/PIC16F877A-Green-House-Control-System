/* 
 * File:   4linelcdheader.h
 * Author: Onayo Moro
 *
 * Created on 08 November 2019, 16:00
 */
#include <xc.h> 
#ifndef LD
#define	LD

#define rs RA5
#define rw RA4
#define e  RA3
#define pb RA2

void write_str (unsigned char * array);
void lcd_init(void);               //LCD init and I/O init
void writecmd_4line(unsigned char x);         //display one byte
void writechar(unsigned char x);        //LCD display setting.
void delay_lcd(void);                  //delay

#endif // 4LINELCDHEADER_H 