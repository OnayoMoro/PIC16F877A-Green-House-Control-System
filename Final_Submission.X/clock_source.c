#include <pic.h>                        //include MCU head file     
#include "clock_header.h"
#include "lcd_driver.h"
#include "button_press_header.h"
#include "functions_header.h"
#include "temp_header.h"

void week(unsigned int w){
    if (w == 1)
        write_str("Mon");
    else if (w == 2)
        write_str("Tue");
    else if (w == 3)
        write_str("Wed");
    else if (w == 4)
        write_str("Thu");
    else if (w == 5)
        write_str("Fri");
    else if (w == 6)
        write_str("Sat");
    else if (w == 7)
        write_str("Sun");
}

//---------------------------------------------
//DS1302 initilize.
void ds1302_init(){
   sclk=0;                            //pull low clock
   rst =0;                            //reset DS1302
   rst=1;                             //enable DS1302
   time_write_1(0x8e);                //send control command
   time_write_1(0);                   //enable write DS1302
   rst=0;                             //reset
}

//---------------------------------------------
//set time and date.
void set_time_date(){
   int i;                             //define the loop counter.
   rst=1;                             //enable DS1302
   time_write_1(0xbe);                //
   
   for(i=0;i<8;i++)                   //continue to write 8 bytes.
    {
       time_write_1(table[i]);        //write one byte
    }
   rst=0;                             //reset
}

//---------------------------------------------
//get time.
void get_time() {
   int i;                             //set loop counter.
   rst=1;                             //enable DS1302
   time_write_1(0xbf);                //
   for(i=0;i<7;i++)                   //continue to read 7 bytes.
    {
        table1[i]=time_read_1();      //
    }
    rst=0;                            //reset DS1302
}

//--------------------------------------------
//write one byte
void time_write_1(unsigned char time_tx){
    int j;                            //set the loop counter.
    for(j=0;j<8;j++)                  //continue to write 8bit
    {
        i_o=0;                        //
        sclk=0;                       //pull low clk
        if(time_tx&0x01)              //judge the send bit is 0 or 1.
          {
            i_o=1;                    //is 1
          }
        time_tx=time_tx>>1;           //rotate right 1 bit.
        sclk=1;                       //pull high clk
    }
    sclk=0;                         //finished 1 byte,pull low clk
}

//---------------------------------------------
//read one byte.
unsigned char time_read_1(){
   unsigned char time_rx=0;
   int j;                            //set the loop counter.  
   TRISB4=1;                         //continue to write 8bit 
   for(j=0;j<8;j++)                  
   {
        sclk=0;                       //pull low clk                   
        time_rx=time_rx>>1;           //judge the send bit is 0 or 1.  
        if(i_o)time_rx=time_rx|0x80;
    //    time_rx7=i_o;                //put the received bit into the reg's highest.
       sclk=1;                       //pull high clk                 
    }                                                              
    TRISB4=0;                        //finished 1 byte,pull low clk  
    sclk=0;                          
    return(time_rx);                 
}

//--------------------------------------------
//pin define func
void port_init(){
    ADCON1=0X06;                    //a port all i/o
    TRISB=0X02;                     //rb1 input, others output
    OPTION_REG=0X00;                    //open b port internal pull high.
}

//-------------------------------------------
//display
void display_clock(){
    int i;                         //define table variable.
    
    //Date Header
    writecmd_4line(0x80);
    write_str("Date:");
    
    //Day
    i=table1[3]&0xf0;
    i=i>>4;
    writechar(i + '0');
    i=i<<4;
    i = table1[3]&0x0f;
    writechar(i + '0');
    write_str("/");
    
    //Month
    i=table1[4]&0xf0;
    i=i>>4;
    writechar(i + '0');
    i=i<<4;  
    i = table1[4]&0x0f;
    writechar(i + '0');
    write_str("/"); 
    
    //Year
    i=table1[6]&0xf0;
    i=i>>4;
    writechar(i + '0');
    i=i<<4; 
    i = table1[6]&0x0f;
    writechar(i + '0');
    
    //Week
    writecmd_4line(0x90);
    write_str("Week:");
    wkd = (table1[5]);
    week(table1[5]);
    
    //Time Header
    writecmd_4line(0x88);
    write_str("Time:");
    
    //Hours
    i=table1[2]&0xf0;
    i=i>>4;
    writechar(i + '0');
    i=i<<4;
    i = table1[2]&0x0f;
    writechar(i +'0');
    write_str(":");
    
    //Minutes
    i=table1[1]&0xf0;
    i=i>>4;
    writechar(i + '0');
    i=i<<4;
    i = table1[1]&0x0f;
    writechar(i +'0');
    write_str(":");
    
    //Seconds
    i=table1[0]&0xf0;
    i=i>>4;
    writechar(i + '0');
    i=i<<4;
    i = table1[0]&0x0f;
    temp_sec = i;
    writechar(i +'0');
    
    
}

void clock_init(){
    port_init();                     //port initilize.
    ds1302_init();                   //DS1302 initilize.
    set_time_date();                      //set time
}

void start_date(){
    int i;

    //Day
    i=table[3]&0xf0;
    i=i>>4;
    writechar(i + '0');
    i=i<<4;
    i = table[3]&0x0f;
    writechar(i + '0');
    write_str("/ ");
    
    //Month
    i=table[4]&0xf0;
    i=i>>4;
    writechar(i + '0');
    i=i<<4;
    i = table[4]&0x0f;
    writechar(i + '0');
    write_str("/ ");
    
    //Year
    i=table[6]&0xf0;
    i=i>>4;
    writechar(i + '0');
    i=i<<4;
    i = table[6]&0x0f;
    writechar(i + '0');
    
    //Week
    writecmd_4line(0x88);
    write_str("Week: ");
    
}

void start_time(){
    int i;
    i=table[2]&0xf0;
    i=i>>4;
    writechar(i + '0');
    i=i<<4;
    i = table[2]&0x0f;
    writechar(i +'0');
    write_str(": ");
    
    //Minutes
    i=table[1]&0xf0;
    i=i>>4;
    writechar(i + '0');
    i=i<<4;
    i = table[1]&0x0f;
    writechar(i +'0');
    write_str(": ");
    
    //Seconds
    i=table[0]&0xf0;
    i=i>>4;
    writechar(i + '0');
    i=i<<4;
    i = table[0]&0x0f;
    writechar(i +'0');
}

void clock_setting(){
    writecmd_4line(0x1);               //clr screen
    writecmd_4line(0x80);
    write_str("Time Settings");
    writecmd_4line(0x90);
    start_time();
    writecmd_4line(0x88);
    write_str("Change time...");
    int i=0;
    
    for (;;){
        
        //Return to home screen/main function
        if (OutputPins(),FirstRC == 2 && SecondRC == 1){
            return;
        }
        else if (OutputPins(),FirstRC == 2 && SecondRC == 2){
            set_time_date();
            return;
        }
        //Choose to the left
        else if (OutputPins(),FirstRC == 3 && SecondRC == 1){
            button_reset();
            
            if (i != 2){
                i++;
                if (i == 1 ){
                    writecmd_4line(0x88);
                    write_str("                ");
                    writecmd_4line(0x88);
                    write_str("Minute");
                    T('m','0',i);
                    delay_main();
                }
            }
            else if (i == 2){
                writecmd_4line(0x88);
                write_str("                ");
                writecmd_4line(0x88);
                write_str("Hour");
                T('h','0',i);
                delay_main();
            }
        }
        //Choose to the right
        else if (OutputPins(),FirstRC == 4 && SecondRC == 1){
            button_reset();
            
            if (i != 0){
                i--;
                if (i == 1){
                    writecmd_4line(0x88);
                    write_str("                ");
                    writecmd_4line(0x88);
                    write_str("Minute");
                    T('m','0',i);
                    delay_main();
                }
            }
            else if (i == 0){
                writecmd_4line(0x88);
                write_str("                ");
                writecmd_4line(0x88);
                write_str("Seconds");
                T('s','0',i);
                delay_main();
            }
        }
        
        //Decrement selected value down
        else if (OutputPins(),FirstRC == 3 && SecondRC == 2){
            button_reset();
            
            //Seconds
            if (i == 0){
                T('s','d',i);
            }
            
            //Minutes
            else if (i == 1){
                T('m','d',i);
            }
            
            //Hours
            else if (i == 2){
                T('h','d',i);
                
            }
        }
        
        //Increment selected value up
        else if (OutputPins(),FirstRC == 4 && SecondRC == 2){
            button_reset();
            
            //Day
            if (i == 0){
                T('s','i',i);
            }
            
            //Minutes
            else if (i == 1){
                T('m','i',i);
            }
            
            //Hours
            else if (i == 2){
                T('h','i',i);
            }
        }
    }
    
}

void date_setting(){
    
    writecmd_4line(0x1);               //clr screen
    writecmd_4line(0x80);
    write_str("Date Settings");
    writecmd_4line(0x90);
    start_date();
    week(wkd);
    writecmd_4line(0x98);
    write_str("Change date...");
    int i=3;
    
    for (;;){
        
        //Return to home screen/main function without saving
        if (OutputPins(),FirstRC == 2 && SecondRC == 1){
            return;
        }
        
        //Return to home screen/main function with saving
        else if (OutputPins(),FirstRC == 2 && SecondRC == 2){
            table[5] = wkd;
            set_time_date();
            return;
        }
        
        //Choose to the right
        else if (OutputPins(),FirstRC == 4 && SecondRC == 1){
            button_reset();
            
            if (i != 6){
                i++;
                if (i == 5){
                    D('w','0',i);
                    delay_main();
                }
                else if (i == 4){
                    D('m','0',i);
                    display_val(i);
                    delay_main();
                }
            }
            else if (i == 6){
                D('y','0',i);
                display_val(i);
                delay_main();
            }
        }

        //Choose to the left
        else if (OutputPins(),FirstRC == 3 && SecondRC == 1){
            button_reset();
            
            if (i != 3){
                i--;
                if (i == 5){
                    D('w','0',i);
                    delay_main();
                }
                else if (i == 4){
                    D('m','0',i);
                    display_val(i);
                    delay_main();
                }
            }
            else if (i == 3){
                D('d','0',i);
                delay_main();
            }
        }
        
        //Decrement selected value down
        else if (OutputPins(),FirstRC == 3 && SecondRC == 2){
            button_reset();
            
            //Day
            if (i == 3){
                D('d','d',i);
            }
            
            //Week
            else if (i == 5){
                //D('w','0',i);
                if (wkd != 1){
                    wkd--;
                    writecmd_4line(0x8B);
                    week(wkd);
                    writecmd_4line(0x8B);
                }
                delay_main();
            }
            
            //Month
            else if (i == 4){
                D('m','d',i);
            }
            
            //Year
            else if (i == 6){
                D('0','1',i);;
                if (table[i] != 0x00){
                    if (table[i] == 0x10 || table[i] == 0x20 
                        || table[i] == 0x30 || table[i] == 0x40 
                        || table[i] == 0x50 || table[i] == 0x60 
                        || table[i] == 0x70 || table[i] == 0x80 
                        || table[i] == 0x90 
                        || table[i] == 0x100){
                        for (int j=0; j<6; j++){
                            table[i]--;
                        }
                        display_val(i);
                        //delay_main();
                    }
                    else {
                        table[i]--;
                        display_val(i);
                        delay_main();
                    }
                }
                else {
                    display_val(i);
                    delay_main();
                }
            }
        }
        
        //Increment selected value up
        else if (OutputPins(),FirstRC == 4 && SecondRC == 2){
            button_reset();
            
            //Day
            if (i == 3){
                display_val(i);
                
                //Check for February
                if (table[4] == 0x02){
                    
                    //Leap Year
                    //unsigned char y = (table[6] + '0');
                    unsigned char a = (table[6]&0xF0)>>4;
                    unsigned char b = (table[6]&0x0F);
                    unsigned char y = a*10 + b;
                    if (y%4 == 0){
                        //Invalid day for February 
                        if (table[3] == 0x30 || table[3] == 0x31){
                            table[3] = 0x29; 
                            display_val(i);
                            delay_main();
                        }
                        //Increment normally
                        if (table[i] == 0x09 || table[i] == 0x19){
                            for (int j=0; j<7; j++){
                                table[i]++;
                            }
                            display_val(i);
                            delay_main();
                        }
                        else if (table[i] != 0x29){
                            table[i]++;
                            display_val(i);
                            delay_main();
                        }
                        else {
                            delay_main();
                        }
                    }
                    
                    //Not Leap Year
                    else if (table[6]%4 != 0){
                        //Invalid day for February
                        if (table[3] == 0x30 || table[3] == 0x31 || table[3] == 0x29){
                            table[3] = 0x28; 
                            display_val(i);
                            delay_main();
                        }
                        //Increment normally                  
                        if (table[i] == 0x09 || table[i] == 0x19){
                            for (int j=0; j<7; j++){
                                table[i]++;
                            }
                            display_val(i);
                            delay_main();
                        }
                        else if (table[i] != 0x28){
                            table[i]++;
                            display_val(i);
                            delay_main();
                        }     
                        else {
                           delay_main();
                        }
                    }
                }
                //Not a leap year
                else if (table[i] != 0x31){
                    if (table[i] == 0x09 || table[i] == 0x19 || table[i] == 0x29){
                        for (int j=0; j<7; j++){
                            table[i]++;
                        }
                        display_val(i);
                        delay_main();
                    }
                    else {
                        table[i]++;
                        display_val(i);
                        delay_main();
                    }
                }
                else {
                    delay_main();
                }
            }
            
            //Week
            else if (i == 5){
                if (wkd != 7){
                    wkd++;
                    writecmd_4line(0x8B);
                    week(wkd);
                    writecmd_4line(0x8B);
                }
                delay_main();
            }
            
            //Month
            else if (i == 4){
                D('m','1',i);
                if (table[i] != 0x12){
                    if (table[i] == 9){
                        for (int j=0; j<7; j++){
                            table[i]++;
                        }
                        display_val(i);
                        delay_main();
                    }
                    else {
                        table[i]++;
                        display_val(i);
                        delay_main();
                    }
                }
                else {
                    display_val(i);
                    delay_main();
                }
            }
            
            //Year
            else if (i == 6){
                D('0','1',i);
                if (table[i] != 0x99){
                    if (table[i] == 0x9 || table[i] == 0x19 
                        || table[i] == 0x29 || table[i] == 0x39 
                        || table[i] == 0x49 || table[i] == 0x59 
                        || table[i] == 0x69 || table[i] == 0x79 
                        || table[i] == 0x89){
                        for (int j=0; j<7; j++){
                            table[i]++;
                        }
                        display_val(i);
                        delay_main();
                    }
                    else {
                        table[i]++;
                        display_val(i);
                        delay_main();
                    }
                }
                else {
                    display_val(i);
                    delay_main();
                }
            }
        }
    }
}

void D(unsigned char * D,unsigned char * C,unsigned int i){
    
    if (C == '0'){
        writecmd_4line(0x98);
        write_str("                ");
        writecmd_4line(0x98);

        if (D == 'd'){
            write_str("Day");
            if (C == '0'){
                display_val(i);
                return;
            }
        }
        else if (D == 'm'){
            write_str("Month");
        }
        else if (D == 'w'){
            write_str("Week");
            writecmd_4line(0x8B);
        }
        else if (D == 'y'){
            write_str("Year");
        }
    }
    
    //Decrement for day and month as their lowest value is one
    if (D == 'd' || D == 'm' && C == 'd'){
        if (table[i] != 0x01){
            if (table[i] == 0x10 || table[i] == 0x20 || table[i] == 0x30){ 
                for (int j=0; j<7; j++){
                    table[i]--;
                }
                display_val(i);
                delay_main();
            }
            else{
                table[i]--;
                display_val(i);
                delay_main();
            }
        }
        else{
                display_val(i);
                delay_main();
            }
    }
}

void T(unsigned char * T,unsigned char * C,unsigned int i){
    
    //Decrement
    if ( C == 'd' && table[i] != 0x00){
        if (table[i] == 0x10 || table[i] == 0x20 || table[i] == 0x30
            || table[i] == 0x40 || table[i] == 0x50 
            || table[i] == 0x60){
            for (int j=0; j<7; j++){
                table[i]--;
            }
            display_val(i);
            delay_main();
        }
        else {
            table[i]--;
            display_val(i);
            delay_main();
        }
    }
    
    //Increment for hours
    else if (T == 'h' && C == 'i' && table[i] != 0x23){
        if (table[i] == 0x09 || table[i] == 0x19){
            for (int j=0; j<7; j++){
                table[i]++;
            }
            display_val(i);
            delay_main();
        }
        else {
            table[i]++;
            display_val(i);
            delay_main();
        }
    }
    else if (T == 'h' && C == 'i' && table[i] == 0x23){
            table[i] = 0x00;
            display_val(i);
            delay_main();
        }
    
    //Increment for seconds and minutes
    else if (T != 'h' && C == 'i' && table[i] != 0x59){
        
        if (table[i] == 0x09 || table[i] == 0x19 || table[i] == 0x29
            || table[i] == 0x39 || table[i] == 0x49 
            || table[i] == 0x59){
            for (int j=0; j<7; j++){
                table[i]++;
            }
            display_val(i);
            delay_main();
        }
        else {
            table[i]++;
            display_val(i);
            delay_main();
        }
    }
    else if (C == 'i' && table[i] == 0x59){
            table[i] = 0x00;
            display_val(i);
            delay_main();
        }
    else if (C == 'd'){
        if (T == 'h' && table[i] == 0x00){
                table[i] = 0x23;
                display_val(i);
                delay_main();
            }
            else if (T == 'm' && table[i] == 0x00){
                table[i] = 0x59;
                display_val(i);
                delay_main();
            }
            else if (T == 's' && table[i] == 0x00){
                table[i] = 0x59;
                display_val(i);
                delay_main();
            }
        }
    else {
        display_val(i);
        delay_main();
    }
}

