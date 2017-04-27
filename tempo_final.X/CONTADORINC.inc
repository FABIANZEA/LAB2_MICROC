;--------------------------------------
    ;RUTINA DE SALIDA TEMPORIZADOR CUANDO VA CONTANDO NEGATIVAMENTE
    ;Y CUENTA HASTA QUE SE DE UN PULSO DE ENTRADA
    ;EN LOS DISPLAYS DESTINADOS A HORAS SE PODRA OBSERVAR UN SIGNO DE MENOS
;--------------------------------------
    
;--------------------------------------
    ;INICIALIZA LOS REGISTROS DE SEGUNDOS EN 1 Y MINUTOS EN 0
;--------------------------------------
CONTADORINC:
    CLRF   CONTEO2
    CLRF   PORTC
    CLRF   PORTD
    CLRF   REGOP
    CLRF   CONTEO2
    MOVLW  VENTANASEG
    MOVWF  FSR
    MOVLW  .1
    MOVWF  INDF
    INCF   FSR
    MOVLW  .0
    MOVWF  INDF
;--------------------------------------
    ;CONVIERTE EN BCD LOS VALORES DE LOS REGISTROS DE SEGUNDOS Y MINUTOS
;--------------------------------------
BBB:
    CALL   CONVERSOR1   
    CALL   CONVERSOR2
;--------------------------------------
    ;VIZUALIZA EN EL PUERTO D LOS VALORES SEGUNDOS Y MINUTOS
    ;ROTA EL PUERTO C PARA SELECCIONAR QUE DISPLAY ENCENDER
;--------------------------------------  
SEGUNDOS1:
    CLRF   PORTC
    CLRF   PORTD
    BSF    PORTC,RC0
    MOVF   SALIDABSEG,W
    CALL   TABLA
    MOVWF  PORTD
    CALL   RETARDO1
    CLRF   PORTD
    RLF    PORTC
    MOVF   SALIDAASEG,W
    CALL   TABLA
    MOVWF  PORTD
    CALL   RETARDO1
MINUTOS1:  
    CLRF   PORTD
    RLF    PORTC
    MOVF   SALIDABMIN,W
    CALL   TABLA
    MOVWF  PORTD
    CALL   RETARDO1
    CLRF   PORTD
    RLF    PORTC
    MOVF   SALIDAAMIN,W
    CALL   TABLA
    MOVWF  PORTD
    CALL   RETARDO1
    
;--------------------------------------
    ;LOS DIPLAYS DE HORA SE OBSERVARA SIGNO NEGATIVO
    ;INDICANDO QUE LA TEMPORIZADOR ESTA EN SECUENCIA NEGATIVA
;-------------------------------------- 
HORA1:
    CLRF   PORTD
    RLF    PORTC
    MOVLW  0X01
    MOVWF  PORTD
    CALL   RETARDO1
    CLRF   PORTD
    RLF    PORTC
    MOVLW  0X01
    MOVWF  PORTD
    CALL   RETARDO1
    
;--------------------------------------
    ;TERMINA EL CONTEO NEGATIVO Y RETORNA AL PROGRAMA PRINCIPAL
    ;SI SE OPRIME EL PULSADOR
;-------------------------------------- 

    BTFSS  PORTE,RE1
    GOTO   $+2
    GOTO   SALIR
    
;--------------------------------------
    ;EL REGISTRO CONTEO2 VA INCREMENTANDO HASTA EL VALOR 100
    ; SI ESTE REGISTRO ES MENOR QUE 100 VUELVE A MOSTRAR LOS MISMOS NUMEROS 
    ;SIN NINGUN CAMBIO
;-------------------------------------- 
    
    INCF   CONTEO2
    MOVLW  .100
    XORWF  CONTEO2,W
    BTFSS  STATUS,Z
    GOTO   SEGUNDOS1
;------------------------------------------
    ;INCREMENTA EL VALOR DE SEGUNDO
    ;SI LLEGA A 59 TOMA EL VALOR DE 0
    ;Y SALTA A INCREMENTAR LOS MINUTOS    
;-------------------------------------------
    
    MOVLW  VENTANASEG
    MOVWF  FSR
    MOVLW  .59
    MOVWF  REGOP
    XORWF  VENTANASEG,W
    BTFSC  STATUS,Z
    GOTO   $+3
    INCF   VENTANASEG
    GOTO   BBB
    MOVLW  VENTANASEG
    MOVWF  FSR
    CLRF   INDF
;------------------------------------------
    ;INCREMENTA EL VALOR DE MINUTOS
    ;SI LLEGA A 59 TOMA EL VALOR DE 0   
;-------------------------------------------
    INCF   FSR
    MOVLW  .59
    MOVWF  REGOP
    XORWF  VENTANAMIN,W
    BTFSC  STATUS,Z
    GOTO   $+3
    INCF   INDF
    GOTO   BBB
    MOVLW  VENTANAMIN
    MOVWF  FSR
    CLRF   INDF
SALIR:
    RETURN


