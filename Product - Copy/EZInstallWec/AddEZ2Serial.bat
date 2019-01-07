C:
cd \Vision
EZTelnet\EZTelnet -C StopEZ2Serial.cmd -O logs\Upgrade.log 
NcFTP\NcFTPPut -f Vision.cfg -d logs\Upgrade3.log -m \NDFlash\EZForecourt  \NDFlash\EZForecourt  \Vision\Release\EZ2serial.dll
NcFTP\NcFTPPut -f Vision.cfg -d logs\Upgrade4.log -m \NDFlash\EZForecourt  \NDFlash\EZForecourt  \Vision\INI\Install\EZ2Serial.ini
EZTelnet\EZTelnet -C StartEZ2Serial.cmd -O logs\Upgrade.log 
