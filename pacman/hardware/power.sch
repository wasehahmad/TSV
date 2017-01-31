EESchema Schematic File Version 2
LIBS:pacman-main-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:pacman-main-cache
LIBS:tca9617b
EELAYER 25 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 2 6
Title "Battery Pack Management Computer"
Date "2016-12-13"
Rev "0.8"
Comp "Lafayette College"
Comment1 "Fall Semester 2016"
Comment2 "Supervisor: Christopher Nadovich"
Comment3 "Engineer: Preston Bejabeng"
Comment4 "DEVELOPMENT ONLY"
$EndDescr
$Comp
L NCP1117ST33T3G U9
U 1 1 5574EF3F
P 9150 5050
F 0 "U9" H 9150 5350 40  0000 C CNN
F 1 "NCP1117ST33T3G" H 9150 5250 40  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-223" H 9150 5050 60  0001 C CNN
F 3 "" H 9150 5050 60  0000 C CNN
F 4 "Digikey" H 9150 5050 60  0001 C CNN "Supplier"
F 5 "NCP1117ST33T3GOSCT-ND" H 9150 5050 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/NCP1117ST33T3G/NCP1117ST33T3GOSCT-ND/660708" H 9150 5050 60  0001 C CNN "Supplier URL"
F 7 "ON Semiconductor" H 9150 5050 60  0001 C CNN "Manufacturer"
F 8 "NCP1117ST33T3G" H 9150 5050 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.onsemi.com/pub_link/Collateral/NCP1117-D.PDF" H 9150 5050 60  0001 C CNN "Datasheet URL"
F 10 "IC REG LDO 3.3V 1A SOT223" H 9150 5050 60  0001 C CNN "Description"
F 11 "0.49" H 9150 5050 60  0001 C CNN "Unit Cost"
	1    9150 5050
	1    0    0    -1  
$EndComp
Text Notes 8900 4650 0    60   ~ 0
3.3V Linear Regulator
$Comp
L CP1-RESCUE-pacman-main C16
U 1 1 5574EF8D
P 8100 5200
F 0 "C16" H 8150 5300 50  0000 L CNN
F 1 "220u" H 8150 5100 50  0000 L CNN
F 2 "custom_footprints:c_elec_6.3x7.7" H 8100 5200 60  0001 C CNN
F 3 "" H 8100 5200 60  0000 C CNN
F 4 "Digikey" H 8100 5200 60  0001 C CNN "Supplier"
F 5 "493-6214-1-ND" H 8100 5200 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-search/en?pv7=2&k=UUR1C221MCL6GS&mnonly=0&newproducts=0&ColumnSort=0&page=1&quantity=0&ptm=0&fid=0&pageSize=25" H 8100 5200 60  0001 C CNN "Supplier URL"
F 7 "Nichicon" H 8100 5200 60  0001 C CNN "Manufacturer"
F 8 "UUR1C221MCL6GS" H 8100 5200 60  0001 C CNN "Manufacturer P/N"
F 9 "SMD 16volts 220uF 20% 85C 6.3X7.7" H 8100 5200 60  0001 C CNN "Description"
F 10 ".41" H 8100 5200 60  0001 C CNN "Unit Cost"
	1    8100 5200
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-pacman-main #PWR023
U 1 1 5574EFAB
P 10050 5500
F 0 "#PWR023" H 10050 5500 30  0001 C CNN
F 1 "GND" H 10050 5430 30  0001 C CNN
F 2 "" H 10050 5500 60  0000 C CNN
F 3 "" H 10050 5500 60  0000 C CNN
	1    10050 5500
	1    0    0    -1  
$EndComp
Text Label 10100 1300 2    60   ~ 0
+5V
Text Label 10100 1400 2    60   ~ 0
GND
Text Label 8250 4950 0    60   ~ 0
+5V
Text Label 9950 5000 2    60   ~ 0
+3.3V
Text Label 9900 5400 2    60   ~ 0
GND
$Comp
L PWR_FLAG #FLG024
U 1 1 557BD05E
P 9400 1100
F 0 "#FLG024" H 9400 1195 30  0001 C CNN
F 1 "PWR_FLAG" H 9400 1280 30  0000 C CNN
F 2 "" H 9400 1100 60  0000 C CNN
F 3 "" H 9400 1100 60  0000 C CNN
	1    9400 1100
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG025
U 1 1 557BD201
P 9100 1100
F 0 "#FLG025" H 9100 1195 30  0001 C CNN
F 1 "PWR_FLAG" H 9100 1280 30  0000 C CNN
F 2 "" H 9100 1100 60  0000 C CNN
F 3 "" H 9100 1100 60  0000 C CNN
	1    9100 1100
	1    0    0    -1  
$EndComp
Text HLabel 9850 1750 2    60   BiDi ~ 0
SDA
Text Label 9350 1750 0    60   ~ 0
SDA
Text HLabel 9850 1950 2    60   BiDi ~ 0
SCL
Text Label 9350 1950 0    60   ~ 0
SCL
$Comp
L Si8600 U8
U 1 1 559EAA55
P 8300 3800
F 0 "U8" H 8300 3850 60  0000 C CNN
F 1 "Si8600" H 8300 3750 60  0000 C CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 8300 3800 60  0001 C CNN
F 3 "" H 8300 3800 60  0000 C CNN
F 4 "Digikey" H 8300 3800 60  0001 C CNN "Supplier"
F 5 "336-2048-5-ND" H 8300 3800 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/silicon-labs/SI8600AC-B-IS/336-2048-5-ND/2623281" H 8300 3800 60  0001 C CNN "Supplier URL"
F 7 "Silicon Labs" H 8300 3800 60  0001 C CNN "Manufacturer"
F 8 "Si8600AC-B-IS" H 8300 3800 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.silabs.com/Support%20Documents/TechnicalDocs/Si860x.pdf" H 8300 3800 60  0001 C CNN "Datasheet URL"
F 10 "3.75kV Bidirect I2C Isolator 1.7MHz" H 8300 3800 60  0001 C CNN "Description"
F 11 "2.96" H 8300 3800 60  0001 C CNN "Unit Cost"
	1    8300 3800
	1    0    0    -1  
$EndComp
$Comp
L C-RESCUE-pacman-main C13
U 1 1 559EAEEF
P 6900 3800
F 0 "C13" H 6925 3900 50  0000 L CNN
F 1 "0.1u" H 6925 3700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 6938 3650 30  0001 C CNN
F 3 "" H 6900 3800 60  0000 C CNN
	1    6900 3800
	1    0    0    -1  
$EndComp
Text Label 7100 4100 0    60   ~ 0
HV_GND
Text Label 7100 3700 0    60   ~ 0
SDA_HV
Text Label 7100 3900 0    60   ~ 0
SCL_HV
Text Label 9500 3500 2    60   ~ 0
+3.3V
Text Label 9500 4100 2    60   ~ 0
GND
Text Label 9500 3700 2    60   ~ 0
SDA
Text Label 9500 3900 2    60   ~ 0
SCL
$Comp
L C-RESCUE-pacman-main C17
U 1 1 559EB3D2
P 9700 3800
F 0 "C17" H 9725 3900 50  0000 L CNN
F 1 "0.1u" H 9725 3700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 9738 3650 30  0001 C CNN
F 3 "" H 9700 3800 60  0000 C CNN
	1    9700 3800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR026
U 1 1 559EB72A
P 9700 4200
F 0 "#PWR026" H 9700 3950 50  0001 C CNN
F 1 "GND" H 9700 4050 50  0000 C CNN
F 2 "" H 9700 4200 60  0000 C CNN
F 3 "" H 9700 4200 60  0000 C CNN
	1    9700 4200
	1    0    0    -1  
$EndComp
Text Label 7100 3500 0    60   ~ 0
5V_HV
Text Notes 5900 4650 0    100  ~ 0
HIGH VOLTAGE
Text Notes 7200 4650 0    100  ~ 0
LOW VOLTAGE
Text Notes 8400 650  0    100  ~ 0
LOW VOLTAGE
Text Notes 650  3450 0    100  ~ 0
PACK VOLTAGE SENSOR\nAND CHARGE SENSOR
Text Label 5575 3200 0    60   ~ 0
5V_HV
Text Label 6900 1100 0    60   ~ 0
AMS_RESET
Text Label 1900 1700 2    60   ~ 0
SCL_HV
Text Label 1900 1550 2    60   ~ 0
SDA_HV
Text Label 1900 1100 2    60   ~ 0
PACK-
Text Label 1900 950  2    60   ~ 0
PACK+
$Comp
L +5V #PWR027
U 1 1 560CFE2A
P 8250 4900
F 0 "#PWR027" H 8250 4750 50  0001 C CNN
F 1 "+5V" H 8250 5040 50  0000 C CNN
F 2 "" H 8250 4900 60  0000 C CNN
F 3 "" H 8250 4900 60  0000 C CNN
	1    8250 4900
	1    0    0    -1  
$EndComp
$Comp
L PCF8574A U3
U 1 1 560B0C11
P 2950 6650
F 0 "U3" H 2600 7250 50  0000 L CNN
F 1 "PCF8574A" H 3050 7250 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-16_7.5x10.3mm_Pitch1.27mm" H 2950 6650 60  0001 C CNN
F 3 "" H 2950 6650 60  0000 C CNN
F 4 "Digikey" H 2950 6650 60  0001 C CNN "Supplier"
F 5 "568-1074-1-ND" H 2950 6650 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/PCF8574AT%2F3518/568-1074-1-ND/735790" H 2950 6650 60  0001 C CNN "Supplier URL"
F 7 "NXP Semiconductors" H 2950 6650 60  0001 C CNN "Manufacturer"
F 8 "PCF8574AT3518" H 2950 6650 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.nxp.com/documents/data_sheet/PCF8574_PCF8574A.pdf" H 2950 6650 60  0001 C CNN "Datasheet URL"
F 10 "IC I/O EXPANDER I2C 8B 16SOIC" H 2950 6650 60  0001 C CNN "Description"
F 11 "1.22" H 2950 6650 60  0001 C CNN "Unit Cost"
	1    2950 6650
	-1   0    0    -1  
$EndComp
$Comp
L LTC3638 U6
U 1 1 560E8451
P 5900 2000
F 0 "U6" H 5900 2150 60  0000 C CNN
F 1 "LTC3638" H 5900 2000 60  0000 C CNN
F 2 "custom_footprints:TSSOP16_LTC3638" H 5900 2000 60  0001 C CNN
F 3 "" H 5900 2000 60  0000 C CNN
F 4 "Digikey" H 5900 2000 60  0001 C CNN "Supplier"
F 5 "LTC3638EMSE#PBF-ND" H 5900 2000 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/LTC3638EMSE%23PBF/LTC3638EMSE%23PBF-ND/4693775" H 5900 2000 60  0001 C CNN "Supplier URL"
F 7 "Linear Technology" H 5900 2000 60  0001 C CNN "Manufacturer"
F 8 "LTC3638EMSE#PBF" H 5900 2000 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.linear.com/docs/44312" H 5900 2000 60  0001 C CNN "Datasheet URL"
F 10 "IC REG BUCK ADJ 0.25A 16MSOP" H 5900 2000 60  0001 C CNN "Description"
F 11 "7.79" H 5900 2000 60  0001 C CNN "Unit Cost"
	1    5900 2000
	1    0    0    -1  
$EndComp
$Comp
L C-RESCUE-pacman-main C11
U 1 1 560E8698
P 4200 2150
F 0 "C11" H 4200 2250 40  0000 L CNN
F 1 "1u" H 4206 2065 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4238 2000 30  0001 C CNN
F 3 "" H 4200 2150 60  0000 C CNN
F 4 "Digikey" H 4200 2150 60  0001 C CNN "Supplier"
F 5 "1276-1860-1-ND" H 4200 2150 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/samsung-electro-mechanics-america-inc/CL10A105KB8NNNC/1276-1860-1-ND/3889946" H 4200 2150 60  0001 C CNN "Supplier URL"
F 7 "Samsung Electro-Mechanics America, Inc." H 4200 2150 60  0001 C CNN "Manufacturer"
F 8 "CL10A105KB8NNNC" H 4200 2150 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.samsungsem.com/kr/support/product-search/mlcc/__icsFiles/afieldfile/2016/08/18/S_CL10A105KB8NNNC.pdf" H 4200 2150 60  0001 C CNN "Datasheet URL"
F 10 "1µF 50V Ceramic Capacitor X5R 0603 (1608 Metric) 0.063\" L x 0.031\" W (1.60mm x 0.80mm)" H 4200 2150 60  0001 C CNN "Description"
F 11 "0.14" H 4200 2150 60  0001 C CNN "Unit Cost"
	1    4200 2150
	1    0    0    -1  
$EndComp
$Comp
L INDUCTOR-RESCUE-pacman-main L1
U 1 1 560E9174
P 7100 1700
F 0 "L1" V 7200 1700 50  0000 C CNN
F 1 "220u" V 7050 1700 50  0000 C CNN
F 2 "custom_footprints:SELF-WE-TPC_M" H 7100 1700 60  0001 C CNN
F 3 "" H 7100 1700 60  0000 C CNN
F 4 "Digikey" H 7100 1700 60  0001 C CNN "Supplier"
F 5 "445-173047-1-ND" H 7100 1700 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/VLS6045EX-221M/445-173047-1-ND/5287389" H 7100 1700 60  0001 C CNN "Supplier URL"
F 7 "TDK Corporation" H 7100 1700 60  0001 C CNN "Manufacturer"
F 8 "VLS6045EX-221M" H 7100 1700 60  0001 C CNN "Manufacturer P/N"
F 9 "http://product.tdk.com/en/catalog/datasheets/inductor_commercial_power_vls6045ex_en.pdf" H 7100 1700 60  0001 C CNN "Datasheet URL"
F 10 "FIXED IND 220UH 500MA 1.15 MOHM" H 7100 1700 60  0001 C CNN "Description"
F 11 "0.52" H 7100 1700 60  0001 C CNN "Unit Cost"
	1    7100 1700
	0    -1   -1   0   
$EndComp
$Comp
L DIODESCH D6
U 1 1 560E9E47
P 6700 2200
F 0 "D6" H 6700 2300 40  0000 C CNN
F 1 "SK310A-LTP" H 6700 2100 40  0000 C CNN
F 2 "custom_footprints:do214ac" H 6700 2200 60  0001 C CNN
F 3 "" H 6700 2200 60  0000 C CNN
F 4 "Digikey" H 6700 2200 60  0001 C CNN "Supplier"
F 5 "SK310A-LTPMSCT-ND" H 6700 2200 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/SK310A-LTP/SK310A-LTPMSCT-ND/2642066" H 6700 2200 60  0001 C CNN "Supplier URL"
F 7 "Micro Commercial Components (MMC)" H 6700 2200 60  0001 C CNN "Manufacturer"
F 8 "SK310A-LTP" H 6700 2200 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.mccsemi.com/up_pdf/SK32A-LT~SK310A-LT%28DO-214AC%29.PDF" H 6700 2200 60  0001 C CNN "Datasheet URL"
F 10 "Schottky Diodes & Rectifiers DIODE SCHOTTKY 100V 3A DO214AC " H 6700 2200 60  0001 C CNN "Description"
F 11 "0.57" H 6700 2200 60  0001 C CNN "Unit Cost"
	1    6700 2200
	0    -1   -1   0   
$EndComp
$Comp
L C-RESCUE-pacman-main C15
U 1 1 560EA637
P 7500 2200
F 0 "C15" H 7500 2300 40  0000 L CNN
F 1 "10u" H 7506 2115 40  0000 L CNN
F 2 "Capacitors_SMD:C_1210_HandSoldering" H 7538 2050 30  0001 C CNN
F 3 "" H 7500 2200 60  0000 C CNN
F 4 "Digikey" H 7500 2200 60  0001 C CNN "Supplier"
F 5 "490-1891-1-ND" H 7500 2200 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/GRM32DF51H106ZA01L/490-1891-1-ND/587282" H 7500 2200 60  0001 C CNN "Supplier URL"
F 7 "Murata Electronics" H 7500 2200 60  0001 C CNN "Manufacturer"
F 8 "GRM32DF51H106ZA01L" H 7500 2200 60  0001 C CNN "Manufacturer P/N"
F 9 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRM32DF51H106ZA01-01.pdf" H 7500 2200 60  0001 C CNN "Datasheet URL"
F 10 "CAP CER 10UF 50V Y5V 1210" H 7500 2200 60  0001 C CNN "Description"
F 11 "0.61" H 7500 2200 60  0001 C CNN "Unit Cost"
	1    7500 2200
	1    0    0    -1  
$EndComp
Text Label 2400 2600 0    60   ~ 0
HV_GND
Text Label 2400 1700 2    60   ~ 0
PACK+
Text Label 7900 2600 2    60   ~ 0
HV_GND
Text Label 7900 1700 2    60   ~ 0
5V_HV
Text Notes 3550 850  0    100  ~ 0
HIGH VOLTAGE POWER
Text Label 6900 900  0    60   ~ 0
5V_HV
Text Label 1900 1400 2    60   ~ 0
~CHRG_DET
Text Label 700  2550 0    60   ~ 0
HV_GND
Text Label 1150 2550 0    60   ~ 0
PACK-
Text Notes 7150 650  0    100  ~ 0
HIGH VOLTAGE
Text Label 2600 5850 0    60   ~ 0
5V_HV
Text Label 3300 7450 2    60   ~ 0
HV_GND
Text Label 3950 6350 2    60   ~ 0
SDA_HV
Text Label 3950 6250 2    60   ~ 0
SCL_HV
Text Label 3950 6550 2    60   ~ 0
HV_GND
Text Label 3950 6650 2    60   ~ 0
HV_GND
Text Label 3950 6750 2    60   ~ 0
HV_GND
Text Notes 4675 6175 0    60   ~ 0
The flyback regulator responsible for delivering\n5V isolated power to low voltage systems has been\nreplaced with an isolated DC/DC converter. This\nis due to the insufficient output current (300mA)\navailable when assembled.  Cost is comparable.
Text Label 4950 5350 2    60   ~ 0
HV_GND
Text Label 1050 6250 0    60   ~ 0
~CHRG_DET
Text Label 4950 5000 2    60   ~ 0
HV_PWR
$Comp
L R-RESCUE-pacman-main R20
U 1 1 5613543A
P 6175 3750
F 0 "R20" V 6255 3750 40  0000 C CNN
F 1 "1k" V 6182 3751 40  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6105 3750 30  0001 C CNN
F 3 "" H 6175 3750 30  0000 C CNN
	1    6175 3750
	-1   0    0    1   
$EndComp
$Comp
L R-RESCUE-pacman-main R19
U 1 1 56135999
P 5975 3750
F 0 "R19" V 6055 3750 40  0000 C CNN
F 1 "1k" V 5982 3751 40  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5905 3750 30  0001 C CNN
F 3 "" H 5975 3750 30  0000 C CNN
	1    5975 3750
	-1   0    0    1   
$EndComp
Text Notes 675  675  0    100  ~ 0
HIGH VOLTAGE INTERFACES
Text Notes 1550 5375 0    100  ~ 0
HIGH VOLTAGE DIGITAL I/O
Text Notes 5325 3050 0    100  ~ 0
I2C PULLUP
Text Label 5575 4100 0    60   ~ 0
SDA_HV
Text Label 5575 4300 0    60   ~ 0
SCL_HV
Text Notes 7550 3400 0    60   ~ 0
5mA
Text Notes 8850 3400 0    60   ~ 0
5mA
Text Notes 5250 1550 0    60   ~ 0
350uA
Text Notes 3050 6000 0    60   ~ 0
40uA
Text Notes 5675 3550 0    60   ~ 0
1mA
Text Label 1050 6350 0    60   ~ 0
AMS_RESET
Text Label 4700 4400 2    60   ~ 0
HV_GND
Text Label 3700 3200 0    60   ~ 0
5V_HV
NoConn ~ 4800 3700
Text Label 5300 4000 2    60   ~ 0
SCL_HV
Text Label 5300 3900 2    60   ~ 0
SDA_HV
Text Label 5300 3600 2    60   ~ 0
HV_GND
Text Notes 3700 3050 0    60   ~ 0
I2C Address 0x48\n(see datasheet page 14)
$Comp
L C-RESCUE-pacman-main C8
U 1 1 561A469B
P 3050 3150
F 0 "C8" H 3050 3250 40  0000 L CNN
F 1 "0.1u" H 3056 3065 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 3088 3000 30  0001 C CNN
F 3 "" H 3050 3150 60  0000 C CNN
	1    3050 3150
	1    0    0    -1  
$EndComp
Text Label 3450 3450 2    60   ~ 0
HV_GND
Text Notes 3050 5850 0    60   ~ 0
I2C Address 0x40\n(see datasheet page 13)
Text Notes 1450 5700 0    60   ~ 0
This I/O expander is responsible for relaying\ndigital signals accross the HV-LV isolation barrier\nvia the I2C bus.
Text Notes 7000 3150 0    100  ~ 0
I2C ISOLATOR
Text Notes 2850 1350 0    60   ~ 0
This power supply is responsible for delivering non-isolated 5V\npower to the high voltage electronics. All AMS bus connected\ndevices are powered from this regulator. Maximum current draw\n250mA. This Switcher was selected for its high efficiency even at light load.
Text Notes 7250 5825 0    60   ~ 0
\nMaximum Current Draw on 5V output: 1.2A
NoConn ~ 3450 7050
Text Label 700  2900 0    60   ~ 0
5V_HV
$Comp
L PWR_FLAG #FLG028
U 1 1 561C66F4
P 1750 2800
F 0 "#FLG028" H 1750 2895 30  0001 C CNN
F 1 "PWR_FLAG" H 1750 2980 30  0000 C CNN
F 2 "" H 1750 2800 60  0000 C CNN
F 3 "" H 1750 2800 60  0000 C CNN
	1    1750 2800
	1    0    0    -1  
$EndComp
$Comp
L CP1 C10
U 1 1 56149C59
P 3700 2325
F 0 "C10" H 3725 2425 50  0000 L CNN
F 1 "220u" H 3725 2225 50  0000 L CNN
F 2 "custom_footprints:c_elec_10x10" H 3700 2325 60  0001 C CNN
F 3 "" H 3700 2325 60  0000 C CNN
F 4 "Digikey" H 3700 2325 60  0001 C CNN "Supplier"
F 5 "493-9426-1-ND" H 3700 2325 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/UCW1H221MNL1GS/493-9426-1-ND/3962774" H 3700 2325 60  0001 C CNN "Supplier URL"
F 7 "Nichion" H 3700 2325 60  0001 C CNN "Manufacturer"
F 8 "UCW1H221MNL1GS" H 3700 2325 60  0001 C CNN "Manufacturer P/N"
F 9 "CAP ALUM 220UF 20% 50V SMD" H 3700 2325 60  0001 C CNN "Description"
F 10 "0.79" H 3700 2325 60  0001 C CNN "Unit Cost"
	1    3700 2325
	1    0    0    -1  
$EndComp
$Comp
L DIODESCH D5
U 1 1 5614A4E6
P 3300 1700
F 0 "D5" H 3300 1800 40  0000 C CNN
F 1 "SK310A-LTP" H 3300 1600 40  0000 C CNN
F 2 "custom_footprints:do214ac" H 3300 1700 60  0001 C CNN
F 3 "" H 3300 1700 60  0000 C CNN
F 4 "Digikey" H 3300 1700 60  0001 C CNN "Supplier"
F 5 "SK310A-LTPMSCT-ND" H 3300 1700 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/SK310A-LTP/SK310A-LTPMSCT-ND/2642066" H 3300 1700 60  0001 C CNN "Supplier URL"
F 7 "Micro Commercial Components (MMC)" H 3300 1700 60  0001 C CNN "Manufacturer"
F 8 "SK310A-LTP" H 3300 1700 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.mccsemi.com/up_pdf/SK32A-LT~SK310A-LT%28DO-214AC%29.PDF" H 3300 1700 60  0001 C CNN "Datasheet URL"
F 10 "Schottky Diodes & Rectifiers DIODE SCHOTTKY 100V 3A DO214AC " H 3300 1700 60  0001 C CNN "Description"
F 11 "0.57" H 3300 1700 60  0001 C CNN "Unit Cost"
	1    3300 1700
	1    0    0    -1  
$EndComp
Text Label 3550 1700 0    60   ~ 0
HV_PWR
$Comp
L PWR_FLAG #FLG029
U 1 1 5616DCE6
P 1750 2450
F 0 "#FLG029" H 1750 2545 30  0001 C CNN
F 1 "PWR_FLAG" H 1750 2630 30  0000 C CNN
F 2 "" H 1750 2450 60  0000 C CNN
F 3 "" H 1750 2450 60  0000 C CNN
	1    1750 2450
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG030
U 1 1 5616ED66
P 3950 1600
F 0 "#FLG030" H 3950 1695 30  0001 C CNN
F 1 "PWR_FLAG" H 3950 1780 30  0000 C CNN
F 2 "" H 3950 1600 60  0000 C CNN
F 3 "" H 3950 1600 60  0000 C CNN
	1    3950 1600
	1    0    0    -1  
$EndComp
Text Notes 3100 2950 0    60   ~ 0
Bypass \nCapacitor \n(U5)
$Comp
L DIODESCH D9
U 1 1 561F2090
P 7800 5000
F 0 "D9" H 7800 5100 40  0000 C CNN
F 1 "SK310A-LTP" H 7800 4900 40  0000 C CNN
F 2 "custom_footprints:do214ac" H 7800 5000 60  0001 C CNN
F 3 "" H 7800 5000 60  0000 C CNN
F 4 "Digikey" H 7800 5000 60  0001 C CNN "Supplier"
F 5 "SK310A-LTPMSCT-ND" H 7800 5000 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/SK310A-LTP/SK310A-LTPMSCT-ND/2642066" H 7800 5000 60  0001 C CNN "Supplier URL"
F 7 "Micro Commercial Components (MMC)" H 7800 5000 60  0001 C CNN "Manufacturer"
F 8 "SK310A-LTP" H 7800 5000 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.mccsemi.com/up_pdf/SK32A-LT~SK310A-LT%28DO-214AC%29.PDF" H 7800 5000 60  0001 C CNN "Datasheet URL"
F 10 "Schottky Diodes & Rectifiers DIODE SCHOTTKY 100V 3A DO214AC " H 7800 5000 60  0001 C CNN "Description"
F 11 "0.57" H 7800 5000 60  0001 C CNN "Unit Cost"
	1    7800 5000
	1    0    0    -1  
$EndComp
NoConn ~ 2450 6650
NoConn ~ 2450 6750
NoConn ~ 2450 6850
NoConn ~ 2450 6950
$Comp
L R-RESCUE-pacman-main R10
U 1 1 5617C752
P 1400 5950
F 0 "R10" V 1480 5950 40  0000 C CNN
F 1 "10k" V 1407 5951 40  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1330 5950 30  0001 C CNN
F 3 "" H 1400 5950 30  0000 C CNN
	1    1400 5950
	0    -1   -1   0   
$EndComp
Text Label 750  5950 0    60   ~ 0
5V_HV
$Comp
L +3.3V #PWR031
U 1 1 56259511
P 10050 4900
F 0 "#PWR031" H 10050 4750 50  0001 C CNN
F 1 "+3.3V" H 10050 5040 50  0000 C CNN
F 2 "" H 10050 4900 60  0000 C CNN
F 3 "" H 10050 4900 60  0000 C CNN
	1    10050 4900
	1    0    0    -1  
$EndComp
Text GLabel 1100 950  0    50   Input ~ 0
PACK+
Text GLabel 1100 1100 0    50   Input ~ 0
PACK-
Text GLabel 7700 900  2    50   Output ~ 0
5V_HV
Text GLabel 7700 1100 2    50   Output ~ 0
AMS_RESET
Text GLabel 1100 1400 0    50   Input ~ 0
~CHRG_DET
Text GLabel 1100 1550 0    50   Input ~ 0
SDA_HV
Text GLabel 1100 1700 0    50   Input ~ 0
SCL_HV
$Comp
L C-RESCUE-pacman-main C22
U 1 1 56251D56
P 4300 7500
F 0 "C22" H 4300 7600 40  0000 L CNN
F 1 "0.1u" H 4306 7415 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4338 7350 30  0001 C CNN
F 3 "" H 4300 7500 60  0000 C CNN
	1    4300 7500
	1    0    0    -1  
$EndComp
Text Label 4700 7800 2    60   ~ 0
HV_GND
Text Notes 4450 7600 0    60   ~ 0
Bypass \nCapacitor \n(U3)
Text Label 3900 7200 0    60   ~ 0
5V_HV
$Comp
L C-RESCUE-pacman-main C23
U 1 1 56252980
P 2800 3150
F 0 "C23" H 2800 3250 40  0000 L CNN
F 1 "0.1u" H 2806 3065 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 2838 3000 30  0001 C CNN
F 3 "" H 2800 3150 60  0000 C CNN
	1    2800 3150
	1    0    0    -1  
$EndComp
Text Notes 2300 3150 0    60   ~ 0
Bypass \nCapacitor \n(U4)
$Comp
L ADS1015 U5
U 1 1 56C794D3
P 4200 3800
F 0 "U5" H 4200 3850 60  0000 C CNN
F 1 "ADS1115" H 4200 3750 60  0000 C CNN
F 2 "custom_footprints:msop_10_ads1015" H 4200 3850 60  0001 C CNN
F 3 "" H 4200 3850 60  0000 C CNN
F 4 "Digikey" H 4200 3800 60  0001 C CNN "Supplier"
F 5 "296-38849-1-ND" H 4200 3800 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/texas-instruments/ADS1115IDGSR/296-38849-1-ND/5142969" H 4200 3800 60  0001 C CNN "Supplier URL"
F 7 "Texas Instruments" H 4200 3800 60  0001 C CNN "Manufacturer"
F 8 "ADS1115IDGSR" H 4200 3800 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.ti.com/lit/ds/symlink/ads1113.pdf" H 4200 3800 60  0001 C CNN "Datasheet URL"
F 10 "IC ADC 16BIT 860SPS LP 10MSOP" H 4200 3800 60  0001 C CNN "Description"
F 11 "5.65" H 4200 3800 60  0001 C CNN "Unit Cost"
	1    4200 3800
	1    0    0    -1  
$EndComp
Text Label 2300 2850 0    60   ~ 0
5V_HV
$Comp
L C-RESCUE-pacman-main C24
U 1 1 56C84061
P 8400 5200
F 0 "C24" H 8400 5300 40  0000 L CNN
F 1 "0.1u" H 8406 5115 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 8438 5050 30  0001 C CNN
F 3 "" H 8400 5200 60  0000 C CNN
F 4 "Digikey" H 8400 5200 60  0001 C CNN "Supplier"
F 5 "?" H 8400 5200 60  0001 C CNN "Supplier P/N"
	1    8400 5200
	1    0    0    -1  
$EndComp
$Comp
L ZENER-RESCUE-pacman-main D20
U 1 1 56C84F96
P 8700 5200
AR Path="/56C84F96" Ref="D20"  Part="1" 
AR Path="/5574E706/56C84F96" Ref="D20"  Part="1" 
F 0 "D20" H 8700 5300 50  0000 C CNN
F 1 "NZH5V1B" H 8700 5100 39  0000 C CNN
F 2 "footprints:sod123" H 8700 5200 60  0001 C CNN
F 3 "" H 8700 5200 60  0001 C CNN
F 4 "Digikey" H 8700 5200 60  0001 C CNN "Supplier"
F 5 "568-6370-1-ND" H 8700 5200 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/NZH5V1B115/568-6370-1-ND/2531657" H 8700 5200 60  0001 C CNN "Supplier URL"
F 7 "NXP Semiconductors" H 8700 5200 60  0001 C CNN "Manufacturer"
F 8 "NZH5V1B" H 8700 5200 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.nxp.com/documents/data_sheet/NZH_SER.pdf" H 8700 5200 60  0001 C CNN "Datasheet URL"
F 10 "DIODE ZENER 5.1V 500MW SOD123F" H 8700 5200 60  0001 C CNN "Description"
F 11 "0.20" H 8700 5200 60  0001 C CNN "Unit Cost"
	1    8700 5200
	0    1    1    0   
$EndComp
Text GLabel 1350 2000 0    60   Input ~ 0
CURRENT_HV_1
Text GLabel 1350 2150 0    60   Input ~ 0
CURRENT_HV_2
Text Label 1900 2000 2    60   ~ 0
AMPS_1
Text Label 1900 2150 2    60   ~ 0
AMPS_2
Text Label 2950 3700 0    60   ~ 0
AMPS_2
Text Label 2950 3600 0    60   ~ 0
AMPS_1
$Comp
L INA_226 U4
U 1 1 56D798E2
P 1750 4200
F 0 "U4" H 1750 4250 60  0000 C CNN
F 1 "INA_226" H 1750 4150 60  0000 C CNN
F 2 "custom_footprints:msop_10_ads1015" H 1750 4250 60  0001 C CNN
F 3 "" H 1750 4250 60  0000 C CNN
F 4 "Digikey" H 1750 4200 60  0001 C CNN "Supplier"
F 5 "296-29034-1-ND" H 1750 4200 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-search/en?keywords=296-29034-1-ND" H 1750 4200 60  0001 C CNN "Supplier URL"
F 7 "Texas Instruments" H 1750 4200 60  0001 C CNN "Manufacturer"
F 8 "INA226AIDGSR" H 1750 4200 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.ti.com/lit/ds/symlink/ina226.pdf" H 1750 4200 60  0001 C CNN "Datasheet URL"
F 10 "3.44" H 1750 4200 60  0001 C CNN "Unit Cost"
	1    1750 4200
	1    0    0    -1  
$EndComp
Text Label 2900 4300 2    60   ~ 0
SDA_HV
Text Label 2900 4400 2    60   ~ 0
SCL_HV
Text Label 1250 3600 0    60   ~ 0
5V_HV
Text Label 2900 4700 2    60   ~ 0
HV_GND
NoConn ~ 1150 4000
Text Notes 1200 5200 0    60   ~ 0
I2C Address 0x44\n(see datasheet page 18)\nAdditional documentation\nof the use of this component\n is req'd.
$Comp
L R R3
U 1 1 56D7B790
P 750 4250
F 0 "R3" V 830 4250 50  0000 C CNN
F 1 "0.001 1%" V 750 4250 39  0000 C CNN
F 2 "custom_footprints:CSNL1206" H 680 4250 30  0001 C CNN
F 3 "" H 750 4250 30  0000 C CNN
F 4 "Digikey" V 750 4250 60  0001 C CNN "Supplier"
F 5 "CSNL1206FT1L00CT-ND" V 750 4250 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/stackpole-electronics-inc/CSNL1206FT1L00/CSNL1206FT1L00CT-ND/1788120" V 750 4250 60  0001 C CNN "Supplier URL"
F 7 "Stackpole Electronics" V 750 4250 60  0001 C CNN "Manufacturer"
F 8 "CSNL1206FT1L00" V 750 4250 60  0001 C CNN "Manufacturer P/N"
F 9 "https://www.seielect.com/Catalog/SEI-csnl.pdf" V 750 4250 60  0001 C CNN "Datasheet URL"
F 10 "RES SMD 0.001 OHM 1% 1W 1206" V 750 4250 60  0001 C CNN "Description"
F 11 "0.65" V 750 4250 60  0001 C CNN "Unit Cost"
	1    750  4250
	1    0    0    -1  
$EndComp
Connection ~ 3050 3450
Wire Wire Line
	2800 3300 2800 3450
Wire Wire Line
	4300 7800 4700 7800
Wire Wire Line
	4300 7650 4300 7800
Wire Wire Line
	4300 7200 3900 7200
Wire Wire Line
	4300 7200 4300 7350
Wire Wire Line
	5200 2100 5200 2600
Wire Wire Line
	5200 1700 5200 1900
Wire Notes Line
	7100 4400 7100 4650
Wire Notes Line
	8300 4400 7100 4400
Connection ~ 1650 6250
Wire Wire Line
	1650 5950 1650 6250
Wire Wire Line
	1150 5950 750  5950
Connection ~ 3950 1700
Wire Wire Line
	3950 1700 3950 1600
Wire Wire Line
	1750 2550 1750 2450
Wire Notes Line
	8300 3350 8300 500 
Connection ~ 3700 2600
Wire Wire Line
	3700 2475 3700 2600
Wire Wire Line
	1750 2900 1750 2800
Wire Wire Line
	700  2900 1750 2900
Wire Wire Line
	2800 3450 3450 3450
Wire Wire Line
	3050 3300 3050 3450
Wire Wire Line
	4800 3600 5300 3600
Wire Wire Line
	5300 3900 4800 3900
Wire Wire Line
	4800 4000 5300 4000
Wire Wire Line
	4200 4400 4200 4300
Wire Wire Line
	3550 4400 4700 4400
Wire Wire Line
	4200 3200 3700 3200
Wire Wire Line
	4200 3300 4200 3200
Wire Wire Line
	2450 6350 1050 6350
Wire Wire Line
	6175 4300 5575 4300
Wire Wire Line
	6175 4000 6175 4300
Wire Wire Line
	5975 4100 5575 4100
Wire Wire Line
	5975 4000 5975 4100
Wire Wire Line
	6175 3200 6175 3500
Wire Wire Line
	1050 6250 2450 6250
Wire Wire Line
	1100 1400 1900 1400
Wire Wire Line
	3450 6750 3950 6750
Wire Wire Line
	3450 6650 3950 6650
Wire Wire Line
	3450 6550 3950 6550
Wire Wire Line
	3450 6250 3950 6250
Wire Wire Line
	3450 6350 3950 6350
Wire Wire Line
	2950 7450 3300 7450
Wire Wire Line
	2950 7350 2950 7450
Wire Wire Line
	2950 5850 1900 5850
Wire Wire Line
	2950 5950 2950 5850
Wire Wire Line
	700  2550 1750 2550
Wire Wire Line
	7700 900  6900 900 
Connection ~ 7500 2600
Connection ~ 7500 1700
Connection ~ 6700 2600
Wire Wire Line
	7500 2600 7500 2350
Connection ~ 7500 1900
Wire Wire Line
	6400 1900 7750 1900
Wire Wire Line
	7500 1700 7500 2050
Wire Wire Line
	7400 1700 7900 1700
Wire Wire Line
	6700 2600 6700 2400
Connection ~ 6700 1700
Wire Wire Line
	6700 1700 6700 2000
Wire Wire Line
	6500 2100 6400 2100
Wire Wire Line
	6500 2300 6500 2100
Wire Wire Line
	6400 2300 6500 2300
Wire Wire Line
	6400 1700 6800 1700
Wire Wire Line
	2400 2600 7900 2600
Wire Wire Line
	5200 2100 5400 2100
Wire Wire Line
	5200 1900 5400 1900
Wire Wire Line
	1100 950  1900 950 
Wire Wire Line
	1100 1100 1900 1100
Wire Wire Line
	7700 1100 6900 1100
Wire Wire Line
	1100 1700 1900 1700
Wire Wire Line
	1100 1550 1900 1550
Connection ~ 5975 3200
Wire Wire Line
	5575 3200 6175 3200
Wire Wire Line
	5975 3500 5975 3200
Wire Notes Line
	7100 7050 7100 5450
Wire Notes Line
	8300 4400 8300 4250
Connection ~ 9700 4100
Wire Wire Line
	9700 3950 9700 4200
Wire Wire Line
	9700 3500 9700 3650
Wire Wire Line
	9700 4100 9000 4100
Wire Wire Line
	9000 3900 9500 3900
Wire Wire Line
	9000 3700 9500 3700
Wire Wire Line
	9700 3500 9000 3500
Wire Wire Line
	6900 3950 6900 4100
Wire Wire Line
	6900 3500 6900 3650
Wire Wire Line
	6450 4100 7600 4100
Wire Wire Line
	7600 3900 7100 3900
Wire Wire Line
	7600 3700 7100 3700
Wire Wire Line
	6450 3500 7600 3500
Wire Wire Line
	9850 1950 9350 1950
Wire Wire Line
	9850 1750 9350 1750
Wire Wire Line
	9100 1400 9100 1100
Wire Wire Line
	9100 1400 10100 1400
Wire Wire Line
	9400 1300 9400 1100
Wire Wire Line
	9400 1300 10100 1300
Wire Wire Line
	7350 5000 7600 5000
Connection ~ 8100 5400
Connection ~ 8100 5000
Wire Wire Line
	8000 5000 8750 5000
Connection ~ 9600 5400
Wire Wire Line
	10050 5400 10050 5500
Wire Wire Line
	7500 5400 10050 5400
Wire Wire Line
	10050 5000 10050 4900
Wire Wire Line
	3600 3900 3550 3900
Wire Wire Line
	2950 3600 3600 3600
Wire Wire Line
	3600 3700 2950 3700
Wire Wire Line
	4200 1700 4200 2000
Connection ~ 4200 1700
Wire Wire Line
	4200 2600 4200 2300
Connection ~ 4200 2600
Wire Wire Line
	2300 2850 3050 2850
Connection ~ 2800 2850
Wire Wire Line
	3050 2850 3050 3000
Wire Wire Line
	2800 2850 2800 3000
Wire Wire Line
	8250 4900 8250 5000
Connection ~ 8250 5000
Wire Wire Line
	8400 5050 8400 5000
Connection ~ 8400 5000
Wire Wire Line
	8400 5350 8400 5400
Connection ~ 8400 5400
Wire Wire Line
	9550 5000 10050 5000
Wire Wire Line
	9600 5050 9600 5000
Connection ~ 9600 5000
Wire Wire Line
	9600 5350 9600 5400
Wire Wire Line
	9150 5300 9150 5400
Connection ~ 9150 5400
Connection ~ 8700 5400
Connection ~ 8700 5000
Wire Wire Line
	1350 2000 1900 2000
Wire Wire Line
	1350 2150 1900 2150
Wire Wire Line
	3550 3900 3550 4400
Wire Wire Line
	3550 4000 3600 4000
Connection ~ 4200 4400
Connection ~ 3550 4000
Wire Wire Line
	2350 4300 2900 4300
Wire Wire Line
	2350 4400 2900 4400
Wire Wire Line
	1250 3600 2500 3600
Wire Wire Line
	1750 3700 1750 3600
Wire Wire Line
	1750 4700 3050 4700
Wire Wire Line
	2500 3600 2500 4000
Wire Wire Line
	2500 4000 2350 4000
Connection ~ 1750 3600
Wire Wire Line
	2350 4100 3050 4100
Wire Wire Line
	3050 4100 3050 4700
Wire Wire Line
	750  4000 750  4100
Wire Wire Line
	750  4700 1150 4700
Wire Wire Line
	1150 4700 1150 4400
Text GLabel 1100 800  0    50   Input ~ 0
BATT+
Text Label 1900 800  2    50   ~ 0
BATT+
Wire Wire Line
	1100 800  1900 800 
Text Label 1050 4700 2    50   ~ 0
BATT+
Text Label 900  3600 2    60   ~ 0
PACK+
$Comp
L FUSE F1
U 1 1 56D7F3E2
P 2850 1700
F 0 "F1" H 2950 1750 50  0000 C CNN
F 1 "5 A" H 2750 1650 50  0000 C CNN
F 2 "custom_footprints:blade_fuse_holder" H 2850 1700 60  0001 C CNN
F 3 "" H 2850 1700 60  0000 C CNN
F 4 "Digikey" H 2850 1700 60  0001 C CNN "Supplier"
F 5 "BK-6010-ND" H 2850 1700 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/mpd-memory-protection-devices/BK-6010/BK-6010-ND/2330529" H 2850 1700 60  0001 C CNN "Supplier URL"
F 7 "Memory Protection Devices" H 2850 1700 60  0001 C CNN "Manufacturer"
F 8 "BK-6010" H 2850 1700 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.memoryprotectiondevices.com/datasheets/BK-6010-datasheet.pdf" H 2850 1700 60  0001 C CNN "Datasheet URL"
F 10 "FUSE BLOCK BLADE PCB" H 2850 1700 60  0001 C CNN "Description"
F 11 "0.54" H 2850 1700 60  0001 C CNN "Unit Cost"
F 12 "5A Blade Fuse" H 2850 1700 60  0001 C CNN "Accessory"
	1    2850 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 1700 2600 1700
Wire Wire Line
	3500 1700 5400 1700
Wire Wire Line
	750  4400 750  4700
Wire Wire Line
	900  3600 1000 3600
Wire Wire Line
	1000 3600 1000 4300
Wire Wire Line
	1000 4000 750  4000
Wire Wire Line
	1000 4300 1150 4300
Connection ~ 1000 4000
Wire Wire Line
	1150 4100 1000 4100
Connection ~ 1000 4100
$Comp
L SI2323DDS Q4
U 1 1 56DA35B2
P 1375 6850
F 0 "Q4" H 1375 7100 70  0000 C CNN
F 1 "RRR015P03TL" V 1750 6800 60  0000 C CNN
F 2 "custom_footprints:sot346" H 1425 6850 60  0001 C CNN
F 3 "" H 1425 6850 60  0000 C CNN
F 4 "Digikey" H 1375 6850 60  0001 C CNN "Supplier"
F 5 "RRR015P03TLCT-ND" H 1375 6850 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/RRR015P03TL/RRR015P03TLCT-ND/3769397" H 1375 6850 60  0001 C CNN "Supplier URL"
F 7 "Rohm Semiconductor" H 1375 6850 60  0001 C CNN "Manufacturer"
F 8 "RRR015P03TL" H 1375 6850 60  0001 C CNN "Manufacturer P/N"
F 9 "http://rohmfs.rohm.com/en/products/databook/datasheet/discrete/transistor/mosfet/rrr015p03tl-e.pdf" H 1375 6850 60  0001 C CNN "Datasheet URL"
F 10 "MOSFET P-CH 30V 1.5A TSMT3" H 1375 6850 60  0001 C CNN "Description"
F 11 "0.43" H 1375 6850 60  0001 C CNN "Unit Cost"
	1    1375 6850
	0    1    1    0   
$EndComp
Text Label 1675 7350 0    60   ~ 0
5V_HV
Wire Wire Line
	1675 7050 1675 7350
Text GLabel 1350 1850 0    60   Input ~ 0
5V_AMPS
Text Label 1900 1850 2    60   ~ 0
5V_AMPS
Wire Wire Line
	1350 1850 1900 1850
Wire Wire Line
	675  7050 1075 7050
Text Label 675  7050 0    60   ~ 0
5V_AMPS
Text Label 1675 6550 0    60   ~ 0
~LOW_DET
Text Label 1900 1250 2    60   ~ 0
~LOW_DET
Text GLabel 1100 1250 0    50   Input ~ 0
~LOW_DET
Wire Wire Line
	1100 1250 1900 1250
$Comp
L R-RESCUE-pacman-main R11
U 1 1 56E8D006
P 2225 7550
F 0 "R11" V 2305 7550 40  0000 C CNN
F 1 "10k" V 2232 7551 40  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2155 7550 30  0001 C CNN
F 3 "" H 2225 7550 30  0000 C CNN
	1    2225 7550
	1    0    0    -1  
$EndComp
Text Label 1825 7800 0    60   ~ 0
5V_HV
Wire Wire Line
	2225 7800 1825 7800
$Comp
L R R13
U 1 1 56FD44FA
P 3700 1950
F 0 "R13" V 3780 1950 50  0000 C CNN
F 1 "1 1%" V 3700 1950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3630 1950 30  0001 C CNN
F 3 "" H 3700 1950 30  0000 C CNN
	1    3700 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 2100 3700 2175
Wire Wire Line
	3700 1800 3700 1700
Connection ~ 3700 1700
Wire Wire Line
	5400 2300 5325 2300
Wire Wire Line
	5325 2300 5325 2600
Connection ~ 5325 2600
Wire Wire Line
	5800 2500 5800 2600
Connection ~ 5800 2600
Wire Wire Line
	5900 2500 5900 2600
Connection ~ 5900 2600
Wire Wire Line
	6000 2500 6000 2600
Connection ~ 6000 2600
$Comp
L C-RESCUE-pacman-main C12
U 1 1 56FD77E6
P 7750 2200
F 0 "C12" H 7750 2300 40  0000 L CNN
F 1 "10u" H 7756 2115 40  0000 L CNN
F 2 "Capacitors_SMD:C_1210_HandSoldering" H 7788 2050 30  0001 C CNN
F 3 "" H 7750 2200 60  0000 C CNN
F 4 "Digikey" H 7750 2200 60  0001 C CNN "Supplier"
F 5 "490-1891-1-ND" H 7750 2200 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/GRM32DF51H106ZA01L/490-1891-1-ND/587282" H 7750 2200 60  0001 C CNN "Supplier URL"
F 7 "Murata Electronics" H 7750 2200 60  0001 C CNN "Manufacturer"
F 8 "GRM32DF51H106ZA01L" H 7750 2200 60  0001 C CNN "Manufacturer P/N"
F 9 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRM32DF51H106ZA01-01.pdf" H 7750 2200 60  0001 C CNN "Datasheet URL"
F 10 "CAP CER 10UF 50V Y5V 1210" H 7750 2200 60  0001 C CNN "Description"
F 11 "0.61" H 7750 2200 60  0001 C CNN "Unit Cost"
	1    7750 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 1900 7750 2050
Wire Wire Line
	7750 2350 7750 2475
Wire Wire Line
	7750 2475 7500 2475
Connection ~ 7500 2475
$Comp
L R-RESCUE-pacman-main R14
U 1 1 56FD81C4
P 7250 2200
F 0 "R14" V 7330 2200 40  0000 C CNN
F 1 "1k" V 7257 2201 40  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7180 2200 30  0001 C CNN
F 3 "" H 7250 2200 30  0000 C CNN
	1    7250 2200
	-1   0    0    1   
$EndComp
Wire Wire Line
	7250 1950 7250 1900
Connection ~ 7250 1900
Wire Wire Line
	7250 2450 7250 2600
Connection ~ 7250 2600
$Comp
L NCS6S1205C U7
U 1 1 56FDBE53
P 6650 5150
F 0 "U7" H 6650 5150 60  0000 C CNN
F 1 "NCS6S1205C" H 6650 5050 60  0000 C CNN
F 2 "custom_footprints:NCS6S1205C" H 6650 5150 60  0001 C CNN
F 3 "" H 6650 5150 60  0000 C CNN
F 4 "Digikey" H 6650 5150 60  0001 C CNN "Supplier"
F 5 "http://power.murata.com/data/power/ncl/kdc_ncs6.pdf" H 6650 5150 60  0001 C CNN "Supplier URl"
F 6 "811-2109-5-ND" H 6650 5150 60  0001 C CNN "Supplier P/N"
F 7 "Murata" H 6650 5150 60  0001 C CNN "Manufacturer"
F 8 "NCS6S1205C" H 6650 5150 60  0001 C CNN "Manufacturer P/N"
F 9 "http://power.murata.com/data/power/ncl/kdc_ncs6.pdf" H 6650 5150 60  0001 C CNN "Datasheet URL"
F 10 "CONVERT DC/DC 6W 12VIN-5VOUT T/H" H 6650 5150 60  0001 C CNN "Description"
F 11 "22.00" H 6650 5150 60  0001 C CNN "Unit Cost"
	1    6650 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 5400 7500 5100
Wire Wire Line
	7500 5100 7350 5100
NoConn ~ 7350 5450
Wire Wire Line
	4950 5000 5950 5000
Wire Wire Line
	5775 5000 5775 5100
Wire Wire Line
	5775 5100 5950 5100
Connection ~ 5775 5000
Wire Wire Line
	4950 5350 5950 5350
Wire Wire Line
	5775 5350 5775 5450
Wire Wire Line
	5775 5450 5950 5450
Connection ~ 5775 5350
$Comp
L C-RESCUE-pacman-main C9
U 1 1 56FDDA6E
P 5250 5175
F 0 "C9" H 5250 5275 40  0000 L CNN
F 1 "10u" H 5256 5090 40  0000 L CNN
F 2 "Capacitors_SMD:C_1210_HandSoldering" H 5288 5025 30  0001 C CNN
F 3 "" H 5250 5175 60  0000 C CNN
F 4 "Digikey" H 5250 5175 60  0001 C CNN "Supplier"
F 5 "490-1891-1-ND" H 5250 5175 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/GRM32DF51H106ZA01L/490-1891-1-ND/587282" H 5250 5175 60  0001 C CNN "Supplier URL"
F 7 "Murata Electronics" H 5250 5175 60  0001 C CNN "Manufacturer"
F 8 "GRM32DF51H106ZA01L" H 5250 5175 60  0001 C CNN "Manufacturer P/N"
F 9 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRM32DF51H106ZA01-01.pdf" H 5250 5175 60  0001 C CNN "Datasheet URL"
F 10 "CAP CER 10UF 50V Y5V 1210" H 5250 5175 60  0001 C CNN "Description"
F 11 "0.61" H 5250 5175 60  0001 C CNN "Unit Cost"
	1    5250 5175
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 5325 5250 5350
Connection ~ 5250 5350
Wire Wire Line
	5250 5025 5250 5000
Connection ~ 5250 5000
Wire Wire Line
	1675 6550 2450 6550
Wire Wire Line
	2225 7300 2225 6550
Connection ~ 2225 6550
Wire Wire Line
	1375 6650 1375 6450
Wire Wire Line
	1375 6450 2450 6450
$Comp
L C-RESCUE-pacman-main C25
U 1 1 56FE1471
P 6675 3800
F 0 "C25" H 6700 3900 50  0000 L CNN
F 1 "0.1u" H 6700 3700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 6713 3650 30  0001 C CNN
F 3 "" H 6675 3800 60  0000 C CNN
	1    6675 3800
	1    0    0    -1  
$EndComp
$Comp
L C-RESCUE-pacman-main C14
U 1 1 56FE1501
P 6450 3800
F 0 "C14" H 6475 3900 50  0000 L CNN
F 1 "0.1u" H 6475 3700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 6488 3650 30  0001 C CNN
F 3 "" H 6450 3800 60  0000 C CNN
	1    6450 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 3650 6450 3500
Connection ~ 6900 3500
Wire Wire Line
	6675 3650 6675 3500
Connection ~ 6675 3500
Wire Wire Line
	6450 3950 6450 4100
Connection ~ 6900 4100
Wire Wire Line
	6675 3950 6675 4100
Connection ~ 6675 4100
Connection ~ 5200 2600
Connection ~ 5200 1700
$Comp
L C-RESCUE-pacman-main C27
U 1 1 57F6E953
P 9600 5200
F 0 "C27" H 9600 5300 40  0000 L CNN
F 1 "10u" H 9606 5115 40  0000 L CNN
F 2 "Capacitors_SMD:C_1210_HandSoldering" H 9638 5050 30  0001 C CNN
F 3 "" H 9600 5200 60  0000 C CNN
F 4 "Digikey" H 9600 5200 60  0001 C CNN "Supplier"
F 5 "1276-1854-1-ND" H 9600 5200 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/samsung-electro-mechanics-america-inc/CL32A106KAULNNE/1276-1854-1-ND/3889940" H 9600 5200 60  0001 C CNN "Supplier URL"
F 7 "Samsung Electro-Mechanics America, Inc." H 9600 5200 60  0001 C CNN "Manufacturer"
F 8 "CL32A106KAULNNE" H 9600 5200 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.samsungsem.com/kr/support/product-search/mlcc/__icsFiles/afieldfile/2016/08/18/S_CL32A106KAULNNE.pdf" H 9600 5200 60  0001 C CNN "Datasheet URL"
F 10 "10µF 25V Ceramic Capacitor X5R 1210 (3225 Metric) 0.126\" L x 0.098\" W (3.20mm x 2.50mm)" H 9600 5200 60  0001 C CNN "Description"
F 11 "0.24" H 9600 5200 60  0001 C CNN "Unit Cost"
	1    9600 5200
	1    0    0    -1  
$EndComp
$EndSCHEMATC
