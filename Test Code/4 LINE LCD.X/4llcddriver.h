/* 
 * File:   4llcddriver.h
 * Author: Onayo Moro
 *
 * Created on 04 November 2019, 17:26
*/
#ifndef 4LLCDDRIVER_H
#define	4LLCDDRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif



#endif	/* 4LLCDDRIVER_H */
#define rs RA5
#define rw RA4
#define e  RA3
#define pb RA2

void lcd_init();               //LCD init
void writecmd(char x);         //display one byte
void writechar(char x);        //LCD display setting.
void delay();                  //delay
void yeet(char *s);
void dispcmd(int line, char * linetxt);
void writelcd(char line, char *str);
void replaceachar(char line, char poistion, char letter);
