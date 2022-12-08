attrib -R \ndflash\ezforecourt\*.ini
setdate
settime
ezloader EZMOD
eznet service add ezserver 30
eznet service add ez2serial 31
eznet service del EZHOWSC
attrib -R \NDFlash\EZForecourt\EZHOWSC.*
del \NDFlash\EZForecourt\EZHOWSC.*
ezhowscinst /EZC /DNS 
eznet service add EZConnect 32
eznet start all 
exit