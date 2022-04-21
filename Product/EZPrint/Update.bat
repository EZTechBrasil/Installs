@echo off
echo Instalando o EZPrint da EZTech.
if exist C:\EZForecourt goto alreadyinstalled
echo Criando as pastas etc.
md C:\EZForecourt
copy EZForecourt\Install\* C:\EZForecourt
:alreadyinstalled
echo Copiando os arquivos para o computador...
if exist C:\EZForecourt\PDF goto alreadyhas
md C:\EZForecourt\PDF
:alreadyhas
if not exist C:\EZForecourt\EZPrint.exe goto newinstall
del C:\EZForecourt\EZPrint.old
C:\EZForecourt\EZPrint /uninstall
ren C:\EZForecourt\EZPrint.exe C:\EZForecourt\EZPrint.old
del C:\EZForecourt\EZPrint.old
:newinstall
copy EZForecourt\* C:\EZForecourt
C:
cd EZForecourt
start .\EZPrint /install
exit 

