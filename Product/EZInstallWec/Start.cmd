attrib -R \ndflash\ezforecourt\*.ini
attrib -R \ndflash\SQlite\*.ini
setdate
settime
ezloader EZMOD
ezhowscinst /EZC /DNS 
eznet service add ezserver 30
eznet service add ez2serial 31
eznet service del ezhowsc
eznet service add ezconnect 32
eznet start all
exit