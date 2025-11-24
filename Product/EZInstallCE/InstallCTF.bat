C:
CD \EZServerCE
del install.log
EZTelnet\EZTelnet -C Stop.cmd -O logs\install.log 
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\install1.log -m \NDFlash\HTTP\Admin   \NDFlash\HTTP\Admin   \EZServerCE\HTTP\Admin\*
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\install2.log -m \NDFlash\HTTP\Main    \NDFlash\HTTP\Main    \EZServerCE\HTTP\Main\*
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\install3.log -m \NDFlash\EZForecourt  \NDFlash\EZForecourt  \EZServerCE\Release\*
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\install4.log -m \NDFlash\EZForecourt  \NDFlash\EZForecourt  \EZServerCE\INI\*
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\install5.log -m \NDFlash\EZForecourt  \NDFlash\EZForecourt  \EZServerCE\INI\Install\*
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\install6.log -m \NDFlash\CTF  \NDFlash\CTF  \EZServerCE\CTF\*
EZTelnet\EZTelnet -C start.cmd -O logs\install.log 
