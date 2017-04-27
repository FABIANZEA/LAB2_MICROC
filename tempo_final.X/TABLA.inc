;--------------------------------
    ;TABLA DE CONVERSION DE BCD A 7 SEGMENTOS
;----------------------------------------
TABLA:
    ADDWF  PCL,1
    RETLW  0X7E
    RETLW  0X30
    RETLW  0X6D
    RETLW  0X79
    RETLW  0X33
    RETLW  0X5B
    RETLW  0X1F
    RETLW  0X70
    RETLW  0X7F
    RETLW  0X7B

