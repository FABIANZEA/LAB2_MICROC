;--------------------------------------------------------
  ;MUESTRA LOS CONTENIDOS DE CADA REGISTROS EN LOS 6 DISPLAYS EN EL PUERTO D
  ;HABILITANDO CUAL DISPLAY SE DESEA ENCENDER EN EL PUERTO C
  ;PROCESO QUE TIENE 100 REPETICIONES
  ;PAARA UN DESPLAZAMIENTO CADA DE 200mS
;----------------------------------------------------------
SALIDA_VISUAL:
    CLRF  PORTC
    BSF   PORTC,6
    MOVLW VENTANASEG
    MOVWF FSR
    MOVF  INDF,W
    MOVWF PORTD
    RRF   PORTC
    CALL  RETARDO1
    INCF  FSR
    INCF  REG1
    MOVLW 0X06
    XORWF REG1,W
    BTFSS STATUS,Z
    GOTO  $-9
    CLRF  REG1
    INCF  REG2
    MOVLW 0X64
    XORWF REG2,W
    BTFSS STATUS,Z
    GOTO SALIDA_VISUAL
    CLRF REG2
    CLRF PORTC
    RETURN





