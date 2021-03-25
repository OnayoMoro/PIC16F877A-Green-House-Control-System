#INCLUDE<P16F877A.INC>           
__CONFIG _DEBUG_OFF&_CP_ALL&_WRT_HALF&_CPD_ON&_LVP_OFF&_BODEN_OFF&_PWRTE_ON&_WDT_OFF&_HS_OSC  
bit_1 equ 01h
bit_2 equ 02h
bit_4 equ 04h
bit_8 equ 08h
bit_16 equ 010h
bit_32 equ 020h
bit_64 equ 040h
bit_128 equ 080h
 
; Predefined values  
outer_delay   equ   0ffh
inner_delay   equ   0ffh  
 
ORG    00H                      ;Program entry point 
main
    clrf PORTC
    clrf PORTB
    clrf PORTA
    banksel TRISC 
    banksel TRISB
    banksel TRISA
    clrf TRISC
    clrf TRISB
    clrf TRISA
    clrf STATUS
    
    loop
    movlw bit_1
    movwf PORTC
    call delay
    
    movlw bit_1
    movwf PORTB
    call delay
    
    movlw bit_1
    movwf PORTA
    call delay
    
    movlw bit_2
    movwf PORTC
    call delay
    
    movlw bit_2
    movwf PORTB
    call delay
    
    movlw bit_2
    movwf PORTA
    call delay
    
    movlw bit_4
    movwf PORTC
    call delay
    
    movlw bit_4
    movwf PORTB
    call delay
    
    movlw bit_4
    movwf PORTA
    call delay
    
    movlw bit_8
    movwf PORTC
    call delay
    
    movlw bit_8
    movwf PORTB
    call delay
    
    movlw bit_8
    movwf PORTA
    call delay

    movlw bit_16
    movwf PORTC
    call delay
    
    movlw bit_16
    movwf PORTB
    call delay
    
    movlw bit_16
    movwf PORTA
    call delay
    
    movlw bit_32
    movwf PORTC
    call delay
    
    movlw bit_32
    movwf PORTB
    call delay
    
    movlw bit_32
    movwf PORTA
    call delay
    
    movlw bit_64
    movwf PORTC
    call delay
    
    movlw bit_64
    movwf PORTB
    call delay
    
    movlw bit_64
    movwf PORTA
    call delay
    
    movlw bit_128
    movwf PORTC
    call delay
    
    movlw bit_128
    movwf PORTB
    call delay
    
    movlw bit_128
    movwf PORTA
    call delay
    goto loop
    
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
    


