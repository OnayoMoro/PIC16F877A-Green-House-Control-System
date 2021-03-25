#INCLUDE<P16F877A.INC>           
__CONFIG _DEBUG_OFF&_CP_ALL&_WRT_HALF&_CPD_ON&_LVP_OFF&_BODEN_OFF&_PWRTE_ON&_WDT_OFF&_HS_OSC  

ORG    00H                      ;Program entry point 
BSF     STATUS,RP0		;select BANK1 
MOVLW   1FBH                    ;set PORT C bit 0 to OUTPUT, the other bits INPUT 
MOVWF   TRISB                   
BCF     STATUS,RP0              ;select BANK0 
BSF     PORTB,2                 ;Set port C bit 0 high (should light the LED)
LOOP
GOTO	LOOP			;enter an infinite loop 
END                             ;program end





