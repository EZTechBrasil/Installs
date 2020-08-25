@echo off
echo Instalando a conexao com concentrador da EZTech.
if exist C:\Vision goto alreadyinstalled
echo Criando as pastas etc.
md C:\EZForecourt
copy EZForecourt\* C:\EZForecourt
md C:\Vision
md C:\Vision\Release
md C:\Vision\EZTelnet
copy EZTelnet\* C:\Vision\EZTelnet
copy *.cfg C:\Vision
md C:\Vision\NcFTP
copy NcFTP\* C:\Vision\NcFTP
md C:\Vision\INI
md C:\Vision\INI\Install
C:\EZForecourt\EZIPConfig.exe
:alreadyinstalled
echo Copiando os arquivos para o computador...
copy Release\* C:\Vision\Release
copy EZHOWSC.ini C:\Vision\Ini\Install
copy *.cmd C:\Vision
C:
cd \Vision
echo Copiando os arquivos para o Vision....
EZTelnet\EZTelnet -C InstEZHOWSCBefore.cmd -O logs\InstEZHOWSCBefore.log 
NcFTP\NcFTPPut -f Vision.cfg -d logs\InstEZHOWSC1.log \NDFlash\EZForecourt  \Vision\Release\EZHOWSC.dll
NcFTP\NcFTPPut -f Vision.cfg -d logs\InstEZHOWSC2.log \NDFlash\EZForecourt  \Vision\Release\EZHOWSCInst.exe
NcFTP\NcFTPPut -f Vision.cfg -d logs\InstEZHOWSC3.log \NDFlash\EZForecourt  \Vision\INI\Install\EZHOWSC.ini
EZTelnet\EZTelnet -C InstEZHOWSCAfter.cmd -O logs\InstEZHOWSCAfter.log 
echo Instalacao completa, tecla entra para continuar.
pause
exit 

