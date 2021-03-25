#INCLUDE<P16F877A.INC>           
__CONFIG _DEBUG_OFF&_CP_ALL&_WRT_HALF&_CPD_ON&_LVP_OFF&_BODEN_OFF&_PWRTE_ON&_WDT_OFF&_HS_OSC

     ; Predefined values  
    outer_delay   equ   0ffh
   inner_delay   equ   0afh 
   countnum equ 0xff
   countdigit equ 
    
    ;Output numbers for the display
    number0 equ 0xC0
    number1 equ 0xF9
    number2 equ 0xA4
    number3 equ 0xB0
    number4 equ 0x99
    number5 equ 0x92
    number6 equ 0x82
    number7 equ 0xF8
    number8 equ 0x80
    number9 equ 0x90 
    
    ;PORTA multiplex
    digitall equ 0x00
    digit1 equ 0xFE
    digit2 equ 0xFD
    digit3 equ 0xFB
    digit4 equ 0xF7
    digit5 equ 0xEF
    digit6 equ 0xDF
   
    
 org 00h
    main 
    clrf PORTA 
    clrf PORTD
    movlw 0x06
    movwf ADCON1
    banksel TRISA
    clrf TRISA
    banksel TRISD
    clrf TRISD
    clrf STATUS
    banksel PORTA
    
    loop
    movlw 0xDE
    movwf PORTA
    digital_1
    movlw number0
    mov
    goto main
    
    
    
;    loop
;    movlw 0xfe    ;Display the digit on the 
;    movwf PORTA	    ;first segment display
;    movlw 0xf9
;    movwf PORTD
;    call delay 
;    call delay
;    call delay
;    movlw 0xfd
;    movwf PORTA 
;    movlw 0xa4
;    movwf PORTD
;    call delay
;    call delay
;    call delay
;    goto loop
    
;    loop 
;    movlw digit1
;    movwf PORTA
;    digit1_count
;    movlw number0
;    movwf PORTD
;    call delay
;    call delay
;    movlw number1
;    movwf PORTD
;    call delay
;    call delay
;    movlw number2
;    movwf PORTD
;    call delay
;    call delay
;    movlw number3
;    movwf PORTD
;    call delay
;    call delay
;    movlw number4
;    movwf PORTD
;    call delay
;    call delay
;    movlw number5
;    movwf PORTD
;    call delay
;    call delay
;    movlw number6
;    movwf PORTD
;    call delay
;    call delay
;    movlw number7
;    movwf PORTD
;    call delay
;    call delay
;    movlw number8
;    movwf PORTD
;    call delay
;    call delay
;    movlw number9
;    movwf PORTD
;    call delay
;    call delay
;    digit2_count 
;    movlw 0xFC
;    movwf PORTA
; 
;    goto main
   
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
    