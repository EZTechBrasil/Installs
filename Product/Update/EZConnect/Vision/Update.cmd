cd \
ezzip -x \Release.zip \Temp
eznet stop EZConnect
eznet stop EZHOWSC
eznet stop All
del *.l00
del *.zip
cd \NDFLash\EZForecourt
attrib -R *.dll
attrib -R *.old
attrib -R *.upg
attrib -R EZConnect.*
attrib -R EZHOWSC.*
del *.old
del EZHOWSC.*
del EZConnect.*
ren EZServer.dll EZServer.upg
ren EZ2Serial.dll EZ2Serial.upg
ren EZLog.dll EZLog.upg
ren PumpDrv.dll PumpDrv.upg
ren TankDrv.dll TankDrv.upg
ren Gilbarco.dll Gilbarco.upg
ren Wayne.dll Wayne.upg
ren EZClient.dll EZClient.upg
cd \
copy \Temp\* \NDFlash\EZForecourt
attrib +R \NDFlash\EZForecourt\EZConnect.dll
ezhowscinst /EZC /DNS 
eznet start all 
del \Temp\*.dll
del \Temp\*.exe
del \Temp\*.ini
del \NDFlash\EZForecourt\*.old
del \NDFlash\EZForecourt\*.upg

exit