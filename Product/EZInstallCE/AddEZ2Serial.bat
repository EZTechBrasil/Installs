c:
cd \EZServerCE
EZTelnet\EZTelnet -V "v 5.0" -C StopEZ2Serial.cmd -O logs\Upgrade.log 
if not errorlevel 0 goto wrong_version 

EZTelnet\EZTelnet -C StopEZ2Serial.cmd -O logs\Upgrade.log 
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\Upgrade3.log -m \NDFlash\EZForecourt  \NDFlash\EZForecourt  \EZServerCE\Release\EZ2serial.dll
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\Upgrade4.log -m \NDFlash\EZForecourt  \NDFlash\EZForecourt  \EZServerCE\INI\Install\EZ2Serial.ini
EZTelnet\EZTelnet -C StartEZ2Serial.cmd -O logs\Upgrade.log 
echo All done. 
exit 

:wrong_version
echo Exit Code is %errorlevel%
echo Suspected Vision connected not a EZForecourt Plus/2GS!!
pause
exit
