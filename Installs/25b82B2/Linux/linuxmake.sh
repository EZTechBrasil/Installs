#!/usr/bin/env sh

make -B -C /mnt/c/Work200/EZServer/Linux

cp /mnt/c/Work200/EZServer/Linux/Release/ezserver /usr/ezlx/bin

make -B -C /mnt/c/Work200/EZ2Serial/Linux

cp /mnt/c/Work200/EZ2Serial/Linux/Release/ez2serial /usr/ezlx/bin

make -B -C /mnt/c/Work200/EZCompany/Linux

cp /mnt/c/Work200/EZCompany/Linux/Release/ezcompany /usr/ezlx/bin

make -B -C /mnt/c/Work200/EZConnect/Linux

cp /mnt/c/Work200/EZConnect/Linux/Release/ezconnect /usr/ezlx/bin

make -B -C /mnt/c/Work200/EZPing/Linux

cp /mnt/c/Work200/EZPing/Linux/Release/ezping /usr/ezlx/bin

make -B -C /mnt/c/Work200/EZExtract/Linux

cp /mnt/c/Work200/EZExtract/Linux/Release/ezextract /usr/ezlx/bin

make -B -C /mnt/c/Work200/EZClientDLL/Linux

cp /mnt/c/Work200/EZClientDLL/Linux/Release/EZClient.so.1 /usr/ezlx/lib

make -B -C /mnt/c/Work200/EZ2ShellBox/Linux

cp /mnt/c/Work200/EZ2ShellBox/Linux/Release/ez2shellbox /usr/ezlx/bin

make -B -C /mnt/c/Work200/SQLite/SQLBackup/Linux

cp /mnt/c/Work200/SQLite/SQLBackup/Linux/Release/sqlbackup /usr/ezlx/bin

make -B -C /mnt/c/Work200/SQLite/SQLiteCmd/Linux

cp /mnt/c/Work200/SQLite/SQLiteCmd/Linux/Release/sqlitecmd /usr/ezlx/bin




