@echo off
c:
cd \EZServerCE
EZConfirm.exe "Are you sure you want to upgrade the EZForecourt Plus ?" 
if not errorlevel 0 goto exit_upgrade 
del Upgrade.log
del ini\ezlicense.ini
del ini\ez2serial.ini
del ini\ezTankGauge.ini
@echo on
EZTelnet\EZTelnet -C RemoveOld.cmd -O logs\Upgrade.log 
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\install2.log -m \NDFlash\Log          \EZServerCE\log\*.ini
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\Upgrade3.log -m \NDFlash\EZForecourt  \EZServerCE\ReleaseBBB\*.*
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\Upgrade4.log \NDFlash\EZForecourt  \EZServerCE\INI\*.ini
EZTelnet\EZTelnet -C Start.cmd -O logs\Upgrade.log 
exit_upgrade:

