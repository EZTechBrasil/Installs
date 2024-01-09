copy \EZServerCE\Release\*.B2G \zeztech\Release\Product\EZInstallCE\Release
copy \EZServerCE\Release\*.ARM \zeztech\Release\Product\EZInstallCE\Release
copy \EZServerCE\Release\*.exe \zeztech\Release\Product\EZInstallCE\Release
copy \EZServerCE\Release\*.dll \zeztech\Release\Product\EZInstallCE\Release
pause
copy \Vision\Release\*.B2G \zeztech\Release\Product\EZInstallWec\Release
copy \Vision\Release\*.exe \zeztech\Release\Product\EZInstallWec\Release
copy \Vision\Release\*.dll \zeztech\Release\Product\EZInstallWec\Release
pause 
copy \Work200\EZInstall\*.B2G \zeztech\Release\Product\EZInstallXP
copy \Work200\EZInstall\*.ARM \zeztech\Release\Product\EZInstallXP
copy \Work200\EZInstall\*.exe \zeztech\Release\Product\EZInstallXP
copy \Work200\EZInstall\*.dll \zeztech\Release\Product\EZInstallXP
pause 
xcopy \Work200\EZInstall\EZmonitor\* \zeztech\Release\Product\EZInstallXP\EZmonitor /s /y
xcopy \Work200\EZInstall\x64\* \zeztech\Release\Product\EZInstallXP\x64 /s /y
xcopy \Work200\EZInstall\Passo\* \zeztech\Release\Product\EZInstallXP\Passo /s /y
pause 
