;--------------------------------------
    ;CONFIGURACION DE PUERTOS
;--------------------------------------
CONFIGURACION:
    BANKSEL  OSCCON 
    MOVLW    B'01110001'
    MOVWF OSCCON

    BANKSEL  TRISD
    MOVLW    0XFF
    MOVWF    TRISA
    CLRF     TRISD
    CLRF     TRISC
    MOVLW    0X0E
    MOVWF    TRISE
    BANKSEL  ANSEL
    CLRF     ANSEL

    BANKSEL  PORTD
    CLRF     PORTA
    CLRF     PORTC
    CLRF     PORTD
    CLRF     PORTE
    
    BCF STATUS,RP0
    BCF STATUS,RP1
    RETURN


