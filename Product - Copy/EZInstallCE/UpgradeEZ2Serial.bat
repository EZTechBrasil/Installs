cd \EZServerCE
EZTelnet\EZTelnet -C StopEZ2Serial.cmd -O logs\Upgrade.log 
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\Upgrade3.log -m \NDFlash\EZForecourt  \NDFlash\EZForecourt  \EZServerCE\Release\EZ2serial.dll
EZTelnet\EZTelnet -C StartEZ2Serial.cmd -O logs\Upgrade.log 
wait


