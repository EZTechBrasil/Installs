c:
cd \Vision
EZTelnet\EZTelnet -C StopEZ2Serial.cmd -O logs\Upgrade.log 
NcFTP\NcFTPPut -f Vision.cfg -d logs\Upgrade3.log -m \NDFlash\EZForecourt  \NDFlash\EZForecourt  \Vision\Release\EZ2serial.dll
EZTelnet\EZTelnet -C StartEZ2Serial.cmd -O logs\Upgrade.log 
wait


