@echo off
c:
cd \Vision
EZTelnet\EZTelnet -C InitBBBBefore.cmd -O logs\InitBBBBefore.log 
NcFTP\NcFTPPut -f Vision.cfg -d logs\install3.log -m \NDFlash\EZForecourt  \Vision\Release\*.*
NcFTP\NcFTPPut -f Vision.cfg -d logs\install4.log \NDFlash\EZForecourt  \Vision\INI\*.ini
rem NcFTP\NcFTPPut -f Vision.cfg -d logs\install5.log \NDFlash\EZForecourt  \Vision\INI\Install\*.ini
EZTelnet\EZTelnet -C InitBBBAfter.cmd -O logs\InitBBBAfter.log 
exit 

