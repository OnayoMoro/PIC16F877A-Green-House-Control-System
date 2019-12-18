#include <xc.h>
#include "lcd_driver.h" 
#include "temp_header.h"
#include "button_press_header.h"
#include "buzzer_header.h"
#include "functions_header.h"
                    

unsigned int temp_ten, temp_one, temp_dec;

//-----------------------------------------------------------
//delay function              
void delay_temp(unsigned char x,unsigned char y) {
  unsigned char z;
  do{
      z=y;
      do{;}while(--z);
     }while(--x);
 }
                                                                                                          
//--------------------------------------------------                                                                    
//display function
void display_temp(){
    
    writecmd_4line(0x98);
    write_str("Temp:");
    writechar(shi + '0');
    writechar(ge + '0');
    write_str(".");
    writechar(shifen + '0');
    write_str("C");
    
}

//-----------------------------------------------
//reset DS18B20 function   
reset(void){
  unsigned char presence=1;
  while(presence)
  { 
    DQ_LOW() ;                                //MAIN MCU PULL LOW                                                                       
    delay_temp(2,70);                         //delay 503us                                                                             
    DQ_HIGH();                                //release general line and wait for resistance pull high general line and keep 15~60us    
    delay_temp(2,8);                          //delay 70us                                                                              
    if(DQ==1) presence=1;                     // not receive responsion signal,continue reset                                           
    else presence=0;                          //receive responsion signal                                                               
    delay_temp(2,60);                         //delay 430us                                                                             
   }
  }

//-----------------------------------------------
//write 18b20 one byte function     
void write_byte(uch val){
 uch i;
 uch temp;
 for(i=8;i>0;i--)
 {
   temp=val&0x01;                             //shift the lowest bit                   
   DQ_LOW();                                                                           
   NOP();                                                                              
   NOP();                                                                              
   NOP();                                                                              
   NOP();                                                                              
   NOP();                                     //pull high to low,produce write time    
   if(temp==1)  DQ_HIGH();                    //if write 1,pull high                   
   delay_temp(2,7);                           //delay 63us                             
   DQ_HIGH();                                                                          
   NOP();                                                                              
   NOP();                                                                              
   val=val>>1;                                //right shift a bit                      
  }
}

//------------------------------------------------
//18b20 read a byte function  
uch read_byte(void){
 uch i;
 uch value=0;                                 //read temperature         
 static char j;
 for(i=8;i>0;i--)                             //loop to read the incoming byte
 {
   value>>=1;   
   DQ_LOW();                                  //Thermometer set to output (PORTE)
   NOP();                                     //Delay functions allow time to
   NOP();                                     //read byte
   NOP();
   NOP();
   NOP();
   NOP();                                     //6us              
   DQ_HIGH();                                 //pull PORTE high       
   NOP();                                                       
   NOP();                                                       
   NOP();                                                       
   NOP();                                                       
   NOP();                                    //4us               
//   j=DQ;                                                        
   if(DQ == 1) value|=0x80;                                           
   delay_temp(2,7);                          //63us              
  }
  return(value);
}

//-------------------------------------------------
//start temperature convert function   
void get_temp(){ 
DQ_HIGH();
reset();                              //reset,wait for  18b20 responsion                                                                                                               
write_byte(0XCC);                     //ignore ROM matching                                                                                                                            
write_byte(0X44);                     //send  temperature convert command                                                                                                                                                                                                                                                                                          
display_temp();                       //display function                                                                           
reset();                              //reset again,wait for 18b20 responsion                                                                                                          
write_byte(0XCC);                     //ignore ROM matching                                                                                                                            
write_byte(0XBE);                     //send read temperature command                                                                                                                  
TLV=read_byte();                      //read temperature low byte                                                                                                                      
THV=read_byte();                      //read temperature high byte                                                                                                                     
DQ_HIGH();                            //release general line                                                                                                                           
TZ=(TLV>>4)|(THV<<4)&0X3f;            //temperature integer                                                                                                                            
TX=TLV<<4;                            //temperature decimal                                                                                                                           
ge=TZ%10;                             //integer Entries bit                                                                                                                            
shi=TZ/10;                            //integer ten bit                                                                                                                                
wd=0;                                                                                                                                                                                  
if (TX & 0x80) wd=wd+5000;
if (TX & 0x40) wd=wd+2500;
if (TX & 0x20) wd=wd+1250;
if (TX & 0x10) wd=wd+625;                //hereinbefore four instructions are turn  decimal into BCD code                         
shifen=wd/1000;                          //ten cent bit                                                                     
NOP();                                                                                                                            
}                                                                                                                                 
 
void temp_setting(){
    writecmd_4line(0x1);               //clr screen
    writecmd_4line(0x80);
    write_str("Temp Threshold");
    writecmd_4line(0x90);
    write_str("Day");
    writecmd_4line(0x88);
    write_str("Night");
    
    for (;;){
        
        //Return to home screen/main function
        if (OutputPins(),FirstRC == 2 && SecondRC == 1){
            return;
        }
        
        //Menu Right / Day Temp
        else if (OutputPins(),FirstRC == 3 && SecondRC == 1){
            button_reset();
            set_day();
        }
        
        //Menu Left / Night Temp
        else if (OutputPins(),FirstRC == 4 && SecondRC == 1){
            button_reset();
            set_night();
        }
    }
}   

void set_day(){
    writecmd_4line(0x1);
    writecmd_4line(0x80);
    write_str("Day Settings");
    writecmd_4line(0x90);
    write_str("Max:");
    writechar(day_ten_max + '0');
    writechar(day_one_max + '0');
    write_str(".");
    writechar(day_dec_max + '0');
    writecmd_4line(0x88);
    write_str("Min:");
    writechar(day_ten_min + '0');
    writechar(day_one_min + '0');
    write_str(".");
    writechar(day_dec_min + '0');
    
    unsigned int min_max = 0;
    
    for (;;){
        
        
        if (OutputPins(),FirstRC == 2 && SecondRC == 1){
            button_reset();
            return;
        }
        
        //Select Max
        else if (OutputPins(),FirstRC == 3 && SecondRC == 1){
            button_reset();
            writecmd_4line(0x90);
            write_str("          ");
            writecmd_4line(0x90);
            write_str("Max:");
            writechar(day_ten_max + '0');
            writechar(day_one_max + '0');
            write_str(".");
            writechar(day_dec_max + '0');
            
            min_max = 0;
            
        }
        
        //Select Min
        else if (OutputPins(),FirstRC == 4 && SecondRC == 1){
            button_reset();
            writecmd_4line(0x88);
            write_str("          ");
            writecmd_4line(0x88);
            write_str("Min:");
            writechar(day_ten_min + '0');
            writechar(day_one_min + '0');
            write_str(".");
            writechar(day_dec_min + '0');
            
            min_max = 1;
        }
        
        //Increment button
        else if (OutputPins(),FirstRC == 4 && SecondRC == 2){
            button_reset();
            if (min_max == 0){
                
                temp_ten = day_ten_max; temp_one = day_one_max; temp_dec = day_dec_max;
                
                temp_increment();
                
                day_ten_max = temp_ten; day_one_max = temp_one; day_dec_max = temp_dec;
                
                writecmd_4line(0x92);
                writechar(day_ten_max + '0');
                writechar(day_one_max + '0');
                write_str(".");
                writechar(day_dec_max + '0');
            }
            else if (min_max == 1){
                
                temp_ten = day_ten_min; temp_one = day_one_min; temp_dec = day_dec_min;
                
                temp_increment();
                
                day_ten_min = temp_ten; day_one_min = temp_one; day_dec_min = temp_dec;
                
                writecmd_4line(0x8A);
                writechar(day_ten_min + '0');
                writechar(day_one_min + '0');
                write_str(".");
                writechar(day_dec_min + '0');
            }
        } 
        
        //Decrement button
        else if (OutputPins(),FirstRC == 3 && SecondRC == 2){
            button_reset();
            if (min_max == 0){
                
                temp_ten = day_ten_max; temp_one = day_one_max; temp_dec = day_dec_max;
                
                temp_decrement();
                
                day_ten_max = temp_ten; day_one_max = temp_one; day_dec_max = temp_dec;
                
                writecmd_4line(0x92);
                writechar(day_ten_max + '0');
                writechar(day_one_max + '0');
                write_str(".");
                writechar(day_dec_max + '0');
            }
            else if (min_max == 1){
                
                temp_ten = day_ten_min; temp_one = day_one_min; temp_dec = day_dec_min;
                
                temp_decrement();
                
                day_ten_min = temp_ten; day_one_min = temp_one; day_dec_min = temp_dec;
                
                writecmd_4line(0x8A);
                writechar(day_ten_min + '0');
                writechar(day_one_min + '0');
                write_str(".");
                writechar(day_dec_min + '0');
            }
        }
    }
}   

void set_night(){
    writecmd_4line(0x1);
    writecmd_4line(0x80);
    write_str("Night Settings");
    writecmd_4line(0x90);
    write_str("Max:");
    writechar(night_ten_max + '0');
    writechar(night_one_max + '0');
    write_str(".");
    writechar(night_dec_max + '0');
    writecmd_4line(0x88);
    write_str("Min:");
    writechar(night_ten_min + '0');
    writechar(night_one_min + '0');
    write_str(".");
    writechar(night_dec_min + '0');
    
    unsigned int min_max = 0;
    
    for (;;){
        
        if (OutputPins(),FirstRC == 2 && SecondRC == 1){
            button_reset();
            return;
        }
        
        //Select Max
        else if (OutputPins(),FirstRC == 3 && SecondRC == 1){
            button_reset();
            writecmd_4line(0x90);
            write_str("          ");
            writecmd_4line(0x90);
            write_str("Max:");
            writechar(night_ten_max + '0');
            writechar(night_one_max + '0');
            write_str(".");
            writechar(night_dec_max + '0');
            
            min_max = 0;
            
        }
        
        //Select Min
        else if (OutputPins(),FirstRC == 4 && SecondRC == 1){
            button_reset();
            writecmd_4line(0x88);
            write_str("          ");
            writecmd_4line(0x88);
            write_str("Min:");
            writechar(night_ten_min + '0');
            writechar(night_one_min + '0');
            write_str(".");
            writechar(night_dec_min + '0');
            
            min_max = 1;
        }
        
        //Increment button
        else if (OutputPins(),FirstRC == 4 && SecondRC == 2){
            button_reset();
            if (min_max == 0){
                
                temp_ten = night_ten_max; temp_one = night_one_max; temp_dec = night_dec_max;
                
                temp_increment();
                
                night_ten_max = temp_ten; night_one_max = temp_one; night_dec_max = temp_dec;
                
                writecmd_4line(0x92);
                writechar(night_ten_max + '0');
                writechar(night_one_max + '0');
                write_str(".");
                writechar(night_dec_max + '0');
            }
            else if (min_max == 1){
                
                temp_ten = night_ten_min; temp_one = night_one_min; temp_dec = night_dec_min;
                
                temp_increment();
                
                night_ten_min = temp_ten; night_one_min = temp_one; night_dec_min = temp_dec;
                
                writecmd_4line(0x8A);
                writechar(night_ten_min + '0');
                writechar(night_one_min + '0');
                write_str(".");
                writechar(night_dec_min + '0');
            }
        } 
        
        //Decrement button
        else if (OutputPins(),FirstRC == 3 && SecondRC == 2){
            button_reset();
            if (min_max == 0){
                
                temp_ten = night_ten_max; temp_one = night_one_max; temp_dec = night_dec_max;
                
                temp_decrement();
                
                night_ten_max = temp_ten; night_one_max = temp_one; night_dec_max = temp_dec;
                
                writecmd_4line(0x92);
                writechar(night_ten_max + '0');
                writechar(night_one_max + '0');
                write_str(".");
                writechar(night_dec_max + '0');
            }
            else if (min_max == 1){
                
                temp_ten = night_ten_min; temp_one = night_one_min; temp_dec = night_dec_min;
                
                temp_decrement();
                
                night_ten_min = temp_ten; night_one_min = temp_one; night_dec_min = temp_dec;
                
                writecmd_4line(0x8A);
                writechar(night_ten_min + '0');
                writechar(night_one_min + '0');
                write_str(".");
                writechar(night_dec_min + '0');
            }
        }
    }
}
   
void temp_increment(){
    //If temp == 40C
    if (temp_ten != 4){

        //Decimal 
        if (temp_dec == 9){
            temp_dec = 0;

            //Ones 
            if (temp_one == 9){
                temp_one = 0;

                //Tens
                temp_ten++;
                delay_main();
            }
            else {
                temp_one++;
                delay_main();
            }
        }
        else {
            temp_dec++;
            delay_main();
        }
    }
    else {
        delay_main();
    }
}

void temp_decrement(){
    unsigned int end = 0;

    if (temp_ten == 1){
        end++;
        if (temp_one == 5){
            end++;
            if (temp_dec == 0){
                end++;
            }
        }
    }
    
    if (end != 3){

        //Decimal 
        if (temp_dec == 0){
            temp_dec = 9;

            //Ones 
            if (temp_one == 0){
                temp_one = 9;

                //Tens
                temp_ten--;
                delay_main();
            }
            else {
                temp_one--;
                delay_main();
            }
        }
        else {
            temp_dec--;
            delay_main();
        }
    }

    else{
        delay_main();
    }
}

void temp_day(){
    unsigned int temp = shi*100 + ge*10 + shifen;
    unsigned int temp_max = day_ten_max*100 + day_one_max*10 + day_dec_max;
    unsigned int temp_min = day_ten_min*100 + day_one_min*10 + day_dec_min;
    if (temp > temp_max){
        cool();
    }
    else if (temp < temp_min){
        heat();
    }
    else if (temp <= temp_max){
        if (temp >= temp_min){
            OK();
        }
    }
}

void temp_night(){
    unsigned int temp = shi*100 + ge*10 + shifen;
    unsigned int temp_max = night_ten_max*100 + night_one_max*10 + night_dec_max;
    unsigned int temp_min = night_ten_min*100 + night_one_min*10 + night_dec_min;
    if (temp > temp_max){
        cool();
    } 
    else if (temp < temp_min){
        heat();
    }
    else if (temp <= temp_max){
        if (temp >= temp_min){
            OK();
        }
    }
}

void cool(){
    writecmd_4line(0x9E);
    write_str("Cool");
    temp_check_lower();
    if (buzz_count == 20 && pass == 0){
        buzzer = 1;
    }
}

void heat(){
    writecmd_4line(0x9E);
    write_str("Heat ");
    temp_check_rise();
    if (buzz_count == 20 && pass == 0){
        buzzer = 1;
    }
}

void OK(){
    writecmd_4line(0x9E);
    write_str("OK  ");
    buzz_count = 0;
    pass = 0;
    buzzer = 0;
}

void temp_check_lower(){
    
    if (temp_sec%2 == 0){
        temp_p = shi*100 + ge*10 + shifen;
    }
    else if (temp_sec%2 != 0){
        unsigned char temp_e = shi*100 + ge*10 + shifen;
        if (temp_p > temp_e){
                buzz_count = 0;
                buzzer = 0;
        }
        else if (temp_p == temp_e){
           buzz_count++; 
        }
        else {
            buzz_count++;
        }
    }
}

void temp_check_rise(){
    if (temp_sec%2 == 0){
        temp_p = shi*100 + ge*10 + shifen;
    }
    else if (temp_sec%2 != 0){
        unsigned char temp_e = shi*100 + ge*10 + shifen;
        if (temp_p < temp_e){
            buzz_count = 0;
            buzzer = 0;
        }
        else if (temp_p == temp_e){
            buzz_count++;
            
        }
        else {
            buzz_count++;
        }
    }
}
