cd \
ezzip -x \Release.zip \Temp
eznet stop EZHOWSC
eznet stop EZVid
eznet stop EZAuth
eznet stop CTF
eznet stop EZServer
del *.l??
del *.zip
cd \NDFLash\EZForecourt
attrib -R *.dll
attrib -R *.old
attrib -R *.upg
attrib -R EZServer.*
attrib -R EZHOWSC.*
attrib -R EZConnect.*
attrib -R EZVid.*
attrib -R EZAuth.*
attrib -R CTF.*
del *.old
del *.upg
del EZServer.dll
del EZHOWSC.dll 
del EZConnect.dll
del EZVid.dll
del EZAuth.dll
del CTF.dll
ren EZServer.dll EZServer.upg
ren EZHOWSC.dll EZHOWSC.upg
ren EZConnect.dll EZConnect.upg
ren EZAuth.dll EZAuth.upg
ren EZVid.dll EZVid.upg
ren CTF.dll CTF.upg
cd \
copy \Temp\* \NDFlash\EZForecourt
cd \NDFLash\EZForecourt
copy EZConnect.dll EZVid.dll
rem copy EZConnect.dll EZAuth.dll
rem copy EZConnect.dll CTF.dll
cd \NDFlash\SQLite
del EzDB.bu
ren EzDB.SQL EzDB.bu
cd \
eznet start all 
del \Temp\*.dll
del \Temp\*.exe
del \Temp\*.ini
del \NDFlash\EZForecourt\*.old
del \NDFlash\EZForecourt\*.upg

exit