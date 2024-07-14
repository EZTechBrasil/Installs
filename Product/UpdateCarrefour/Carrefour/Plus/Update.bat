@echo off
echo Instalando a conexao com concentrador da EZTech.
if not exist C:\EZServerCE goto notinstalled
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
:notinstalled
echo EZForecourt Plus nao instalado!! 
pause 
exit 



