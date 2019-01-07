C:
CD \EZServerCE
del GetLogs.log
EZTelnet\EZTelnet -C logs.cmd -O logs\GetLogs.log
NcFTP\NcFTPGet -f EZServerCE.cfg -d logs\GetLogs1.log   \EZServerCE\Logs \Logs.zip
EZTelnet\EZTelnet -C Cleanlogs.cmd -O logs\GetLogs.log
