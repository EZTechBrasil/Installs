C:
cd \EZServerCE
EZTelnet\EZTelnet -C StopEZ2Serial.cmd -O logs\Upgrade.log 
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\Upgrade3.log -m \NDFlash\EZForecourt  \NDFlash\EZForecourt  \EZServerCE\Release\EZ2serial.dll
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\Upgrade4.log -m \NDFlash\EZForecourt  \NDFlash\EZForecourt  \EZServerCE\INI\Install\EZ2Serial.ini
EZTelnet\EZTelnet -C StartEZ2Serial.cmd -O logs\Upgrade.log 
