;--------------------------------------------------------
  ;DESPLAZA EL CONTENIDO UN REGISTRO AL SIGUIENTE REGISTRO ES DECIR
  ;ES AQUI DONDE DESPLAZAMOS LAS LETRAS ESTE PROCESO SE REALIZA 6 VECES
  ;EL NUMERO DE DISPLAYS
;----------------------------------------------------------
ROTAR_CARACTER:
    MOVLW  VENTANASEG
    MOVWF  FSR
    INCF   FSR
    MOVF   INDF,W
    DECF   FSR
    MOVWF  INDF
    INCF   FSR
    INCF   REG4
    MOVLW  0X05
    XORWF  REG4,W
    BTFSS  STATUS,Z
    GOTO   ROTAR_CARACTER+2
    CLRF   REG4
    RETURN
    



