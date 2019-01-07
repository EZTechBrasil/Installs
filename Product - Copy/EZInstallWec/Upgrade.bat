@echo off
c:
cd \Vision
EZConfirm.exe "Are you sure you want to upgrade the EZTech Vision ?" 
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
EZTelnet\EZTelnet -C InitBBBBefore.cmd -O logs\InitBBBBefore.log 
EZTelnet\EZTelnet -C RemoveOld.cmd -O logs\Upgrade.log 
NcFTP\NcFTPPut -f Vision.cfg -d logs\Upgrade1.log -m \NDFlash\Log          \Vision\log\*.ini		  
NcFTP\NcFTPPut -f Vision.cfg -d logs\Upgrade2.log -m \NDFlash\SQLite       \Vision\INI\SQLite\*.ini
NcFTP\NcFTPPut -f Vision.cfg -d logs\Upgrade3.log -m \NDFlash\EZForecourt  \Vision\Release\*.*
NcFTP\NcFTPPut -f Vision.cfg -d logs\Upgrade4.log -m \NDFlash\EZApps       \Vision\EZApps\*.exe
NcFTP\NcFTPPut -f Vision.cfg -d logs\Upgrade5.log \NDFlash\EZForecourt     \Vision\INI\*.ini
EZTelnet\EZTelnet -C WriteProtect.cmd -O logs\WriteProtect.log 
NcFTP\NcFTPPut -f Vision.cfg -d logs\install5.log \NDFlash\EZForecourt     \Vision\INI\Install\*.ini
EZTelnet\EZTelnet -C Start.cmd -O logs\Upgrade.log 
exit_upgrade:

