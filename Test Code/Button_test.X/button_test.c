#include <xc.h>
//begin config
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = ON // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV onMCLR must be used for programming)
//end config

//--------------------
//Turn on the first set of switches closest to LCD sockets
//Leave the others alone (they'll interfere otherwise)
//------------
void initialisation ();
void OutputPins ();
void InputPins (int RC);
void LightUp(int ORC , int IRC);

void delay(){
    int i;
    for(i=0;i<2500;i++);
}

void initialisation () {
    ADCON1 = 0X07; //A port as ordinary i/o as digital
    TRISA = 0x00; // Set Port A as outputs
    TRISB = 0x00; // Set Port B as outputs
    TRISC = 0xF0; //First 4 pins set as output, last 4 set as inputs
    PORTA = 0x00;
    PORTB = 0x00;
    PORTC = 0x00;
}
// Output pins = column pins that send signal throughout matrix 
//Setting column pins high one by one 
void OutputPins (){
    int OutputRC;
    PORTCbits.RC0 = 1;      //Turn RC0 on 
    OutputRC = 0;           //Indicating RC0 is on 
    InputPins(OutputRC);    //Check which input pins received RC0's signal 
    PORTCbits.RC0 = 0;      //Turn RC0 off
    
    PORTCbits.RC1 = 1;      //Turn RC1 on
    OutputRC = 1;           //Indicating RC1 is on 
    InputPins(OutputRC);    //Check which input pins received RC1's signal    
    PORTCbits.RC1 = 0;      //Turn RC1 off

    PORTCbits.RC2 = 1;      //Turn RC2 on
    OutputRC = 2;           //Indicating RC2 is on 
    InputPins(OutputRC);    //Check which input pins received RC2's signal  
    PORTCbits.RC2 = 0;      //Turn RC2 off
    
    PORTCbits.RC3 = 1;      //Turn RC3 on
    OutputRC = 3;           //Indicating RC3 is on 
    InputPins(OutputRC);    //Check which input pins received RC3's signal  
    PORTCbits.RC3 = 0;      //Turn RC3 off
}

//Input pins = row pins that will read the signal of the column/output pins
//Will send the no. of both input & ouput pins through a method to then be used elsewhere
void InputPins (int RC){
    int InputRC;
    int OutputRC = RC;
    
    if (PORTCbits.RC4 == 1){
        InputRC = 4;
        LightUp(OutputRC,InputRC);     
    } 
    else if (PORTCbits.RC5 == 1){
        InputRC = 5;
        LightUp(OutputRC,InputRC);      
    } 
    else if (PORTCbits.RC6 == 1){
        InputRC = 6;
        LightUp(OutputRC,InputRC);        
    } 
    else if (PORTCbits.RC7 == 1){
        InputRC = 7;
        LightUp(OutputRC,InputRC);
    } 
}

void LightUp(int ORC , int IRC){
    switch(ORC)
    {
        case 0:
            if (IRC == 4){
                //button K13
               PORTA = 0x10;
                break;
            }
            else if (IRC == 5){
                //button K17
                PORTA = 0x20;
                break;
            }
            else if (IRC == 6){
                //button K21
               PORTA = 0x40;
                break;
            }
            else if (IRC == 7){
                //button K 25
               PORTA = 0x80;
                break;
            }
            else{
                //if something's wrong, light this up
               PORTB = 0x04;
               break;
            }
        case 1:
            if (IRC == 4){
                //button K12
               PORTA = 0x01;
                break;
            }
            else if (IRC == 5){
                //button K16
                PORTA = 0x02;
                break;
            }
            else if (IRC == 6){
                //button K20
               PORTA = 0x04;
                break;
            }
            else if (IRC == 7){
                //button K24
                 PORTA = 0x08;
                break;
            }
            else{
               PORTB = 0x08; 
               break;
            }
        case 2:
            if (IRC == 4){
                //button K11
               PORTB = 0x10;
                break;
            }
            else if (IRC == 5){
                //button K15
                PORTB = 0x20;
                break;
            }
            else if (IRC == 6){
                //button K19
               PORTB = 0x40;
                break;
            }
            else if (IRC == 7){
                //button K 23
               PORTB = 0x80;
                break;
            }
            else{
               PORTA = 0x04;
               break;
            }
        case 3:
            if (IRC == 4){
                //button K10
               PORTB = 0x01;
                break;
            }
            else if (IRC == 5){
                //button K14
                PORTB = 0x02;
                break;
            }
            else if (IRC == 6){
                //button K18
               PORTB = 0x04;
                break;
            }
            else if (IRC == 7){
                //button K22
                 PORTB = 0x08;
                break;
            }
            else{
               PORTA = 0x08; 
               break;
            }
                
    }
}

void main (){
    initialisation();
    for (;;){
       OutputPins(); 
       }
    }






















//#include <xc.h>
//#include "button_press_header.h"
//
//
//void initialisation () {
//    ADCON1 = 0X07; //A port as ordinary i/o as digital
//    TRISC = 0xF0; //First 4 pins set as output, last 4 set as inputs
//    PORTC = 0x00;
//}
//
//void delay_buttons(){
//    for(int i=0;i<500;i++);
//}
//
//// Output pins = column pins that send signal throughout matrix 
////Setting column pins high one by one 
//int FirstRC1(){
//    PORTCbits.RC0 = 1;      //Turn RC0 on 
//    OutputRC = 1;           //Indicating RC0 is on 
//    InputPins();    //Check which input pins received RC0's signal 
//    PORTCbits.RC0 = 0;      //Turn RC0 off
//    return 1;
//}
//
//int FirstRC2 (){
//    PORTCbits.RC1 = 1;      //Turn RC1 on
//    OutputRC = 2;           //Indicating RC1 is on 
//    InputPins();    //Check which input pins received RC1's signal    
//    PORTCbits.RC1 = 0;      //Turn RC1 off
//    return 2;
//}
//
//int FirstRC3 (){
//    PORTCbits.RC2 = 1;      //Turn RC2 on
//    OutputRC = 3;           //Indicating RC2 is on 
//    InputPins();    //Check which input pins received RC2's signal  
//    PORTCbits.RC2 = 0;      //Turn RC2 off
//    return 3;
//}
//
//int FirstRC4(){
//    PORTCbits.RC3 = 1;      //Turn RC3 on
//    OutputRC = 4;           //Indicating RC3 is on 
//    InputPins();    //Check which input pins received RC3's signal  
//    PORTCbits.RC3 = 0;      //Turn RC3 off
//    return 4;
//}
//
////Input pins = row pins that will read the signal of the column/output pins
////Will send the no. of both input & ouput pins through a method to then be used elsewhere
//void InputPins(){
//    
//    if (PORTCbits.RC4 == 1){
//        SecondRC = 1;
//        FirstRC = OutputRC;
//    } 
//    else if (PORTCbits.RC5 == 1){
//        SecondRC = 2;
//        FirstRC = OutputRC;
//    } 
//    else if (PORTCbits.RC6 == 1){
//        SecondRC = 3;
//        FirstRC = OutputRC;
//    } 
//    else if (PORTCbits.RC7 == 1){
//        SecondRC = 4;
//        FirstRC = OutputRC;
//    } 
//}
















//       if (FirstRC1() == 1 && SecondRC == 4){
//           //k25 pressed
//           SecondRC = 0;
//           FirstRC = 0;
//           OutputRC = 0;
//           writecmd_4line(0x80);
//           yeet("1.4!");
//           delay_buttons();
//       }
//       else if (FirstRC2() == 2 && SecondRC == 1){
//           //k12
//           SecondRC = 0;
//       FirstRC = 0;
//       OutputRC = 0;
//           writecmd_4line(0x80);
//           yeet("2.1!");
//       }  
//       else if (FirstRC2() == 2 && SecondRC == 4){
//           //k24
//           SecondRC = 0;
//       FirstRC = 0;
//       OutputRC = 0;
//           writecmd_4line(0x80);
//           yeet("2.4!");
//       }
//       else if (FirstRC3() == 3 && SecondRC == 1){
//           //k11
//           SecondRC = 0;
//       FirstRC = 0;
//       OutputRC = 0;
//           writecmd_4line(0x80);
//           yeet("3.1!");
//       }
//       else if (FirstRC3() == 3 && SecondRC == 4){
//           //k22
//           SecondRC = 0;
//       FirstRC = 0;
//       OutputRC = 0;
//           writecmd_4line(0x80);
//           yeet("3.4!");
//       }
//       else if (FirstRC4() == 4 && SecondRC == 3){
//           //k18
//           SecondRC = 0;
//       FirstRC = 0;
//       OutputRC = 0;
//           writecmd_4line(0x80);
//           yeet("4.3!");
//        }