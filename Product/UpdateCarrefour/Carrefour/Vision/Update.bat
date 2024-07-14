@echo off
echo Instalando a conexao com concentrador da EZTech.
if not exist C:\Vision goto notinstalled
echo Copiando os arquivos para o computador...
copy *.cmd C:\Vision
C:
cd \Vision
echo Copiando os arquivos para o concentrador.
NcFTP\NcFTPPut -f Vision.cfg -d logs\Upgrade1.log \  \Vision\Release\Release.zip
EZTelnet\EZTelnet -C Update.cmd -O logs\Update.log 
echo Instalacao completa, tecla entra para continuar.
exit 
:notinstalled
echo EZTech Vision nao instalado 
pause 
exit 

