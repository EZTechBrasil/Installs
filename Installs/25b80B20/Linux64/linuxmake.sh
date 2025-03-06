#!/usr/bin/env sh

make -B -C /mnt/c/Work200/EZServer/Linux64

cp /mnt/c/Work200/EZServer/Linux64/Release/ezserver /usr/ezlx/bin

make -B -C /mnt/c/Work200/EZ2Serial/Linux64

cp /mnt/c/Work200/EZ2Serial/Linux64/Release/ez2serial /usr/ezlx/bin

make -B -C /mnt/c/Work200/EZCompany/Linux64

cp /mnt/c/Work200/EZCompany/Linux64/Release/ezcompany /usr/ezlx/bin

make -B -C /mnt/c/Work200/EZConnect/Linux64

cp /mnt/c/Work200/EZConnect/Linux64/Release/ezconnect /usr/ezlx/bin

make -B -C /mnt/c/Work200/EZPing/Linux64

cp /mnt/c/Work200/EZPing/Linux64/Release/ezping /usr/ezlx/bin

make -B -C /mnt/c/Work200/EZExtract/Linux64

cp /mnt/c/Work200/EZExtract/Linux64/Release/ezextract /usr/ezlx/bin

make -B -C /mnt/c/Work200/EZClientDLL/Linux64

cp /mnt/c/Work200/EZClientDLL/Linux64/Release/EZClient.so.1 /usr/ezlx/lib

make -B -C /mnt/c/Work200/EZ2ShellBox/Linux64

cp /mnt/c/Work200/EZ2ShellBox/Linux64/Release/ez2shellbox /usr/ezlx/bin


