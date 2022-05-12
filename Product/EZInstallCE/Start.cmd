setdate
settime
ezloader EZMOD
attrib -R \NDFlash\EZForecourt\*.ini
attrib -R \NDFlash\SQLite\*.ini
cd \NDFlash\EZForecourt
copy EZConnect.dll EZVid.dll
eznet start all
exit