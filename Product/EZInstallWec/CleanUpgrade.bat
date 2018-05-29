C:
cd \Vision
del Upgrade.log
del ini\ezlicense.ini
del ini\ez2serial.ini
del ini\ezTankGauge.ini
\EZTelnet\EZTelnet -C CleanStop.cmd -O logs\Upgrade.log 
\NcFTP\NcFTPPut -f Vision.cfg -d logs\Upgrade3.log -m \NDFlash\EZForecourt  \NDFlash\EZForecourt  \Vision\Release\*
\NcFTP\NcFTPPut -f Vision.cfg -d logs\Upgrade4.log -m \NDFlash\EZForecourt  \NDFlash\EZForecourt  \Vision\INI\*
\EZTelnet\EZTelnet -C CleanStart.cmd -O logs\Upgrade.log 
