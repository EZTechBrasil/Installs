md \NDFlash\SQLite
delete \NDFlash\SQLite\config.ini
EZExtract export \NDFlash\SQLite\config.ini 
eznet stop EZAuth
eznet stop EZViD
eznet stop CTF
eznet stop EZConnect
eznet stop EZCompany
eznet stop all 
eznet user add EZAdmin EZTechOnly
eznet telnet unlock 
eznet telnet add EZAdmin
eznet telnet lock
eznet FTP unlock 
eznet FTP add EZAdmin
eznet FTP lock
exit


