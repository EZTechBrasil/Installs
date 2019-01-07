attrib -R \ndflash\ezforecourt\*.ini
setdate
settime
ezloader EZMOD
eznet service add ezserver 30
eznet service add ez2serial 31
eznet service add ezhowsc 32
eznet start all
exit