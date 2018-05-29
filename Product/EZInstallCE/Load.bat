C:
CD \EZServerCE
EZTelnet\EZTelnet -C stop.cmd -O logs\Load.log 
NcFTP\NcFTPPut -f EZServerCE.cfg -d Load1.log -m \NDFlash\EZForecourt   \NDFlash\EZForecourt   \EZServerCE\INI\EZ2Serial.ini
EZTelnet\EZTelnet -C load.cmd -O logs\Load2.log 

