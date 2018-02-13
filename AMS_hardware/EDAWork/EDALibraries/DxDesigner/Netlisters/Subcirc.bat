@echo off

rem Arguments:
rem		%1 - block name
rem		%2 - CDL or PSPICE

rem if exist .\tech.dat	call :st %1 0 %2 & goto done
rem if exist .\fsm0pt6.dat	call :st %1 1 %2 & goto done
rem if exist .\fsm0pt8.dat	call :st %1 2 %2 & goto done
rem if exist .\fsm3pt0.dat	call :st %1 3 %2 & goto done
rem if exist .\ami_abo.dat	call :st %1 4 %2 & goto done
rem if exist .\uni_bcd3.dat	call :st %1 5 %2 & goto done
rem if exist .\uni_bcd1.dat	call :st %1 6 %2 & goto done

rem echo ***
rem echo  ERROR - there are no *.DAT files in your
rem echo                project directory.
rem echo ***
rem goto done

rem :bolt
rem echo CDL will not go into level BOLT....
rem wspice -ehanzj -c50 -lBOLT %1
rem goto cont

rem :verilog
rem echo CDL will not go into level VERILOG....
rem wspice -ehanzj -c50 -lVERILOG %1
rem goto cont

rem :st
rem if exist level.bolt       goto bolt
rem if exist level.verilog    goto verilog
echo level attribute is ignored....

x:\ece322\schemdev\netlisters\wspicegui.exe -ehnzjq -c12 -kx:\ece322\schemdev\netlisters\cdl.cfg %1 
goto cont

rem -- this is used for ALL netlist versions --
:cont

if exist %1.cir copy %1.cir tempfile.cir
if exist tempfile.sub del tempfile.sub

x:\ece322\schemdev\netlisters\netlister1.pl 

if exist %1.bak del %1.bak
if exist %1.sub ren %1.sub %1.bak
if exist %1.err del %1.err
if exist %1.ndc del %1.ndc
if exist %1.net del %1.net
if exist %1.baf del %1.baf
if exist %1.pkg del %1.pkg
if exist %1.xrf del %1.xrf
if exist %1.rat del %1.rat

copy tempfile.sub %1.sub
del tempfile.cir
del tempfile.sub
del %1.cir

:done

