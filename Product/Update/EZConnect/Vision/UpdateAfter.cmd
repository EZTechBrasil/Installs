attrib +R \NDFlash\EZForecourt\EZConnect.dll
ezhowscinst /EZC /DNS 
eznet start all 
eznet service del EZHOWSC
eznet service add EZConnect 32
exit