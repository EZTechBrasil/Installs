@echo off
echo Instalando a conexao com concentrador da EZTech.
if exist C:\EZServerCE\EZTelnet goto alreadyinstalled
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
copy *.cmd C:\EZServerCE
C:
cd \EZServerCE
echo Copiando os arquivos para o concentrador.
NcFTP\NcFTPPut -f EZServerCE.cfg -d logs\Upgrade1.log \  \EZServerCE\Release\Release.zip
EZTelnet\EZTelnet -C Update.cmd -O logs\Update.log 
echo Instalacao completa, tecla entra para continuar.
pause
exit 



