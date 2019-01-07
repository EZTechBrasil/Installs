EZNet stop all
cd \NDFlash\SQLite
del EzDBOld.SQL
ren EzDB.SQL EzDBOld.SQL
cd \
del *.zip 
del *.L00
EZNet start all
EZExtract import \NDFlash\SQLite\config.ini 
exit

