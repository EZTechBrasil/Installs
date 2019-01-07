eznet stop all 
del *.l00
del *.zip 
copy \ndflash\ezforecourt\EZServer.NV \ndflash\ezforecourt\EZServer.old
del \ndflash\ezforecourt\EZServer.NV
eznet start all
setdate
settime
exit