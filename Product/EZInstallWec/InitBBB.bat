@echo off
c:
cd \Vision
del ini\EZProductGroup.ini
EZTelnet\EZTelnet -V "v 8.00" -C InitBBBBefore.cmd -O logs\InitBBBBefore.log 
if not errorlevel 0 goto wrong_version 

EZTelnet\EZTelnet -C WriteProtect.cmd -O logs\WriteProtect.log 
EZTelnet\EZTelnet -C InitBBB.cmd -O logs\Upgrade.log 
echo All done. 
exit 

:wrong_version
echo Exit Code is %errorlevel%
echo Suspected EZForecourt Plus/2GS connected not a Vision!!
pause
exit

