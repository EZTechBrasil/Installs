@echo off
c:
cd \Vision
del install.log
EZTelnet\EZTelnet -C InitBBBSd.cmd -O logs\install.log 
exit