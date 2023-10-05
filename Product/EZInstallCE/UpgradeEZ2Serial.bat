@echo off
c:
cd \EZServerCE
EZTelnet\EZTelnet -V "v 5.00" -C StopEZ2Serial.cmd -O logs\Upgrade.log 
if not errorlevel 0 goto wrong_version 

NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\Upgrade3.log -m \NDFlash\EZForecourt  \NDFlash\EZForecourt  \EZServerCE\Release\EZ2serial.dll
EZTelnet\EZTelnet -C StartEZ2Serial.cmd -O logs\Upgrade.log 
echo All done. 
exit 

:wrong_version
echo Exit Code is %errorlevel%
echo Suspected Vision connected not a EZForecourt Plus/2GS!!
pause
exit



