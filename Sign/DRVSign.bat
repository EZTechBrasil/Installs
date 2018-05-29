%~dp0"inf2cat" /v /driver:.\ /os:XP_X86,Vista_X86,Vista_X64,7_X86,7_X64
%~dp0"signtool" sign /v /ac "%~dp0Go Daddy Class 2 Certification Authority.cer" /n "EZTECH TECNOLOGIA E AUTOMACAO LTDA" /tr http://tsa.starfieldtech.com *.cat
pause