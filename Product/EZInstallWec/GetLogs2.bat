C:
CD \Vision
del GetLogs*.log
EZTelnet\EZTelnet -C logs1.cmd -O logs\GetLogs1A.log
NcFTP\NcFTPGet -f Vision.cfg -d logs\GetLogs1B.log   \Vision\Logs \Logs1.zip
EZTelnet\EZTelnet -C logs2.cmd -O logs\GetLogs2A.log
NcFTP\NcFTPGet -f Vision.cfg -d logs\GetLogs2B.log   \Vision\Logs \Logs2.zip
EZTelnet\EZTelnet -C logs3.cmd -O logs\GetLogs3A.log
NcFTP\NcFTPGet -f Vision.cfg -d logs\GetLogs3B.log   \Vision\Logs \Logs3.zip
EZTelnet\EZTelnet -C Cleanlogs.cmd -O logs\GetLogs.log
