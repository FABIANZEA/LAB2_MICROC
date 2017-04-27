;--------------------------------------------------------
    ;RUTINA USANDO EL DIRECCIONAMIENTO INDIRECTO INICIALIZAMOS LOS REGISTROS
;----------------------------------------------------------
INIG_REG:
    MOVLW 0X20
    MOVWF FSR
    CLRF  INDF
    INCF  FSR
    MOVLW 0X40
    XORWF FSR,W
    BTFSS STATUS,Z
    GOTO  $-5
RETURN

