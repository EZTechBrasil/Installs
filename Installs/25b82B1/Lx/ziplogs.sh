#!/bin/bash
echo "compressing the logs to ezlxlogs.tar.gz"
rm ezlxlogs.tar.gz
tar -czvf ezlxlogs.tar.gz ./var/log/ ./var/*.ini ./etc/*.ini 
chmod 666 ezlxlogs.tar.gz
echo "all done, bye."
