;--------------------------------------
    ;RUTINA DE SALIDA TEMPORIZADOR CUANDO VA DECREMENTEANDO
    ;DESDE EL VALOR INICIAL HASTA LLEGAR A 0
;--------------------------------------
CONTADORDEC:
;--------------------------------------
    ;LLAMA RUTINA PARA ESCOJER EL TIEMPO DE TEMPORIZACION 
;--------------------------------------
    CALL T_ESCOGER
    CLRF   CONTEO2
AAA:
;--------------------------------------
    ;LLAMA RUTINA PARA CONERSION DE LOS TIEMPOS HA VALORES EN BCD PARA
    ;LA RESPECTIVA VIZUALIZACION
    ;CONVERSOR 1 PARA SEGUNDOS
    ;CONVERSOR DOS PARA MINUTOS
    ;CONVERSOR 3 PARA HORAS
;--------------------------------------
    CALL   CONVERSOR1   
    CALL   CONVERSOR2
    CALL   CONVERSOR3
 
;--------------------------------------
    ;SACA AL PUERTO D LOS DIFERENTES VALORES DE CADA DISPLAY
    ;Y VA ROTANDO EL PUERTO C PARA ESCOJER EL ENCENDIDO DE CADA DISPLAY
;--------------------------------------
SEGUNDOS:
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
MINUTOS:  
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
HORA:
    CLRF   PORTD
    RLF    PORTC
    MOVF   SALIDABHOR,W
    CALL   TABLA
    MOVWF  PORTD
    CALL   RETARDO1
    CLRF   PORTD
    RLF    PORTC
    MOVF   SALIDAAHOR,W
    CALL   TABLA
    MOVWF  PORTD
    CALL   RETARDO1
;--------------------------------------
    ;EL REGISTRO CONTEO2 VA INCREMENTANDO HASTA EL VALOR 100
    ; SI ESTE REGISTRO ES MENOR QUE 100 VUELVE A MOSTRAR LOS MISMOS NUMEROS 
    ;SIN NINGUN CAMBIO
;--------------------------------------
    
    INCF   CONTEO2
    MOVLW  .100
    XORWF  CONTEO2,W
    BTFSS  STATUS,Z
    GOTO   SEGUNDOS
;--------------------------------------
    ;DECREMENTA EL VALOR DE SEGUNDO
    ;SI LLEGA A 0 TOMA EL VALOR DE 59
    ;Y SALTA A DECREMNETAR LOS MINUTOS
;--------------------------------------   
    MOVF   VENTANASEG,W
    BTFSC  STATUS,Z
    GOTO   $+3
    DECF   VENTANASEG
    GOTO   AAA
    MOVLW  VENTANASEG
    MOVWF  FSR
    MOVLW  .59
    MOVWF  INDF
;    -----------------------------------
    ;DECREMENTA EL VALOR DE MINUTOS
    ;SI LLEGA A 0 TOMA EL VALOR DE 59
    ;Y SALTA A DECREMENTAR LOS HORAS
;-------------------------------------- 
    INCF   FSR
    MOVF   VENTANAMIN,W
    BTFSC  STATUS,Z
    GOTO   $+3
    DECF   INDF
    GOTO   AAA
    MOVLW  VENTANAMIN
    MOVWF  FSR
    MOVLW  .59
    MOVWF  INDF
    
;-----------------------------------
    ;DECREMENTA EL VALOR DE HORAS
    ;EN ESTE PUNTO SALTA SI SEGUNDOS LLEGA A 0
    ;MINUTOS LLEGA A 0 Y HORAS EN 0
    ;RETORNA AL PROGRMA PRINCIPAL
;-------------------------------------- 
    MOVF   VENTANAHOR,W
    BTFSC  STATUS,Z
    GOTO   $+3
    DECF   INDF
    GOTO   AAA
    
    RETURN


