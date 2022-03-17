@echo off
c:
cd \Vision
del ini\EZProductGroup.ini
EZTelnet\EZTelnet -C InitBBBBefore.cmd -O logs\InitBBBBefore.log 
EZTelnet\EZTelnet -C WriteProtect.cmd -O logs\WriteProtect.log 
EZTelnet\EZTelnet -C InitBBB.cmd -O logs\Upgrade.log 
:exit_upgrade

