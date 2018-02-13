@echo off

rem Arguments:
rem		%1 - block name
rem		%2 - CDL or PSPICE

rem if %1==SchemDev:* echo here

echo level attribute is ignored....

S:\ece_drive\ECE492\Nick\ICD\netlisters\wspicegui.exe -ehnzjq -c12 -kS:\ece_drive\ECE492\Nick\ICD\netlisters\cdl.cfg %1 
goto cont

rem -- this is used for ALL netlist versions --
:cont

if exist %1.cir copy %1.cir tempfile.cir
if exist tempfile.sub del tempfile.sub

S:\ece_drive\ECE492\Nick\ICD\netlisters\netlister1.pl 

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

copy %1.sub S:\ece_drive\ECE492\Nick\ICD\subcircuits\%1.sub
del %1.sub


:done

