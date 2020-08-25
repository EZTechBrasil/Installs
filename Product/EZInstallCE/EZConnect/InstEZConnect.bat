@echo off
echo Instalando a conexao com concentrador da EZTech.
if exist C:\EZServerCE goto alreadyinstalled
echo Criando as pastas etc.
md C:\EZForecourt
copy EZForecourt\* C:\EZForecourt
md C:\EZServerCE
md C:\EZServerCE\Release
md C:\EZServerCE\EZTelnet
copy EZTelnet\* C:\EZServerCE\EZTelnet
copy *.cfg C:\EZServerCE
md C:\EZServerCE\NcFTP
copy NcFTP\* C:\EZServerCE\NcFTP
md C:\EZServerCE\INI
md C:\EZServerCE\INI\Install
C:\EZForecourt\EZIPConfig.exe
:alreadyinstalled
echo Copiando os arquivos para o computador...
copy Release\* C:\EZServerCE\Release
copy EZConnect.ini C:\EZServerCE\Ini\Install
copy *.cmd C:\EZServerCE
C:
cd \EZServerCE
echo Copiando os arquivos para o concentrador.
EZTelnet\EZTelnet -C InstEZConnectBefore.cmd -O logs\InstEZConnectBefore.log 
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\InstEZHOWSC1.log \NDFlash\EZForecourt  \EZServerCE\Release\EZConnect.dll
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\InstEZHOWSC2.log \NDFlash\EZForecourt  \EZServerCE\Release\EZHOWSCInst.exe
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\InstEZHOWSC3.log \NDFlash\EZForecourt  \EZServerCE\INI\Install\EZConnect.ini
EZTelnet\EZTelnet -C InstEZConnectAfter.cmd -O logs\InstEZConnectAfter.log 
echo Instalacao completa, tecla entra para continuar.
pause
exit 

