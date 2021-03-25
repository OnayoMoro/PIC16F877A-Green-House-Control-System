#INCLUDE<P16F877A.INC>           
__CONFIG _DEBUG_OFF&_CP_ALL&_WRT_HALF&_CPD_ON&_LVP_OFF&_BODEN_OFF&_PWRTE_ON&_WDT_OFF&_HS_OSC
    
    ; Predefined values  
    outer_delay   equ   0ffh
   inner_delay   equ   0ffh  
   bit_1 equ 01h
    count equ 20h
     
org 00h
   main   
   clrf     PORTC  
   clrf	    PORTB
   banksel  TRISC
   clrf     TRISC
   banksel  TRISB
   clrf     TRISB
   clrf     STATUS     
   
   movlw bit_1
   movwf PORTC
   call delay
   
   movlw bit_1
   movwf PORTB
   call delay
   
   loop
   rlf PORTC
   call delay 
   goto pb
   
   pb
   rlf PORTB
   call delay
   decfsz count,1
   goto loop
   goto
   
; Delay loops 
delay   
   movlw    outer_delay    
   movwf    30h 
   
outer_loop        
   movlw    inner_delay   
   movwf    31h
   
inner_loop   
   decfsz   31h,1   
   goto     inner_loop     
   
   decfsz   30h,1   
   goto    outer_loop  
   return    
   end
    
    
    
    













