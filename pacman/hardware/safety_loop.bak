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
Sheet 3 6
Title "Battery Pack Management Computer"
Date "2016-12-13"
Rev "0.8"
Comp "Lafayette College"
Comment1 "Fall Semester 2016"
Comment2 "Supervisor: Christopher Nadovich"
Comment3 "Engineer: Preston Bejabeng"
Comment4 "DEVELOPMENT ONLY"
$EndDescr
Text Label 7700 5250 0    60   ~ 0
~CHRG_CTRL
$Comp
L LED-RESCUE-pacman-main D12
U 1 1 560D901A
P 9050 4350
F 0 "D12" H 9050 4450 50  0000 C CNN
F 1 "CHARGE" H 9050 4250 50  0000 C CNN
F 2 "LEDs:LED_0603" H 9050 4350 60  0001 C CNN
F 3 "" H 9050 4350 60  0000 C CNN
F 4 "0603 LED (GREEN)" H 9050 4350 60  0001 C CNN "Description"
	1    9050 4350
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-pacman-main R23
U 1 1 560D9022
P 8500 4350
F 0 "R23" V 8580 4350 40  0000 C CNN
F 1 "1k" V 8507 4351 40  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 8430 4350 30  0001 C CNN
F 3 "" H 8500 4350 30  0000 C CNN
	1    8500 4350
	0    1    1    0   
$EndComp
Text Label 7650 4350 0    60   ~ 0
CHRG_CTRL
Text Notes 7725 3475 0    100  ~ 0
CHARGE CONTROL P-FET
Text HLabel 1400 1250 0    60   Input ~ 0
SAFETY_CTRL
Text Label 2200 1250 2    60   ~ 0
SLOOP_CTRL
Text HLabel 1400 1450 0    60   Input ~ 0
CHARGE_CTRL
Text Label 2200 1450 2    60   ~ 0
CHRG_CTRL
Text Label 4150 1750 0    60   ~ 0
SLOOP_CTRL
Text Label 6850 2600 2    60   ~ 0
SLOOP_B1
Text Notes 4150 850  0    100  ~ 0
SAFETY LOOP RELAY
Text Label 9000 1850 0    60   ~ 0
SLOOP_A1
Text Notes 4250 1500 0    60   ~ 0
This relay is responsible for switching the PACMAN safety loop\nconnection ON/OFF. The lights show the user at a glance if\nthe safey loop is open or closed.\n\nThis relay is capable of switching 8A.  \nThe SLOOP_CTRL signal is active low.
Text Label 9550 4350 2    60   ~ 0
GND
Text Notes 7450 3950 0    60   ~ 0
This MOSFET is responsible for connecting the CHARGE relays\nwhen the pack charger has been connected. Power is supplied\nfrom either the pack terminals, or USB connector.\n\nCoil Output Voltage: 5V
Text Label 4500 5400 0    60   ~ 0
~FAN_CTRL
Text Notes 4050 3700 0    100  ~ 0
FAN CONTROL P-FET
$Comp
L GND #PWR032
U 1 1 561B18B5
P 5600 6400
F 0 "#PWR032" H 5600 6150 50  0001 C CNN
F 1 "GND" H 5600 6250 50  0000 C CNN
F 2 "" H 5600 6400 60  0000 C CNN
F 3 "" H 5600 6400 60  0000 C CNN
	1    5600 6400
	1    0    0    -1  
$EndComp
Text Notes 4150 4350 0    60   ~ 0
This MOSFET is responsible for switching the charge fan ON/OFF.\n\nThe fan will not come on automatically when charging begins,\nit is controlled by the software.\n\nFan Output Voltage: 5V
Text Label 9000 1950 0    60   ~ 0
SLOOP_B1
Text HLabel 1400 1650 0    60   Input ~ 0
FAN_CTRL
Text Label 2200 1650 2    60   ~ 0
FAN_CTRL
Text Label 9700 1350 0    60   ~ 0
GND
$Comp
L GND-RESCUE-pacman-main #PWR033
U 1 1 562B6308
P 10200 1450
F 0 "#PWR033" H 10200 1450 30  0001 C CNN
F 1 "GND" H 10200 1380 30  0001 C CNN
F 2 "" H 10200 1450 60  0000 C CNN
F 3 "" H 10200 1450 60  0000 C CNN
	1    10200 1450
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR034
U 1 1 562B630E
P 9500 1050
F 0 "#PWR034" H 9500 900 50  0001 C CNN
F 1 "+3.3V" H 9500 1190 50  0000 C CNN
F 2 "" H 9500 1050 60  0000 C CNN
F 3 "" H 9500 1050 60  0000 C CNN
	1    9500 1050
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR035
U 1 1 562B6314
P 10200 1050
F 0 "#PWR035" H 10200 900 50  0001 C CNN
F 1 "+5V" H 10200 1190 50  0000 C CNN
F 2 "" H 10200 1050 60  0000 C CNN
F 3 "" H 10200 1050 60  0000 C CNN
	1    10200 1050
	1    0    0    -1  
$EndComp
Text Label 9000 1150 0    60   ~ 0
+3.3V
Text Label 9700 1150 0    60   ~ 0
+5V
Text Notes 8450 750  0    100  ~ 0
GROUNDED LOW VOLTAGE
Text GLabel 9800 1850 2    50   Output ~ 0
SLOOP_A1
Text GLabel 9800 1950 2    50   Output ~ 0
SLOOP_B1
Text GLabel 9800 2350 2    50   Output ~ 0
FAN+
Text Label 9000 2350 0    60   ~ 0
FAN+
$Comp
L DIODESCH D18
U 1 1 562AB319
P 5600 6100
F 0 "D18" H 5600 6200 40  0000 C CNN
F 1 "SK310A-LTP" H 5600 6000 40  0000 C CNN
F 2 "custom_footprints:do214ac" H 5600 6100 60  0001 C CNN
F 3 "" H 5600 6100 60  0000 C CNN
F 4 "Digikey" H 5600 6100 60  0001 C CNN "Supplier"
F 5 "SK310A-LTPMSCT-ND" H 5600 6100 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/SK310A-LTP/SK310A-LTPMSCT-ND/2642066" H 5600 6100 60  0001 C CNN "Supplier URL"
F 7 "Micro Commercial Components (MMC)" H 5600 6100 60  0001 C CNN "Manufacturer"
F 8 "SK310A-LTP" H 5600 6100 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.mccsemi.com/up_pdf/SK32A-LT~SK310A-LT%28DO-214AC%29.PDF" H 5600 6100 60  0001 C CNN "Datasheet URL"
F 10 "Schottky Diodes & Rectifiers DIODE SCHOTTKY 100V 3A DO214AC " H 5600 6100 60  0001 C CNN "Description"
F 11 "0.57" H 5600 6100 60  0001 C CNN "Unit Cost"
	1    5600 6100
	0    -1   -1   0   
$EndComp
$Comp
L SI2323DDS Q1
U 1 1 562ABB38
P 5400 5400
F 0 "Q1" H 5400 5650 70  0000 C CNN
F 1 "RRR015P03TL" H 5250 5150 60  0000 C CNN
F 2 "custom_footprints:sot346" H 5450 5400 60  0001 C CNN
F 3 "" H 5450 5400 60  0000 C CNN
F 4 "Digikey" H 5400 5400 60  0001 C CNN "Supplier"
F 5 "RRR015P03TLCT-ND" H 5400 5400 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/RRR015P03TL/RRR015P03TLCT-ND/3769397" H 5400 5400 60  0001 C CNN "Supplier URL"
F 7 "Rohm Semiconductor" H 5400 5400 60  0001 C CNN "Manufacturer"
F 8 "RRR015P03TL" H 5400 5400 60  0001 C CNN "Manufacturer P/N"
F 9 "http://rohmfs.rohm.com/en/products/databook/datasheet/discrete/transistor/mosfet/rrr015p03tl-e.pdf" H 5400 5400 60  0001 C CNN "Datasheet URL"
F 10 "MOSFET P-CH 30V 1.5A TSMT3" H 5400 5400 60  0001 C CNN "Description"
F 11 "0.43" H 5400 5400 60  0001 C CNN "Unit Cost"
	1    5400 5400
	1    0    0    -1  
$EndComp
Text Label 7700 4550 0    60   ~ 0
+5V
Text Label 6400 5800 2    60   ~ 0
FAN+
$Comp
L GND #PWR036
U 1 1 562B02ED
P 8800 6250
F 0 "#PWR036" H 8800 6000 50  0001 C CNN
F 1 "GND" H 8800 6100 50  0000 C CNN
F 2 "" H 8800 6250 60  0000 C CNN
F 3 "" H 8800 6250 60  0000 C CNN
	1    8800 6250
	1    0    0    -1  
$EndComp
$Comp
L DIODESCH D19
U 1 1 562B02FC
P 8800 5950
F 0 "D19" H 8800 6050 40  0000 C CNN
F 1 "SK310A-LTP" H 8800 5850 40  0000 C CNN
F 2 "custom_footprints:do214ac" H 8800 5950 60  0001 C CNN
F 3 "" H 8800 5950 60  0000 C CNN
F 4 "Digikey" H 8800 5950 60  0001 C CNN "Supplier"
F 5 "SK310A-LTPMSCT-ND" H 8800 5950 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/SK310A-LTP/SK310A-LTPMSCT-ND/2642066" H 8800 5950 60  0001 C CNN "Supplier URL"
F 7 "Micro Commercial Components (MMC)" H 8800 5950 60  0001 C CNN "Manufacturer"
F 8 "SK310A-LTP" H 8800 5950 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.mccsemi.com/up_pdf/SK32A-LT~SK310A-LT%28DO-214AC%29.PDF" H 8800 5950 60  0001 C CNN "Datasheet URL"
F 10 "Schottky Diodes & Rectifiers DIODE SCHOTTKY 100V 3A DO214AC " H 8800 5950 60  0001 C CNN "Description"
F 11 "0.57" H 8800 5950 60  0001 C CNN "Unit Cost"
	1    8800 5950
	0    -1   -1   0   
$EndComp
Text Label 4500 4700 0    60   ~ 0
+5V
$Comp
L R-RESCUE-pacman-main R37
U 1 1 562A49C0
P 5100 5050
F 0 "R37" V 5180 5050 40  0000 C CNN
F 1 "10k" V 5107 5051 40  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5030 5050 30  0001 C CNN
F 3 "" H 5100 5050 30  0000 C CNN
	1    5100 5050
	-1   0    0    1   
$EndComp
$Comp
L R-RESCUE-pacman-main R38
U 1 1 562A59DB
P 8300 4900
F 0 "R38" V 8380 4900 40  0000 C CNN
F 1 "10k" V 8307 4901 40  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 8230 4900 30  0001 C CNN
F 3 "" H 8300 4900 30  0000 C CNN
	1    8300 4900
	-1   0    0    1   
$EndComp
Text Notes 8850 4200 0    60   ~ 0
GREEN
$Comp
L RELAY_HJR-3FF_H RLY1
U 1 1 56C8F931
P 5400 2450
F 0 "RLY1" H 5400 2700 60  0000 C CNN
F 1 "G5LE-1A4 DC3" H 5400 2215 60  0000 C CNN
F 2 "custom_footprints:relay_G5LE_1A4" H 5400 2450 60  0001 C CNN
F 3 "" H 5400 2450 60  0001 C CNN
F 4 "Digikey" H 5400 2450 60  0001 C CNN "Supplier"
F 5 "Z3697-ND" H 5400 2450 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/G5LE-1A4%20DC3/Z3697-ND/1815639" H 5400 2450 60  0001 C CNN "Supplier URL"
F 7 "Omron" H 5400 2450 60  0001 C CNN "Manufacturer"
F 8 "G5LE-1A4 DC3" H 5400 2450 60  0001 C CNN "Manufacturer P/N"
F 9 "https://www.components.omron.com/components/web/PDFLIB.nsf/0/0293ACA6B03161CD86257538007424DB/$file/G5LE_0813.pdf" H 5400 2450 60  0001 C CNN "Datasheet URL"
F 10 "RELAY GEN PURPOSE SPST 10A 3V" H 5400 2450 60  0001 C CNN "Description"
F 11 "1.43" H 5400 2450 60  0001 C CNN "Unit Cost"
	1    5400 2450
	1    0    0    -1  
$EndComp
Text Label 4150 2300 0    60   ~ 0
GND
Text Label 4150 2550 0    60   ~ 0
SLOOP_A1
Text Label 6850 2300 2    60   ~ 0
+3.3V
$Comp
L DIODESCH D21
U 1 1 56C97FC6
P 5400 1950
F 0 "D21" H 5400 2050 40  0000 C CNN
F 1 "SK310A-LTP" H 5400 1850 40  0000 C CNN
F 2 "custom_footprints:do214ac" H 5400 1950 60  0001 C CNN
F 3 "" H 5400 1950 60  0000 C CNN
F 4 "Digikey" H 5400 1950 60  0001 C CNN "Supplier"
F 5 "SK310A-LTPMSCT-ND" H 5400 1950 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/SK310A-LTP/SK310A-LTPMSCT-ND/2642066" H 5400 1950 60  0001 C CNN "Supplier URL"
F 7 "Micro Commercial Components (MMC)" H 5400 1950 60  0001 C CNN "Manufacturer"
F 8 "SK310A-LTP" H 5400 1950 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.mccsemi.com/up_pdf/SK32A-LT~SK310A-LT%28DO-214AC%29.PDF" H 5400 1950 60  0001 C CNN "Datasheet URL"
F 10 "Schottky Diodes & Rectifiers DIODE SCHOTTKY 100V 3A DO214AC " H 5400 1950 60  0001 C CNN "Description"
F 11 "0.57" H 5400 1950 60  0001 C CNN "Unit Cost"
	1    5400 1950
	1    0    0    -1  
$EndComp
Text Notes 1400 4850 0    60   ~ 0
This device is responsible for driving the\nhigh side p-fet switches.
Text Notes 1300 4550 0    100  ~ 0
HIGH SIDE P-FET DRIVER
Text Label 3400 5500 2    60   ~ 0
~CHRG_CTRL
Text Label 3400 5750 2    60   ~ 0
~FAN_CTRL
Text Label 1150 5500 0    60   ~ 0
CHRG_CTRL
Text Label 1150 5750 0    60   ~ 0
FAN_CTRL
Text Label 1150 6000 0    60   ~ 0
GND
Text Label 3350 6000 2    60   ~ 0
+3.3V
$Comp
L SI2323DDS Q3
U 1 1 56D0EFAD
P 8600 5250
F 0 "Q3" H 8600 5500 70  0000 C CNN
F 1 "RRR015P03TL" H 8450 5000 60  0000 C CNN
F 2 "custom_footprints:sot346" H 8650 5250 60  0001 C CNN
F 3 "" H 8650 5250 60  0000 C CNN
F 4 "Digikey" H 8600 5250 60  0001 C CNN "Supplier"
F 5 "RRR015P03TLCT-ND" H 8600 5250 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/RRR015P03TL/RRR015P03TLCT-ND/3769397" H 8600 5250 60  0001 C CNN "Supplier URL"
F 7 "Rohm Semiconductor" H 8600 5250 60  0001 C CNN "Manufacturer"
F 8 "RRR015P03TL" H 8600 5250 60  0001 C CNN "Manufacturer P/N"
F 9 "http://rohmfs.rohm.com/en/products/databook/datasheet/discrete/transistor/mosfet/rrr015p03tl-e.pdf" H 8600 5250 60  0001 C CNN "Datasheet URL"
F 10 "MOSFET P-CH 30V 1.5A TSMT3" H 8600 5250 60  0001 C CNN "Description"
F 11 "0.43" H 8600 5250 60  0001 C CNN "Unit Cost"
	1    8600 5250
	1    0    0    -1  
$EndComp
$Comp
L SI2323DDS Q2
U 1 1 56D1463E
P 6100 2100
F 0 "Q2" H 6100 2350 70  0000 C CNN
F 1 "RRR015P03TL" H 5950 1850 60  0000 C CNN
F 2 "custom_footprints:sot346" H 6150 2100 60  0001 C CNN
F 3 "" H 6150 2100 60  0000 C CNN
F 4 "Digikey" H 6100 2100 60  0001 C CNN "Supplier"
F 5 "RRR015P03TLCT-ND" H 6100 2100 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/RRR015P03TL/RRR015P03TLCT-ND/3769397" H 6100 2100 60  0001 C CNN "Supplier URL"
F 7 "Rohm Semiconductor" H 6100 2100 60  0001 C CNN "Manufacturer"
F 8 "RRR015P03TL" H 6100 2100 60  0001 C CNN "Manufacturer P/N"
F 9 "http://rohmfs.rohm.com/en/products/databook/datasheet/discrete/transistor/mosfet/rrr015p03tl-e.pdf" H 6100 2100 60  0001 C CNN "Datasheet URL"
F 10 "MOSFET P-CH 30V 1.5A TSMT3" H 6100 2100 60  0001 C CNN "Description"
F 11 "0.43" H 6100 2100 60  0001 C CNN "Unit Cost"
	1    6100 2100
	0    1    1    0   
$EndComp
$Comp
L 74LVC U10
U 1 1 56D82DAA
P 2300 5750
F 0 "U10" H 2250 5900 50  0000 C CNN
F 1 "SN74LVC2G06" H 2300 5550 50  0000 C CNN
F 2 "custom_footprints:DCK" H 2300 5550 50  0001 C CNN
F 3 "" H 2300 5550 50  0000 C CNN
F 4 "Digikey" H 2300 5750 60  0001 C CNN "Supplier"
F 5 "296-13493-1-ND" H 2300 5750 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/texas-instruments/SN74LVC2G06DCKR/296-13493-1-ND/486425" H 2300 5750 60  0001 C CNN "Supplier URL"
F 7 "Texas Instruments" H 2300 5750 60  0001 C CNN "Manufacturer"
F 8 "SN74LVC2G06DCKR" H 2300 5750 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.ti.com/lit/ds/symlink/sn74lvc2g06.pdf" H 2300 5750 60  0001 C CNN "Datasheet URL"
F 10 "IC INVERTER DUAL 1INPUT SC706" H 2300 5750 60  0001 C CNN "Description"
F 11 "0.54" H 2300 5750 60  0001 C CNN "Unit Cost"
	1    2300 5750
	1    0    0    -1  
$EndComp
Text GLabel 9800 2650 2    50   Output ~ 0
SLOOP_A3
Text GLabel 9800 2800 2    50   Output ~ 0
SLOOP_A4
$Comp
L R-RESCUE-pacman-main R4
U 1 1 56D86223
P 7725 2800
F 0 "R4" V 7805 2800 40  0000 C CNN
F 1 "510" V 7732 2801 40  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7655 2800 30  0001 C CNN
F 3 "" H 7725 2800 30  0000 C CNN
F 4 "DigiKey" V 7725 2800 60  0001 C CNN "Supplier"
F 5 "RHM510KCT-ND" V 7725 2800 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/rohm-semiconductor/ESR10EZPJ511/RHM510KCT-ND/1763033" V 7725 2800 60  0001 C CNN "Supplier URL"
F 7 "Rohm Semiconductor" V 7725 2800 60  0001 C CNN "Manufacturer"
F 8 "ESR10EZPJ511" V 7725 2800 60  0001 C CNN "Manufacturer P/N"
F 9 "http://rohmfs.rohm.com/en/products/databook/datasheet/passive/resistor/chip_resistor/esr.pdf" V 7725 2800 60  0001 C CNN "Datasheet URL"
F 10 "RES SMD 510 OHM 5% 0.4W 0805" V 7725 2800 60  0001 C CNN "Description"
F 11 "0.10" V 7725 2800 60  0001 C CNN "Unit Cost"
	1    7725 2800
	0    1    1    0   
$EndComp
Text GLabel 8300 2800 2    60   Input ~ 0
LED+
Text GLabel 9025 2800 0    60   Input ~ 0
LED-
Text Label 9000 2050 0    60   ~ 0
SLOOP_A3
Text GLabel 9800 2050 2    50   Output ~ 0
SLOOP_A3
Text Label 9000 2150 0    60   ~ 0
SLOOP_A4
Text GLabel 9800 2150 2    50   Output ~ 0
SLOOP_A4
Text Notes 7350 2400 0    60   ~ 0
A1 and B1 pins are shorted\ntogether only when the safety\nloop is not opened by this board.\n\nVoltage between A3 and A4\ngreater than 0 means the \nsafety loop is not opened by \nany other component in the\nsystem.
Text Notes 850  2550 0    100  ~ 0
OPTO-ISOLATOR ON SL CLOSED SIGNAL
Text Notes 1050 2950 0    60   ~ 0
This device provides a galvanically isolated signal to the\nmicrocontroller to let it know the safety loop is closed in \nall components.  The HV current sensor is enabled as a\nresult.  This mean the AIRs should be closed if functional.
$Comp
L TLP2361 U13
U 1 1 56DA73C4
P 2375 3550
F 0 "U13" H 2385 3740 60  0000 C CNN
F 1 "TLP2361" H 2225 3040 60  0000 C CNN
F 2 "custom_footprints:TLP2361" H 2385 3740 60  0001 C CNN
F 3 "" H 2385 3740 60  0000 C CNN
F 4 "Digikey" H 2375 3550 60  0001 C CNN "Supplier"
F 5 "TLP2361(V4-TPLECT-ND" H 2375 3550 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-search/en?keywords=TLP2361(V4-TPLECT-ND" H 2375 3550 60  0001 C CNN "Supplier URL"
F 7 "Toshiba Semiconductor and Storage" H 2375 3550 60  0001 C CNN "Manufacturer"
F 8 "TLP2361(V4-TPL,E" H 2375 3550 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.semicon.toshiba.co.jp/info/docget.jsp?type=datasheet&lang=en&pid=TLP2361" H 2375 3550 60  0001 C CNN "Datasheet URL"
F 10 "OPTOISO 3.75KV PSH PULL SO6-5" H 2375 3550 60  0001 C CNN "Description"
F 11 "1.14" H 2375 3550 60  0001 C CNN "Unit Cost"
	1    2375 3550
	1    0    0    -1  
$EndComp
Text Label 850  3350 0    60   ~ 0
SLOOP_A3
Text Label 875  3950 0    60   ~ 0
SLOOP_A4
Text Label 3900 3350 2    60   ~ 0
+3.3V
Text Label 3900 3950 2    60   ~ 0
GND
Text Label 2200 1825 2    60   ~ 0
SLOOP_DET
Text Label 3425 3650 2    60   ~ 0
SLOOP_DET
$Comp
L C-RESCUE-pacman-main C7
U 1 1 56DA9A93
P 3575 3600
F 0 "C7" H 3575 3700 40  0000 L CNN
F 1 "0.1u" H 3581 3515 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 3613 3450 30  0001 C CNN
F 3 "" H 3575 3600 60  0000 C CNN
	1    3575 3600
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-pacman-main R9
U 1 1 56DAA10E
P 1550 3350
F 0 "R9" V 1630 3350 40  0000 C CNN
F 1 "10k" V 1557 3351 40  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1480 3350 30  0001 C CNN
F 3 "" H 1550 3350 30  0000 C CNN
	1    1550 3350
	0    1    1    0   
$EndComp
Text GLabel 1375 1825 0    60   Input ~ 0
SLOOP_DET
$Comp
L RELAY_HJR-3FF_H RLY2
U 1 1 56DBD4FE
P 9750 5900
F 0 "RLY2" H 9750 6150 60  0000 C CNN
F 1 "T9AS1D12-5" H 9750 5665 60  0000 C CNN
F 2 "custom_footprints:RLY_T9AS1D12-5" H 9750 5900 60  0001 C CNN
F 3 "" H 9750 5900 60  0001 C CNN
F 4 "Digikey" H 9750 5900 60  0001 C CNN "Supplier"
F 5 "PB1014-ND" H 9750 5900 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-search/en?keywords=PB1014-ND" H 9750 5900 60  0001 C CNN "Supplier URL"
F 7 "TE Connectivity Potter & Brumfield Relays" H 9750 5900 60  0001 C CNN "Manufacturer"
F 8 "T9AS1D12-5" H 9750 5900 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.te.com/commerce/DocumentDelivery/DDEController?Action=srchrtrv&DocNm=1308242_T9A&DocType=DS&DocLang=English" H 9750 5900 60  0001 C CNN "Datasheet URL"
F 10 "RELAY GEN PURPOSE SPST 30A 5V" H 9750 5900 60  0001 C CNN "Description"
F 11 "4.22" H 9750 5900 60  0001 C CNN "Unit Cost"
	1    9750 5900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4500 4700 5600 4700
Wire Wire Line
	5600 4700 5600 5100
Wire Wire Line
	5100 4800 5100 4700
Connection ~ 5100 4700
Wire Wire Line
	4500 5400 5200 5400
Wire Wire Line
	5100 5300 5100 5400
Connection ~ 5100 5400
Wire Wire Line
	5600 5700 5600 5900
Wire Wire Line
	5600 6300 5600 6400
Wire Wire Line
	7650 4350 8250 4350
Wire Wire Line
	8750 4350 8850 4350
Wire Wire Line
	9250 4350 9550 4350
Wire Wire Line
	7700 4550 8800 4550
Wire Wire Line
	8800 4550 8800 4950
Wire Wire Line
	8300 4650 8300 4550
Connection ~ 8300 4550
Wire Wire Line
	7700 5250 8400 5250
Wire Wire Line
	8300 5150 8300 5250
Connection ~ 8300 5250
Wire Wire Line
	8800 5550 8800 5750
Wire Wire Line
	8800 6150 8800 6250
Wire Wire Line
	9600 5650 8800 5650
Connection ~ 8800 5650
Wire Wire Line
	6400 5800 5600 5800
Connection ~ 5600 5800
Wire Wire Line
	4150 2300 5200 2300
Wire Wire Line
	6850 2600 5600 2600
Wire Wire Line
	5200 2550 4150 2550
Wire Wire Line
	9000 1150 9500 1150
Wire Wire Line
	9500 1150 9500 1050
Wire Wire Line
	9700 1150 10200 1150
Wire Wire Line
	10200 1150 10200 1050
Wire Wire Line
	9700 1350 10200 1350
Wire Wire Line
	10200 1350 10200 1450
Wire Wire Line
	1400 1250 2200 1250
Wire Wire Line
	1400 1450 2200 1450
Wire Wire Line
	1400 1650 2200 1650
Wire Wire Line
	9000 1850 9800 1850
Wire Wire Line
	9000 1950 9800 1950
Wire Wire Line
	9800 2350 9000 2350
Wire Wire Line
	1150 5500 1850 5500
Wire Wire Line
	1150 5750 1850 5750
Wire Wire Line
	2700 5500 3400 5500
Wire Wire Line
	2700 5750 3400 5750
Wire Wire Line
	2700 6000 3350 6000
Wire Wire Line
	6400 2300 6850 2300
Wire Wire Line
	6100 1900 6100 1750
Wire Wire Line
	5600 2300 5800 2300
Wire Wire Line
	5600 1950 5700 1950
Wire Wire Line
	5700 1950 5700 2300
Connection ~ 5700 2300
Wire Wire Line
	5200 1950 5050 1950
Wire Wire Line
	5050 1950 5050 2300
Connection ~ 5050 2300
Wire Wire Line
	6100 1750 4150 1750
Wire Wire Line
	1850 6000 1150 6000
Wire Wire Line
	7475 2650 9800 2650
Wire Wire Line
	9000 2050 9800 2050
Wire Wire Line
	9000 2150 9800 2150
Wire Wire Line
	850  3350 1300 3350
Wire Wire Line
	875  3950 1825 3950
Wire Wire Line
	2925 3350 3900 3350
Wire Wire Line
	2925 3950 3900 3950
Wire Wire Line
	1375 1825 2200 1825
Wire Wire Line
	3575 3450 3575 3350
Connection ~ 3575 3350
Wire Wire Line
	3575 3750 3575 3950
Connection ~ 3575 3950
Wire Wire Line
	1825 3350 1800 3350
Wire Wire Line
	2925 3650 3425 3650
Wire Wire Line
	9600 5700 9600 5650
Wire Wire Line
	9600 6100 9600 6225
Wire Wire Line
	9600 6225 8800 6225
Connection ~ 8800 6225
Text GLabel 9850 6400 2    60   Input ~ 0
CHARGE+
Text GLabel 9900 5375 2    60   Input ~ 0
PACK+
Wire Wire Line
	9900 5700 9900 5375
Wire Wire Line
	9850 6100 9850 6400
$Comp
L C C28
U 1 1 57F2AA8D
P 8075 2950
F 0 "C28" H 8125 3050 50  0000 L CNN
F 1 ".1u" H 8100 2850 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 8113 2800 50  0001 C CNN
F 3 "" H 8075 2950 50  0000 C CNN
F 4 "DigiKey" H 8075 2950 60  0001 C CNN "Supplier"
F 5 "399-7845-1-ND" H 8075 2950 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/kemet/C0603C104M5RACTU/399-7845-1-ND/3471568" H 8075 2950 60  0001 C CNN "Supplier URL"
F 7 "Kemet" H 8075 2950 60  0001 C CNN "Manufacturer"
F 8 "C0603C104M5RACTU" H 8075 2950 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.kemet.com/docfinder?Partnumber=C0603C104M5RACTU" H 8075 2950 60  0001 C CNN "Datasheet URL"
F 10 "0.10µF 50V Ceramic Capacitor X7R 0603 (1608 Metric) 0.063\" L x 0.031\" W (1.60mm x 0.80mm)" H 8075 2950 60  0001 C CNN "Description"
F 11 "0.10" H 8075 2950 60  0001 C CNN "Unit Cost"
	1    8075 2950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR037
U 1 1 57F2B05D
P 8075 3100
F 0 "#PWR037" H 8075 2850 50  0001 C CNN
F 1 "GND" H 8075 2950 50  0000 C CNN
F 2 "" H 8075 3100 50  0000 C CNN
F 3 "" H 8075 3100 50  0000 C CNN
	1    8075 3100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR038
U 1 1 57F2BA2A
P 9150 3100
F 0 "#PWR038" H 9150 2850 50  0001 C CNN
F 1 "GND" H 9150 2950 50  0000 C CNN
F 2 "" H 9150 3100 50  0000 C CNN
F 3 "" H 9150 3100 50  0000 C CNN
	1    9150 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7475 2650 7475 2800
Wire Wire Line
	7975 2800 8300 2800
Wire Wire Line
	9025 2800 9275 2800
Wire Wire Line
	9775 2800 9800 2800
Connection ~ 8075 2800
$Comp
L R-RESCUE-pacman-main R5
U 1 1 580ABC55
P 9525 2800
F 0 "R5" V 9605 2800 40  0000 C CNN
F 1 "510" V 9532 2801 40  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 9455 2800 30  0001 C CNN
F 3 "" H 9525 2800 30  0000 C CNN
F 4 "DigiKey" V 9525 2800 60  0001 C CNN "Supplier"
F 5 "RHM510KCT-ND" V 9525 2800 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/rohm-semiconductor/ESR10EZPJ511/RHM510KCT-ND/1763033" V 9525 2800 60  0001 C CNN "Supplier URL"
F 7 "Rohm Semiconductor" V 9525 2800 60  0001 C CNN "Manufacturer"
F 8 "ESR10EZPJ511" V 9525 2800 60  0001 C CNN "Manufacturer P/N"
F 9 "http://rohmfs.rohm.com/en/products/databook/datasheet/passive/resistor/chip_resistor/esr.pdf" V 9525 2800 60  0001 C CNN "Datasheet URL"
F 10 "RES SMD 510 OHM 5% 0.4W 0805" V 9525 2800 60  0001 C CNN "Description"
F 11 "0.10" V 9525 2800 60  0001 C CNN "Unit Cost"
	1    9525 2800
	0    1    1    0   
$EndComp
$Comp
L C C29
U 1 1 58003966
P 9150 2950
F 0 "C29" H 9200 3050 50  0000 L CNN
F 1 ".1u" H 9175 2850 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 9188 2800 50  0001 C CNN
F 3 "" H 9150 2950 50  0000 C CNN
F 4 "DigiKey" H 9150 2950 60  0001 C CNN "Supplier"
F 5 "399-7845-1-ND" H 9150 2950 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/kemet/C0603C104M5RACTU/399-7845-1-ND/3471568" H 9150 2950 60  0001 C CNN "Supplier URL"
F 7 "Kemet" H 9150 2950 60  0001 C CNN "Manufacturer"
F 8 "C0603C104M5RACTU" H 9150 2950 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.kemet.com/docfinder?Partnumber=C0603C104M5RACTU" H 9150 2950 60  0001 C CNN "Datasheet URL"
F 10 "0.10µF 50V Ceramic Capacitor X7R 0603 (1608 Metric) 0.063\" L x 0.031\" W (1.60mm x 0.80mm)" H 9150 2950 60  0001 C CNN "Description"
F 11 "0.10" H 9150 2950 60  0001 C CNN "Unit Cost"
	1    9150 2950
	1    0    0    -1  
$EndComp
Connection ~ 9150 2800
$EndSCHEMATC
