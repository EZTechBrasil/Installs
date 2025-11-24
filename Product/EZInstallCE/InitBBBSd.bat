C:
CD \EZServerCE
@echo off
c:
cd \EZServerCE
del install.log
EZTelnet\EZTelnet -C InitBBBSd.cmd -O logs\install.log 
exit