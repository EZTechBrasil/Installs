del log*.zip 
del EZCLient*.zip
del config.ini
ezextract export config.ini 
copy config.ini \NDflash\SQLite
ezzip -C logs1.zip *.l?? *.ini \ndflash\log\*.* \NDFLash\EZForecourt\*.ini
exit