eznet stop EZConnect
eznet stop EZHOWSC
attrib -R \NDFlash\EZForecourt\EZConnect.*
attrib -R \NDFlash\EZForecourt\EZHOWSC.*
del \NDFlash\EZForecourt\EZHOWSC.*
del \NDFlash\EZForecourt\EZConnect.DLL
del \NDFlash\EZForecourt\EZConnect.NV
del *.l00
exit