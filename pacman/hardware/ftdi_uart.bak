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
Sheet 5 6
Title "Battery Pack Management Computer"
Date "2016-12-13"
Rev "0.8"
Comp "Lafayette College"
Comment1 "Fall Semester 2016"
Comment2 "Supervisor: Christopher Nadovich"
Comment3 "Engineer: Preston Bejabeng"
Comment4 "DEVELOPMENT ONLY"
$EndDescr
Text Label 4250 4000 0    60   ~ 0
USBD-
Text Label 4250 4100 0    60   ~ 0
USBD+
Text Label 4250 3750 0    60   ~ 0
VUSB
Text Label 7200 3700 2    60   ~ 0
TXD
Text Label 7200 3800 2    60   ~ 0
RXD
$Comp
L C-RESCUE-pacman-main C20
U 1 1 560D7928
P 4750 5300
F 0 "C20" H 4750 5400 40  0000 L CNN
F 1 "0.1u" H 4756 5215 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4788 5150 30  0001 C CNN
F 3 "" H 4750 5300 60  0000 C CNN
	1    4750 5300
	1    0    0    -1  
$EndComp
NoConn ~ 6700 4000
NoConn ~ 6700 4200
NoConn ~ 6700 4300
NoConn ~ 6700 4400
NoConn ~ 6700 4700
NoConn ~ 6700 4800
NoConn ~ 6700 4900
NoConn ~ 4850 4700
NoConn ~ 4850 4600
NoConn ~ 4850 4400
Text Label 8050 3950 0    60   ~ 0
~RESET
Text Label 9950 3950 2    60   ~ 0
DTR
Wire Wire Line
	4850 3650 4750 3650
Wire Wire Line
	4750 4900 4850 4900
Wire Wire Line
	4850 4000 4250 4000
Wire Wire Line
	4250 4100 4850 4100
Wire Wire Line
	4250 3750 4850 3750
Wire Wire Line
	6700 3700 7200 3700
Wire Wire Line
	6700 3800 7200 3800
Wire Wire Line
	4750 5450 4750 5700
Wire Wire Line
	4750 5700 6100 5700
Wire Wire Line
	6100 5700 6100 5600
Wire Wire Line
	5950 5600 5950 5700
Connection ~ 5950 5700
Wire Wire Line
	5800 5600 5800 5800
Connection ~ 5800 5700
Wire Wire Line
	5650 5600 5650 5700
Connection ~ 5650 5700
Wire Wire Line
	5500 5600 5500 5700
Connection ~ 5500 5700
Wire Wire Line
	8850 3950 8050 3950
Wire Wire Line
	9150 3950 9950 3950
$Comp
L GND-RESCUE-pacman-main #PWR047
U 1 1 560D7983
P 5800 5800
F 0 "#PWR047" H 5800 5800 30  0001 C CNN
F 1 "GND" H 5800 5730 30  0001 C CNN
F 2 "" H 5800 5800 60  0000 C CNN
F 3 "" H 5800 5800 60  0000 C CNN
	1    5800 5800
	1    0    0    -1  
$EndComp
Text Notes 8050 3800 0    60   ~ 0
FTDI Reset Connection
Text Notes 4650 2700 0    100  ~ 0
USB UART
$Comp
L FT232RL U12
U 1 1 560D798D
P 5800 4400
F 0 "U12" H 5800 5300 60  0000 C CNN
F 1 "FT232RL" H 6200 3400 60  0000 L CNN
F 2 "Housings_SSOP:SSOP-28_5.3x10.2mm_Pitch0.65mm" H 5800 4400 60  0001 C CNN
F 3 "" H 5800 4400 60  0000 C CNN
F 4 "Digikey" H 5800 4400 60  0001 C CNN "Supplier"
F 5 "768-1007-1-ND" H 5800 4400 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/FT232RL-REEL/768-1007-1-ND/1836402" H 5800 4400 60  0001 C CNN "Supplier URL"
F 7 "FTDI" H 5800 4400 60  0001 C CNN "Manufacturer"
F 8 "FT232RL-REEL" H 5800 4400 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.ftdichip.com/Support/Documents/DataSheets/ICs/DS_FT232R.pdf" H 5800 4400 60  0001 C CNN "Datasheet URL"
F 10 "IC USB FS SERIAL UART 28-SSOP" H 5800 4400 60  0001 C CNN "Description"
F 11 "4.50" H 5800 4400 60  0001 C CNN "Unit Cost"
	1    5800 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 3650 4750 5150
$Comp
L C-RESCUE-pacman-main C21
U 1 1 560D79A3
P 9000 3950
F 0 "C21" H 9025 4050 50  0000 L CNN
F 1 "0.1u" H 9025 3850 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 9038 3800 30  0001 C CNN
F 3 "" H 9000 3950 60  0000 C CNN
	1    9000 3950
	0    1    1    0   
$EndComp
Text Label 7200 4100 2    60   ~ 0
DTR
Wire Wire Line
	6700 4100 7200 4100
NoConn ~ 6700 3900
Text HLabel 9900 2800 2    60   BiDi ~ 0
TXD
Text HLabel 9900 3000 2    60   BiDi ~ 0
RXD
Text HLabel 9900 2600 2    60   Output ~ 0
~RESET
Text Label 9400 2800 0    60   ~ 0
TXD
Text Label 9400 3000 0    60   ~ 0
RXD
Wire Wire Line
	9900 2800 9400 2800
Wire Wire Line
	9900 3000 9400 3000
Text Label 9400 2600 0    60   ~ 0
~RESET
Wire Wire Line
	9900 2600 9400 2600
Wire Wire Line
	1850 5000 3000 5000
Wire Wire Line
	1100 5000 1450 5000
Text Label 3000 5000 2    60   ~ 0
VUSB
Text Notes 1050 3650 0    100  ~ 0
USB BOOTSTRAP POWER
Text Notes 1100 4600 0    60   ~ 0
This diode is used to power the\nPACMAN computer board when\nthe battery pack has been fully\ndischarged. If voltage is not\npresent between PACK+ and \nPACK-, then this diode will allow\nthe USB port to supply up to \n500mA of sustained current.\nFor periods less than 0.1 \nseconds, 1A can be drawn.
Connection ~ 4750 4900
Text Notes 4750 3350 0    60   ~ 0
This is an FTDI USB Serial Converter IC,\nit can be used to upload code, configure \nthe device, or transfer debugging information\nif the software is configured properly.\n\nDrivers available for Windows, Mac OS & Linux
$Comp
L DIODESCH D15
U 1 1 5618023D
P 1650 5000
F 0 "D15" H 1650 4900 40  0000 C CNN
F 1 "SK310A-LTP" H 1650 5100 40  0000 C CNN
F 2 "custom_footprints:do214ac" H 1650 5000 60  0001 C CNN
F 3 "" H 1650 5000 60  0000 C CNN
F 4 "Digikey" H 1650 5000 60  0001 C CNN "Supplier"
F 5 "SK310A-LTPMSCT-ND" H 1650 5000 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/SK310A-LTP/SK310A-LTPMSCT-ND/2642066" H 1650 5000 60  0001 C CNN "Supplier URL"
F 7 "Micro Commercial Components (MMC)" H 1650 5000 60  0001 C CNN "Manufacturer"
F 8 "SK310A-LTP" H 1650 5000 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.mccsemi.com/up_pdf/SK32A-LT~SK310A-LT%28DO-214AC%29.PDF" H 1650 5000 60  0001 C CNN "Datasheet URL"
F 10 "Schottky Diodes & Rectifiers DIODE SCHOTTKY 100V 3A DO214AC " H 1650 5000 60  0001 C CNN "Description"
F 11 "0.57" H 1650 5000 60  0001 C CNN "Unit Cost"
	1    1650 5000
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR048
U 1 1 56263D84
P 1100 4900
F 0 "#PWR048" H 1100 4750 50  0001 C CNN
F 1 "+5V" H 1100 5040 50  0000 C CNN
F 2 "" H 1100 4900 60  0000 C CNN
F 3 "" H 1100 4900 60  0000 C CNN
	1    1100 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 4900 1100 5000
Wire Wire Line
	10350 1400 10350 1500
Wire Wire Line
	9850 1400 10350 1400
Text Label 9850 1400 0    60   ~ 0
GND
$Comp
L GND-RESCUE-pacman-main #PWR049
U 1 1 562B7949
P 10350 1500
F 0 "#PWR049" H 10350 1500 30  0001 C CNN
F 1 "GND" H 10350 1430 30  0001 C CNN
F 2 "" H 10350 1500 60  0000 C CNN
F 3 "" H 10350 1500 60  0000 C CNN
	1    10350 1500
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR050
U 1 1 562B794F
P 9650 1100
F 0 "#PWR050" H 9650 950 50  0001 C CNN
F 1 "+3.3V" H 9650 1240 50  0000 C CNN
F 2 "" H 9650 1100 60  0000 C CNN
F 3 "" H 9650 1100 60  0000 C CNN
	1    9650 1100
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR051
U 1 1 562B7955
P 10350 1100
F 0 "#PWR051" H 10350 950 50  0001 C CNN
F 1 "+5V" H 10350 1240 50  0000 C CNN
F 2 "" H 10350 1100 60  0000 C CNN
F 3 "" H 10350 1100 60  0000 C CNN
	1    10350 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 1200 9650 1100
Wire Wire Line
	9150 1200 9650 1200
Wire Wire Line
	10350 1200 10350 1100
Wire Wire Line
	9850 1200 10350 1200
Text Label 9150 1200 0    60   ~ 0
+3.3V
Text Label 9850 1200 0    60   ~ 0
+5V
Text Notes 8550 800  0    100  ~ 0
GROUNDED LOW VOLTAGE
Text GLabel 9900 1800 2    50   Output ~ 0
VUSB
Text GLabel 9900 2000 2    50   Output ~ 0
USBD+
Text GLabel 9900 2200 2    50   Output ~ 0
USBD-
Wire Wire Line
	9900 1800 9400 1800
Wire Wire Line
	9900 2000 9400 2000
Wire Wire Line
	9900 2200 9400 2200
Text Label 9400 1800 0    60   ~ 0
VUSB
Text Label 9400 2000 0    60   ~ 0
USBD+
Text Label 9400 2200 0    60   ~ 0
USBD-
NoConn ~ 6700 4500
NoConn ~ 6700 4600
$EndSCHEMATC
