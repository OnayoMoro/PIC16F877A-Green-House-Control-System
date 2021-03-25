#INCLUDE<P16F877A.INC>           
__CONFIG _DEBUG_OFF&_CP_ALL&_WRT_HALF&_CPD_ON&_LVP_OFF&_BODEN_OFF&_PWRTE_ON&_WDT_OFF&_HS_OSC
    
    ; Predefined values  
    outer_delay   equ   0ffh
   inner_delay   equ   0afh               
   
   org      00h                   
   main   
   clrf     PORTC  
   banksel  TRISC     
   clrf     TRISC     
   clrf     STATUS     
   
   loop                
   incf     PORTC     
   call     delay     
   goto     loop       
   
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


