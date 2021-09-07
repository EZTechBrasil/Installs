attrib +R \NDFlash\EZForecourt\EZConnect.dll
ezhowscinst /EZC /DNS 
eznet start all 
eznet service add EZConnect 32
eznet service del EZHOWSC
exit