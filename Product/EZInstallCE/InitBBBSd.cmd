eznet stop all 
del \boot\* /s /q 
copy \SDCard\MLO \BOOT
copy \SDCard\EBOOtSD.NB0 \BOOT
copy \SDCard\NK.BIN \BOOT
copy \SDCard\LOGO.BMP \BOOT
diskpartemmc -s \SDCard\diskpartemmc.txt
md \NDFlash\EZForecourt
copy \SDCard\Release\*exe \NDFlash\EZForecourt
exit
