@echo off
c:
cd \Vision
EZConfirm.exe "Are you sure you want to initilaise the database ?" 
if not errorlevel 0 goto exit_upgrade 
EZTelnet\EZTelnet -C RestoreDB.cmd -O logs\Upgrade.log 
exit_upgrade:

