eznet stop all 
del \boot\* /s /q 
copy \SDCard\MLO \BOOT
copy \SDCard\EBOOtSD.NB0 \BOOT
copy \SDCard\NK.BIN \BOOT
copy \SDCard\LOGO.BMP \BOOT
diskpartemmc -s \SDCard\emmc1.txt
diskpartemmc -s \SDCard\emmc2.txt
diskpartemmc -s \SDCard\emmc3.txt
md \NDFlash\EZForecourt
copy \SDCard\Release\*.* \NDFlash\EZForecourt
exit
