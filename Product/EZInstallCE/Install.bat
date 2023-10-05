@echo off
c:
cd \EZServerCE
.\EZConfirm.exe "Are you sure you want to install the EZForecourt Plus ?" 
if not errorlevel 0 goto exit_install 

del install.log
EZTelnet\EZTelnet -V "v 5.00" -C RemoveOld.cmd -O logs\install.log 
if not errorlevel 0 goto wrong_version 

NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\install1.log -m \NDFlash\Log          \EZServerCE\logs\*.ini
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\install2.log -m \NDFlash\SQLite       \EZServerCE\INI\SQLite\*.ini
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\install3.log -m \NDFlash\EZForecourt  \EZServerCE\Release\*.*
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\install4.log \NDFlash\EZForecourt     \EZServerCE\INI\*.ini
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\install5.log \NDFlash\EZForecourt     \EZServerCE\INI\Install\*.ini
EZTelnet\EZTelnet -C start.cmd -O logs\install.log 
:exit_install
echo All done. 
exit 

:wrong_version
echo Exit Code is %errorlevel%
echo Suspected Vision connected not a EZForecourt Plus/2GS!!
pause
exit
