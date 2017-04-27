;--------------------------------------------------------
  ;RUTINA PARA MOSTRAR ALGUNO DE LOS 
;----------------------------------------------------------
PUBLIC:
    CALL  INIG_REG

VOLVER:
    CALL   SALIDA_VISUAL
    CALL   ROTAR
    INCF   REG5
    MOVLW  0X24
    XORWF  REG5,W
    BTFSS  STATUS,Z
    GOTO   VOLVER
    RETURN
 









