
cd \Work200\EZMod\TI
call .\hex.bat
cd \Work200\EZMod\STR711
call .\hex.bat

copy \EZServerCE\Release\*.B2G \zeztech\Release\Product\EZInstallCE\Release
copy \EZServerCE\Release\*.ARM \zeztech\Release\Product\EZInstallCE\Release
copy \EZServerCE\Release\*.exe \zeztech\Release\Product\EZInstallCE\Release
copy \EZServerCE\Release\*.dll \zeztech\Release\Product\EZInstallCE\Release
pause
copy \Vision\Release\*.B2G \zeztech\Release\Product\EZInstallWec\Release
copy \Vision\Release\*.exe \zeztech\Release\Product\EZInstallWec\Release
copy \Vision\Release\*.dll \zeztech\Release\Product\EZInstallWec\Release
rem copy \WINCE800\Osdesign\AM33X_BBB8\AM33X_BBB8\RelDir\AM33X_BBB_BSP_ARMV7_Release\Wec*.exe \zeztech\Release\Product\EZInstallWec\EZApps
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


copy \Work200\EZServer\Linux\Release\ezserver \zeztech\Release\Product\Linux
copy \Work200\EZConnect\Linux\Release\ezconnect \zeztech\Release\Product\Linux 
copy \Work200\EZExtract\Linux\Release\ezextract \zeztech\Release\Product\Linux 
copy \Work200\EZCompany\Linux\Release\ezcompany \zeztech\Release\Product\Linux 
copy \Work200\EZ2Serial\Linux\Release\ez2serial \zeztech\Release\Product\Linux 
copy \Work200\EZPing\Linux\Release\ezping \zeztech\Release\Product\Linux 
copy \Work200\EZ2ShellBox\Linux\Release\ez2shellbox \zeztech\Release\Product\Linux 
copy \Work200\EZClientDLL\Linux\Release\EZClient.so.1 \zeztech\Release\Product\Linux 
copy \Work200\SQLite\SQLBackup\Linux\Release\sqlbackup \zeztech\Release\Product\Linux
copy \Work200\SQLite\SQLiteCmd\Linux\Release\sqlitecmd \zeztech\Release\Product\Linux

copy \Work200\EZServer\Linux64\Release\ezserver \zeztech\Release\Product\Linux64
copy \Work200\EZConnect\Linux64\Release\ezconnect \zeztech\Release\Product\Linux64 
copy \Work200\EZExtract\Linux64\Release\ezextract \zeztech\Release\Product\Linux64 
copy \Work200\EZCompany\Linux64\Release\ezcompany \zeztech\Release\Product\Linux64 
copy \Work200\EZ2Serial\Linux64\Release\ez2serial \zeztech\Release\Product\Linux64 
copy \Work200\EZPing\Linux64\Release\ezping \zeztech\Release\Product\Linux64 
copy \Work200\EZ2ShellBox\Linux64\Release\ez2shellbox \zeztech\Release\Product\Linux64 
copy \Work200\EZClientDLL\Linux64\Release\EZClient.so.1 \zeztech\Release\Product\Linux64 
copy \Work200\SQLite\SQLBackup\Linux64\Release\sqlbackup \zeztech\Release\Product\Linux64
copy \Work200\SQLite\SQLiteCmd\Linux64\Release\sqlitecmd \zeztech\Release\Product\Linux64

copy \Work200\EZClientDLL\Centos7\Release\EZClient.so.1 \zeztech\Release\Product\Centos7 
copy \Work200\EZClientDLL\Centos6\Release\EZClient.so.1 \zeztech\Release\Product\Centos6 

copy \Work200\EZClientDLL\AARCH64\Release\EZClient.so.1 \zeztech\Release\Product\AARCH64 
copy \Work200\EZClientDLL\ARM\Release\EZClient.so.1 \zeztech\Release\Product\ARM 

pause

cd \zeztech\Release\Product