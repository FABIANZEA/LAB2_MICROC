;--------------------------------------------------------
  ;RETARDO DE 300uS ES LA DURACION DE CADA VISUALIZACION ENTRE CADA DISPLAY
;----------------------------------------------------------
RETARDO1:
	    MOVLW  .200
	    MOVWF  CONTA2
	    DECFSZ CONTA2
	    GOTO   $-1
	    RETURN


