#include "4llcddriver.h"


void replaceachar(char line, char poistion, char letter){
    
}

void writelcd(char line, char *str){
    
}

void dispcmd(int line, char * linetxt){
    if (line == 0 || line == 1){
        yeet(linetxt);
    }
    else if (line == 2){
        writecmd(0x90);     //address for second line
        yeet(linetxt);
    }
    else if (line == 3){
        writecmd(0x88);     //address for third line
        yeet(linetxt);
    }
    else if (line == 4){
        writecmd(0x98);     //address for the forth line
        yeet(linetxt);
    }
    else if (line != 0 && line != 1 && line != 2 && line != 3 && line != 4){
        
        char error[] = "LINE DOES NOT EXIST";
        yeet(error);
    }
}


void yeet(char *linetxt){
    char * p; int i = 0;
    for (p = linetxt; *p != '\0'; p++){
        writechar(linetxt[i]);   
        i++;
    } 
}

//LCD init
void lcd_init()
{
    pb = 1;
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
for(i=0;i<1;i++);
}
