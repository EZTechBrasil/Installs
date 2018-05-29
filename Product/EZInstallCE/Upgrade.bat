@echo off
c:
cd \EZServerCE
EZConfirm.exe "Are you sure you want to upgrade the EZForecourt Plus ?" 
if not errorlevel 0 goto exit_upgrade 
del Upgrade.log
del ini\EZlicense.ini
del ini\EZ2serial.ini
del ini\EZ3serial.ini
del ini\EZTankGauge.ini
del ini\EZServer.ini
del ini\EZATG.ini
del ini\BMConfig.ini
del ini\EZPriceSign.ini
del ini\EZProductGroup.ini
@echo on
EZTelnet\EZTelnet -C RemoveOld.cmd -O logs\Upgrade.log 
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\install2.log -m \NDFlash\Log          \EZServerCE\log\*.ini
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\Upgrade3.log -m \NDFlash\EZForecourt  \EZServerCE\Release\*.*
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\Upgrade4.log \NDFlash\EZForecourt     \EZServerCE\INI\*.ini
EZTelnet\EZTelnet -C WriteProtect.cmd -O logs\WriteProtect.log 
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\install5.log \NDFlash\EZForecourt     \EZServerCE\INI\Install\*.ini
EZTelnet\EZTelnet -C Start.cmd -O logs\Upgrade.log 
exit_upgrade:

