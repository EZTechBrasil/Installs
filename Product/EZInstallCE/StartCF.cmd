attrib -R \NDFlash\ezforecourt\*.ini
attrib -R \NDFlash\SQlite\*.ini
copy \NDFlash\Carrefour\*.ini \NDFlash\EZForecourt
copy \NDFlash\Carrefour\EZSQLite.ini \NDFlash\SQLite
setdate
settime
ezloader EZMOD
ezhowscinst /EZC /DNS 
cd \NDFlash\EZForecourt
copy EZConnect.dll EZVid.dll
eznet start all
exit