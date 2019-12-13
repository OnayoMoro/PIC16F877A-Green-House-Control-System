#include <xc.h>
#include "button_press_header.h"

void initialisation () {
    ADCON1 = 0X07; //A port as ordinary i/o as digital
    TRISC = 0xF0; //First 4 pins set as output, last 4 set as inputs
    PORTC = 0x00;
}
// Output pins = column pins that send signal throughout matrix 
//Setting column pins high one by one 
void OutputPins (){
    //int OutputRC;
    PORTCbits.RC0 = 1;      //Turn RC0 on 
    OutputRC = 1;           //Indicating RC0 is on 
    InputPins(OutputRC);    //Check which input pins received RC0's signal 
    PORTCbits.RC0 = 0;      //Turn RC0 off
    
    PORTCbits.RC1 = 1;      //Turn RC1 on
    OutputRC = 2;           //Indicating RC1 is on 
    InputPins(OutputRC);    //Check which input pins received RC1's signal    
    PORTCbits.RC1 = 0;      //Turn RC1 off

    PORTCbits.RC2 = 1;      //Turn RC2 on
    OutputRC = 3;           //Indicating RC2 is on 
    InputPins(OutputRC);    //Check which input pins received RC2's signal  
    PORTCbits.RC2 = 0;      //Turn RC2 off
    
    PORTCbits.RC3 = 1;      //Turn RC3 on
    OutputRC = 4;           //Indicating RC3 is on 
    InputPins(OutputRC);    //Check which input pins received RC3's signal  
    PORTCbits.RC3 = 0;      //Turn RC3 off
}

//Input pins = row pins that will read the signal of the column/output pins
//Will send the no. of both input & ouput pins through a method to then be used elsewhere
void InputPins (unsigned int RC){
    
    if (PORTCbits.RC4 == 1){
        SecondRC = 1;
        FirstRC = RC;
        //LightUp(OutputRC,SecondRC);     
    } 
    else if (PORTCbits.RC5 == 1){
        SecondRC = 2;
        FirstRC = RC;
        //LightUp(OutputRC,SecondRC);      
    } 
    else if (PORTCbits.RC6 == 1){
        SecondRC = 3;
        FirstRC = RC;
        //LightUp(OutputRC,SecondRC);        
    } 
    else if (PORTCbits.RC7 == 1){
        SecondRC = 4;
        FirstRC = RC;
        //LightUp(OutputRC,SecondRC);
    } 
}

void button_reset(){
    SecondRC = 0;
    FirstRC = 0;
    OutputRC = 0;
}