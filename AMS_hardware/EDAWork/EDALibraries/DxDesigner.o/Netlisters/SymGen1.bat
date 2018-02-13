@echo off

rem Arguments:
rem		%1 - block name

echo generating symbol aaaaa ....
echo need to copy to '%1'

cd sym
if exist aaaaa.pin del aaaaa.pin
if exist %1.pin ren %1.pin %1_temp.pin
if exist %1.pin del %1.pin
if exist %1.1 ren %1.1 %1_temp.1
if exist %1.1 del %1.1
cd bac 
if exist %1.1 del %1.1
cd .. 
cd ..
echo stuff changed

check.exe -s %1
viewgen.exe %1 aaaaa -makesym -noschem -sympinspc 20

cd sym
if exist %1_temp.1 ren %1_temp.1 %1.1
if exist %1_temp.1 del %1_temp.1
if exist %1_temp.pin ren %1_temp.pin %1.pin
if exist %1_temp.pin del %1_temp.pin
cd ..

goto cont

rem -- this is used for ALL netlist versions --
:cont

pause
:done

