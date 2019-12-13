/*
 * File:   ClimateControl.c
 * Author: Onayo Moro
 *
 * Created on 22 November 2019, 17:10
 */
#include <xc.h>
#include "lcd_driver.h" 
#include "temp_header.h"
#include "button_press_header.h"
#include "clock_header.h"
#include "buzzer_header.h"
#include "functions_header.h"





void main()
{ 
    buzzer_init();
    clock_init();
    lcd_init();
    initialisation ();
    
   
    
   while(1)                                                                                                                                                                                        
   {           
       get_temp();
       get_time();
       display_clock();

       //Reset button variables
       button_reset();
       
       //K13 button used to go to the Time Settings screen 
       if (OutputPins(),FirstRC == 1 && SecondRC == 1){
           button_reset();                    //Reset button variables
           clock_setting();
           writecmd_4line(0x1);               //clr screen
       }
       //K17 button used to go to the Date Settings screen
       else if (OutputPins(),FirstRC == 1 && SecondRC == 2){
           button_reset();                    //Reset button variables
           date_setting();
           writecmd_4line(0x1);               //clr screen
       }
       //K21 button used to go to the Temperature Settings screen
       else if (OutputPins(),FirstRC == 1 && SecondRC == 3){
           button_reset();                    //Reset button variables
           temp_setting();
           writecmd_4line(0x1);               //clr screen
       }
       //K22 button used to silence buzzer temperature alarm
       else if (OutputPins(),FirstRC == 4 && SecondRC == 4){
           button_reset();
           if (buzz_count >=20){
               buzzer  = 0;
               pass = 1;
               buzz_count = 0;
           }
       }

       
       
       
       
       //Time split between 0 - 29 mins and 30 - 59 mins
       //Time threshold
       
       //More than 30 mins
       if (table1[1] > 0x29){               //Between 30 mins to 59 mins
           //Night Time
           if (table1[2] >= 0x19){          //Greater than 19:30
                writecmd_4line(0x95);
                write_str("Night");         //It is night time
                temp_night();           //If temp is within night threshold 
           }
           //Night Time
           else if (table1[2] < 0x06){      //Any hour below 6am between 30 - 59 mins
                writecmd_4line(0x95);
                write_str("Night"); 
                temp_night();           //If temp is within night threshold 
           }
           //Day Time
           else {
                writecmd_4line(0x95);       //All hours above 6am between 30 - 59 mins
                write_str("Day  "); 
                temp_day();             //CIf temp is within day threshold 
           }
           
       }
       //Less than 30 mins
       else if (table[1] < 0x30){           //0 - 29 mins 
           //Night Time
           if (table1[2] >= 0x20){          //Greater than 19:30
                writecmd_4line(0x95);
                write_str("Night");         //It is night time
                temp_night();           //Checking for night max temp
           }
           //Night Time
           else if ( table1[2] <= 0x06){    //Any hour below 6am between 0 - 29 mins
                writecmd_4line(0x95);       
                write_str("Night");         //Still night time
                temp_night();           //If temp is within night threshold 
           }
           //Day Time
           else {
                writecmd_4line(0x95);       //All hours bellow 7pm between 0 - 29 mins 
                write_str("Day  "); 
                temp_day();             //If temp is within day threshold 
           }
       }        
    }
}      


