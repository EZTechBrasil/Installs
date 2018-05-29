del \ndflash\ezforecourt\ez2serial.ini 
EZExtract EXPORT \ndflash\ezforecourt\ez2serial.ini /PAM 
eznet stop all
del \ndflash\ezforecourt\EZServer.NV
eznet start all
setdate
settime
exit