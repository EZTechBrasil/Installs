cd \
ezzip -x \Release.zip \Temp
eznet stop EZConnect
eznet stop EZHOWSC
eznet stop EZServer
del *.l00
del *.zip
cd \NDFLash\EZForecourt
attrib -R *.dll
attrib -R *.old
attrib -R *.upg
attrib -R EZServer.*
attrib -R EZConnect.*
attrib -R EZHOWSC.*
del *.old
del *.upg
del EZServer.dll
del EZHOWSC.dll
del EZConnect.dll
ren EZServer.dll EZServer.upg
ren EZHOWSC.dll EZHOWSC.upg
ren EZConnect.dll EZConnect.upg
cd \
copy \Temp\* \NDFlash\EZForecourt
attrib +R \NDFlash\EZForecourt\EZConnect.dll
cd \NDFlash\SQLite
del EzDB.bu
ren EzDB.SQL EzDB.bu
cd \
eznet start all 
eznet start ezhowsc
eznet start ezconnect
del \Temp\*.dll
del \Temp\*.exe
del \Temp\*.ini
del \NDFlash\EZForecourt\*.old
del \NDFlash\EZForecourt\*.upg
exit