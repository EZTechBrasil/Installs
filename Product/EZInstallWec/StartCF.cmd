attrib -R \NDFlash\ezforecourt\*.ini
attrib -R \NDFlash\SQlite\*.ini
attrib -R \NDFlash\SQlite\*.ini
copy \NDFlash\Carrefour\*.ini \NDFlash\EZForecourt
copy \NDFlash\Carrefour\EZSQLite.ini \NDFlash\SQLite
cd \NDFlash\SQLite
del EzDBOld.SQL
ren EzDB.SQL EzDBOld.SQL
setdate
settime
ezloader EZMOD
ezhowscinst /EZC /DNS 
eznet service add ezserver 30
eznet service add ez2serial 31
eznet service add ezconnect 32
eznet service add ezhowsc 33
eznet start all
exit