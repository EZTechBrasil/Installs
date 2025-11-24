C:
CD \EZServerCE
@echo off
c:
cd \EZServerCE
EZTelnet\EZTelnet -C InitBBBBefore.cmd -O logs\InitBBBBefore.log 
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\install3.log -m \NDFlash\EZForecourt  \EZServerCE\ReleaseBBB\*.*
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\install4.log \NDFlash\EZForecourt  \EZServerCE\INI\*.ini
rem NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\install5.log \NDFlash\EZForecourt  \EZServerCE\INI\Install\*.ini
EZTelnet\EZTelnet -C InitBBBAfter.cmd -O logs\InitBBBAfter.log 
exit 

