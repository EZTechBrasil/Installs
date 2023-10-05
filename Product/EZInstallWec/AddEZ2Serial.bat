C:
cd \Vision
EZTelnet\EZTelnet -V "v 8.00" -C StopEZ2Serial.cmd -O logs\Upgrade.log 
if not errorlevel 0 goto wrong_version 

NcFTP\NcFTPPut -f Vision.cfg -d logs\Upgrade3.log -m \NDFlash\EZForecourt  \NDFlash\EZForecourt  \Vision\Release\EZ2serial.dll
NcFTP\NcFTPPut -f Vision.cfg -d logs\Upgrade4.log -m \NDFlash\EZForecourt  \NDFlash\EZForecourt  \Vision\INI\Install\EZ2Serial.ini
EZTelnet\EZTelnet -C StartEZ2Serial.cmd -O logs\Upgrade.log 
echo All done. 
exit 

:wrong_version
echo Exit Code is %errorlevel%
echo Suspected EZForecourt Plus/2GS connected not a Vision!!
pause
exit

