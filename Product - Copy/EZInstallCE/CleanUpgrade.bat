C:
cd \EZServerCE
del Upgrade.log
del ini\ezlicense.ini
del ini\ez2serial.ini
del ini\ezTankGauge.ini
\EZTelnet\EZTelnet -C CleanStop.cmd -O logs\Upgrade.log 
\NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\Upgrade1.log -m \NDFlash\HTTP\Admin   \NDFlash\HTTP\Admin   \EZServerCE\HTTP\Admin\*
\NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\Upgrade2.log -m \NDFlash\HTTP\Main    \NDFlash\HTTP\Main    \EZServerCE\HTTP\Main\*
\NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\Upgrade3.log -m \NDFlash\EZForecourt  \NDFlash\EZForecourt  \EZServerCE\Release\*
\NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\Upgrade4.log -m \NDFlash\EZForecourt  \NDFlash\EZForecourt  \EZServerCE\INI\*
\NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\install5.log -m \NDFlash\CTF  \NDFlash\CTF  \EZServerCE\CTF\*
\EZTelnet\EZTelnet -C CleanStart.cmd -O logs\Upgrade.log 
