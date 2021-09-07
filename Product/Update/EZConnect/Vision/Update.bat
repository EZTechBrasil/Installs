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
copy *.cmd C:\Vision
C:
cd \Vision
echo Copiando os arquivos para o concentrador.
EZTelnet\EZTelnet -C UpdateBefore.cmd -O logs\UpdateBefore.log 
NcFTP\NcFTPPut -f Vision.cfg -d logs\Upgrade1.log \NDFlash\EZForecourt  \Vision\Release\Wayne.dll
NcFTP\NcFTPPut -f Vision.cfg -d logs\Upgrade1.log \NDFlash\EZForecourt  \Vision\Release\EZServer.dll
NcFTP\NcFTPPut -f Vision.cfg -d logs\Upgrade1.log \NDFlash\EZForecourt  \Vision\Release\Gilbarco.dll
NcFTP\NcFTPPut -f Vision.cfg -d logs\Upgrade1.log \NDFlash\EZForecourt  \Vision\Release\EZConnect.dll
NcFTP\NcFTPPut -f Vision.cfg -d logs\Upgrade1.log \NDFlash\EZForecourt  \Vision\Release\EZConnect.ini
NcFTP\NcFTPPut -f Vision.cfg -d logs\Upgrade1.log \NDFlash\EZForecourt  \Vision\Release\ezhowscinst.exe 
EZTelnet\EZTelnet -C UpdateAfter.cmd -O logs\UpdateAfter.log 
echo Instalacao completa, tecla entra para continuar.
exit 

