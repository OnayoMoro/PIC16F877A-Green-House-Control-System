/*
 * File:   functions_source.c
 * Author: onayo
 *
 * Created on 27 November 2019, 19:08
 */
#include <xc.h>
#include "functions_header.h"
#include "clock_header.h"
#include "lcd_driver.h"

void delay_main(){
    for (int i=0;i<10000;i++){
    }
}

void display_val(unsigned int i){
    if (i == 0 || i == 6){
        writecmd_4line(0x94);
    }
    else if (i == 1 || i == 4){
        writecmd_4line(0x92);
    }
    else if (i == 2 || i == 3){
        writecmd_4line(0x90);
    }
    
    int t;
    t = table[i]&0xf0;
    t=t>>4;
    writechar(t + '0');
    t=t<<4;
    t = table[i]&0x0f;
    writechar(t + '0');
    
    if (i == 0 || i == 6){
        writecmd_4line(0x94);
    }
    else if (i == 1 || i == 4){
        writecmd_4line(0x92);
    }
    else if (i == 2 || i == 3){
        writecmd_4line(0x90);
    }
}
