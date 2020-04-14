copy EZHOWSC.dll C:\EZServerCE\Release
copy EZHOWSC.ini C:\EZServerCE\Ini\Install
copy *.bat C:\EZServerCE
copy *.cmd C:\EZServerCE
C:
cd \EZServerCE
EZTelnet\EZTelnet -C InstEZHOWSCBefore.cmd -O logs\InstEZHOWSCBefore.log 
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\InstEZHOWSC1.log \NDFlash\EZForecourt  \EZServerCE\Release\EZHOWSC.dll
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\InstEZHOWSC2.log \NDFlash\EZForecourt     \EZServerCE\INI\Install\EZHOWSC.ini
EZTelnet\EZTelnet -C InstEZHOWSCAfter.cmd -O logs\InstEZHOWSCAfter.log 
pause

