C:
CD \EZServerCE
del GetLogs*.log
EZTelnet\EZTelnet -C logs1.cmd -O logs\GetLogs1A.log
NcFTP\NcFTPGet -f EZServerCE.cfg -d logs\GetLogs1B.log   \EZServerCE\Logs \Logs1.zip
EZTelnet\EZTelnet -C logs2.cmd -O logs\GetLogs2A.log
NcFTP\NcFTPGet -f EZServerCE.cfg -d logs\GetLogs2B.log   \EZServerCE\Logs \Logs2.zip
EZTelnet\EZTelnet -C logs3.cmd -O logs\GetLogs3A.log
NcFTP\NcFTPGet -f EZServerCE.cfg -d logs\GetLogs3B.log   \EZServerCE\Logs \Logs3.zip
EZTelnet\EZTelnet -C Cleanlogs.cmd -O logs\GetLogs.log
