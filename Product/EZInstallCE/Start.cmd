setdate
settime
ezloader EZMOD
eznet stop EZHOWSC
attrib -R \NDFlash\EZForecourt\EZHOWSC.*
del \NDFlash\EZForecourt\EZHOWSC.*
attrib -R \NDFlash\EZForecourt\*.ini
attrib +R \NDFlash\EZForecourt\EZConnect.dll
ezhowscinst /EZC /DNS 
eznet start all
exit