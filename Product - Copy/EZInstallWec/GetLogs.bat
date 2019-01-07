C:
CD \Vision
del GetLogs.log
EZTelnet\EZTelnet -C logs.cmd -O logs\GetLogs.log
NcFTP\NcFTPGet -f Vision.cfg -d logs\GetLogs1.log   \Vision\Logs \Logs.zip
EZTelnet\EZTelnet -C Cleanlogs.cmd -O logs\GetLogs.log
