;--------------------------------------------------------
    ;RUTINA QUE MUESTRA UN MENSAJE "ESPERA" AL TERMINAR DE MOSTRAR 
    ;EL MENSAJE DE 30 CARACTERES EL PROGRAMA SE QUEDA EN ESTA RUTINA 
    ;HASTA QUE SE OPRIMA EL PULSADOR Y SE REINICI EL PROGRAMA
;-----------------------------------------------------
ESPERA:
    CLRF  REG6
    CLRF  PORTC 
    CLRF  PORTD
    BSF   PORTC,0
LLAMAR:    
    MOVF  REG6,W
    CALL  TABLAESPERA
    MOVWF PORTD
    CALL  RETARDO1
    BTFSC PORTE,RE1
    GOTO  TERMINAR
    CLRF  PORTD
    RLF   PORTC
    INCF  REG6
    MOVLW 0X06
    XORWF REG6,W
    BTFSS STATUS,Z
    GOTO  LLAMAR
    GOTO  ESPERA 
TERMINAR:
    RETURN