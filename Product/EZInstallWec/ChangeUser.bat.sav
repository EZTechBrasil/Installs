if not exist VisionNew.cfg goto exit_user
EZTelnet\EZTelnet -C Stop.cmd -O logs\Stop.log 
EZTelnet\EZTelnet -C ChangeUser.cmd -O logs\ChangeUser.log 
del Vision.cfg
ren VisionNew.Cfg Vision.cfg 
attrib +R Vision.cfg 
exit_user:
exit

