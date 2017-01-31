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
Sheet 1 6
Title "Battery Pack Management Computer"
Date "2016-12-13"
Rev "0.8"
Comp "Lafayette College"
Comment1 "Fall Semester 2016"
Comment2 "Supervisor: Christopher Nadovich"
Comment3 "Engineer: Preston Bejabeng"
Comment4 "DEVELOPMENT ONLY"
$EndDescr
NoConn ~ 4350 3250
NoConn ~ 4350 3150
NoConn ~ 4350 3050
NoConn ~ 4350 2950
NoConn ~ 4350 2850
$Comp
L C-RESCUE-pacman-main C2
U 1 1 557225A0
P 3400 5800
F 0 "C2" H 3400 5900 40  0000 L CNN
F 1 "0.1u" H 3406 5715 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 3438 5650 30  0001 C CNN
F 3 "" H 3400 5800 60  0000 C CNN
	1    3400 5800
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL-RESCUE-pacman-main X1
U 1 1 55722FB6
P 3500 2350
F 0 "X1" H 3500 2500 60  0000 C CNN
F 1 "10MHz" H 3500 2200 60  0000 C CNN
F 2 "custom_footprints:crystal_TXC_7A" H 3500 2350 60  0001 C CNN
F 3 "" H 3500 2350 60  0000 C CNN
F 4 "Digikey" H 3500 2350 60  0001 C CNN "Supplier"
F 5 "887-1741-1-ND" H 3500 2350 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-search/en?pv7=2&k=7A-10.000MAAE-T&mnonly=0&newproducts=0&ColumnSort=0&page=1&quantity=0&ptm=0&fid=0&pageSize=25" H 3500 2350 60  0001 C CNN "Supplier URL"
F 7 "TXC Corporation" H 3500 2350 60  0001 C CNN "Manufacturer"
F 8 "7A-10.000MAAE-T" H 3500 2350 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.mouser.com/ds/2/417/7a-13881.pdf" H 3500 2350 60  0001 C CNN "Datasheet URL"
F 10 "10MHz SMD Crystal" H 3500 2350 60  0001 C CNN "Description"
F 11 "0.72" H 3500 2350 60  0001 C CNN "Unit Cost"
	1    3500 2350
	1    0    0    -1  
$EndComp
$Comp
L C-RESCUE-pacman-main C1
U 1 1 5572610D
P 3200 2650
F 0 "C1" H 3200 2750 40  0000 L CNN
F 1 "10p" H 3206 2565 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 3238 2500 30  0001 C CNN
F 3 "" H 3200 2650 60  0000 C CNN
F 4 "DigiKey" H 3200 2650 60  0001 C CNN "Supplier"
F 5 "490-6112-1-ND" H 3200 2650 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/murata-electronics-north-america/GRM0335C1H100JA01D/490-6112-1-ND/3845312" H 3200 2650 60  0001 C CNN "Supplier URL"
F 7 "Murata Electronics North America" H 3200 2650 60  0001 C CNN "Manufacturer"
F 8 "GRM0335C1H100JA01D" H 3200 2650 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.murata.com/~/media/webrenewal/support/library/catalog/products/capacitor/mlcc/c02e.pdf" H 3200 2650 60  0001 C CNN "Datasheet URL"
F 10 "10pF 50V Ceramic Capacitor C0G, NP0 0201 (0603 Metric) 0.024\" L x 0.012\" W (0.60mm x 0.30mm)" H 3200 2650 60  0001 C CNN "Description"
F 11 "0.10" H 3200 2650 60  0001 C CNN "Unit Cost"
	1    3200 2650
	1    0    0    -1  
$EndComp
$Comp
L C-RESCUE-pacman-main C4
U 1 1 55726574
P 3800 2650
F 0 "C4" H 3800 2750 40  0000 L CNN
F 1 "10p" H 3806 2565 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 3838 2500 30  0001 C CNN
F 3 "" H 3800 2650 60  0000 C CNN
F 4 "DigiKey" H 3800 2650 60  0001 C CNN "Supplier"
F 5 "	490-6112-1-ND" H 3800 2650 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/murata-electronics-north-america/GRM0335C1H100JA01D/490-6112-1-ND/3845312" H 3800 2650 60  0001 C CNN "Supplier URL"
F 7 "Murata Electronics North America" H 3800 2650 60  0001 C CNN "Manufacturer"
F 8 "GRM0335C1H100JA01D" H 3800 2650 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.murata.com/~/media/webrenewal/support/library/catalog/products/capacitor/mlcc/c02e.pdf" H 3800 2650 60  0001 C CNN "Datasheet URL"
F 10 "10pF 50V Ceramic Capacitor C0G, NP0 0201 (0603 Metric) 0.024\" L x 0.012\" W (0.60mm x 0.30mm)" H 3800 2650 60  0001 C CNN "Description"
F 11 "0.10" H 3800 2650 60  0001 C CNN "Unit Cost"
	1    3800 2650
	1    0    0    -1  
$EndComp
$Comp
L C-RESCUE-pacman-main C6
U 1 1 55727969
P 4200 2650
F 0 "C6" H 4200 2750 40  0000 L CNN
F 1 "0.1u" H 4206 2565 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4238 2500 30  0001 C CNN
F 3 "" H 4200 2650 60  0000 C CNN
	1    4200 2650
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-pacman-main #PWR01
U 1 1 5572842D
P 4200 2950
F 0 "#PWR01" H 4200 2950 30  0001 C CNN
F 1 "GND" H 4200 2880 30  0001 C CNN
F 2 "" H 4200 2950 60  0000 C CNN
F 3 "" H 4200 2950 60  0000 C CNN
	1    4200 2950
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-pacman-main #PWR02
U 1 1 5572E852
P 5600 5550
F 0 "#PWR02" H 5600 5550 30  0001 C CNN
F 1 "GND" H 5600 5480 30  0001 C CNN
F 2 "" H 5600 5550 60  0000 C CNN
F 3 "" H 5600 5550 60  0000 C CNN
	1    5600 5550
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-pacman-main #PWR03
U 1 1 55737BD9
P 3400 6000
F 0 "#PWR03" H 3400 6000 30  0001 C CNN
F 1 "GND" H 3400 5930 30  0001 C CNN
F 2 "" H 3400 6000 60  0000 C CNN
F 3 "" H 3400 6000 60  0000 C CNN
	1    3400 6000
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-pacman-main #PWR04
U 1 1 55738237
P 3700 6000
F 0 "#PWR04" H 3700 6000 30  0001 C CNN
F 1 "GND" H 3700 5930 30  0001 C CNN
F 2 "" H 3700 6000 60  0000 C CNN
F 3 "" H 3700 6000 60  0000 C CNN
	1    3700 6000
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-pacman-main #PWR05
U 1 1 557384F0
P 4000 6000
F 0 "#PWR05" H 4000 6000 30  0001 C CNN
F 1 "GND" H 4000 5930 30  0001 C CNN
F 2 "" H 4000 6000 60  0000 C CNN
F 3 "" H 4000 6000 60  0000 C CNN
	1    4000 6000
	1    0    0    -1  
$EndComp
Text Label 7300 4350 2    60   ~ 0
SCL
Text Label 7300 4450 2    60   ~ 0
SDA
Text Label 7450 4850 2    60   ~ 0
CANTX
Text Label 7450 4950 2    60   ~ 0
CANRX
Text Label 3850 1650 0    60   ~ 0
~RESET_AVR
$Comp
L GND-RESCUE-pacman-main #PWR06
U 1 1 55751BF3
P 3500 3050
F 0 "#PWR06" H 3500 3050 30  0001 C CNN
F 1 "GND" H 3500 2980 30  0001 C CNN
F 2 "" H 3500 3050 60  0000 C CNN
F 3 "" H 3500 3050 60  0000 C CNN
	1    3500 3050
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH-RESCUE-pacman-main SW1
U 1 1 55715F36
P 7400 1250
F 0 "SW1" H 7550 1360 50  0000 C CNN
F 1 "RESET" H 7400 1170 50  0000 C CNN
F 2 "custom_footprints:SW_RACON_8" H 7400 1250 60  0001 C CNN
F 3 "" H 7400 1250 60  0000 C CNN
F 4 "Digikey" H 7400 1250 60  0001 C CNN "Supplier"
F 5 "CKN9363CT-ND" H 7400 1250 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/c-k-components/1.14100.5030000/CKN9363CT-ND/583462" H 7400 1250 60  0001 C CNN "Supplier URL"
F 7 "C&K Components" H 7400 1250 60  0001 C CNN "Manufacturer"
F 8 "1.14100.5030000" H 7400 1250 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.ck-components.com/43191/short-travel-racon.pdf/" H 7400 1250 60  0001 C CNN "Datasheet URL"
F 10 "SWITCH PUSH SPST-NO 0.1A 42V" H 7400 1250 60  0001 C CNN "Description"
F 11 "2.43" H 7400 1250 60  0001 C CNN "Unit Cost"
	1    7400 1250
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-pacman-main #PWR07
U 1 1 557160FF
P 7900 1350
F 0 "#PWR07" H 7900 1350 30  0001 C CNN
F 1 "GND" H 7900 1280 30  0001 C CNN
F 2 "" H 7900 1350 60  0000 C CNN
F 3 "" H 7900 1350 60  0000 C CNN
	1    7900 1350
	1    0    0    -1  
$EndComp
Text Label 6750 1250 0    60   ~ 0
~RESET
Text Notes 6850 1000 0    60   ~ 0
AVR Reset Switch
$Comp
L C-RESCUE-pacman-main C3
U 1 1 5572D9B1
P 3700 5800
F 0 "C3" H 3700 5900 40  0000 L CNN
F 1 "0.1u" H 3706 5715 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 3738 5650 30  0001 C CNN
F 3 "" H 3700 5800 60  0000 C CNN
	1    3700 5800
	1    0    0    -1  
$EndComp
$Comp
L C-RESCUE-pacman-main C5
U 1 1 5572DAEA
P 4000 5800
F 0 "C5" H 4000 5900 40  0000 L CNN
F 1 "0.1u" H 4006 5715 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4038 5650 30  0001 C CNN
F 3 "" H 4000 5800 60  0000 C CNN
	1    4000 5800
	1    0    0    -1  
$EndComp
Text Label 7450 3450 2    60   ~ 0
PC0
Text Label 7450 3550 2    60   ~ 0
PC1
NoConn ~ 6950 4750
NoConn ~ 6950 5050
$Comp
L R-RESCUE-pacman-main R6
U 1 1 55729155
P 9350 2800
F 0 "R6" V 9430 2800 40  0000 C CNN
F 1 "1k" V 9357 2801 40  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 9280 2800 30  0001 C CNN
F 3 "" H 9350 2800 30  0000 C CNN
	1    9350 2800
	0    1    1    0   
$EndComp
$Comp
L R-RESCUE-pacman-main R7
U 1 1 55729416
P 9350 3200
F 0 "R7" V 9430 3200 40  0000 C CNN
F 1 "1k" V 9357 3201 40  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 9280 3200 30  0001 C CNN
F 3 "" H 9350 3200 30  0000 C CNN
	1    9350 3200
	0    1    1    0   
$EndComp
$Comp
L LED-RESCUE-pacman-main D1
U 1 1 5572956F
P 9900 2800
F 0 "D1" H 9900 2900 50  0000 C CNN
F 1 "POWER" H 9900 2700 50  0000 C CNN
F 2 "LEDs:LED_0603" H 9900 2800 60  0001 C CNN
F 3 "" H 9900 2800 60  0000 C CNN
F 4 "0603 LED (BLUE)" H 9900 2800 60  0001 C CNN "Description"
	1    9900 2800
	1    0    0    -1  
$EndComp
$Comp
L LED-RESCUE-pacman-main D2
U 1 1 557296B7
P 9900 3200
F 0 "D2" H 9900 3300 50  0000 C CNN
F 1 "FAULT" H 9900 3100 50  0000 C CNN
F 2 "LEDs:LED_0603" H 9900 3200 60  0001 C CNN
F 3 "" H 9900 3200 60  0000 C CNN
F 4 "0603 LED (RED)" H 9900 3200 60  0001 C CNN "Description"
	1    9900 3200
	1    0    0    -1  
$EndComp
Text Label 8900 3600 0    60   ~ 0
PC0
$Comp
L GND-RESCUE-pacman-main #PWR08
U 1 1 5573AD8E
P 10200 2900
F 0 "#PWR08" H 10200 2900 30  0001 C CNN
F 1 "GND" H 10200 2830 30  0001 C CNN
F 2 "" H 10200 2900 60  0000 C CNN
F 3 "" H 10200 2900 60  0000 C CNN
	1    10200 2900
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-pacman-main #PWR09
U 1 1 5573ADA2
P 10200 3300
F 0 "#PWR09" H 10200 3300 30  0001 C CNN
F 1 "GND" H 10200 3230 30  0001 C CNN
F 2 "" H 10200 3300 60  0000 C CNN
F 3 "" H 10200 3300 60  0000 C CNN
	1    10200 3300
	1    0    0    -1  
$EndComp
$Sheet
S 700  1400 1500 600 
U 5574E706
F0 "Isolated Power Supply" 60
F1 "power.sch" 60
F2 "SDA" O R 2200 1600 60 
F3 "SCL" O R 2200 1800 60 
$EndSheet
Text Label 3850 4350 0    60   ~ 0
RXD
Text Label 3850 4450 0    60   ~ 0
TXD
$Comp
L AT90CAN32-M U1
U 1 1 55247ABB
P 5650 3350
F 0 "U1" H 6650 5250 50  0000 L BNN
F 1 "AT90CAN128-M" H 6750 1400 50  0000 R BNN
F 2 "Housings_QFP:TQFP-64_14x14mm_Pitch0.8mm" H 5700 3350 50  0001 C CNN
F 3 "" H 5650 3350 60  0001 C CNN
F 4 "Digikey" H 5650 3350 60  0001 C CNN "Supplier"
F 5 "AT90CAN128-16AURCT-ND" H 5650 3350 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/atmel/AT90CAN128-16AUR/AT90CAN128-16AURCT-ND/3789383" H 5650 3350 60  0001 C CNN "Supplier URL"
F 7 "Atmel" H 5650 3350 60  0001 C CNN "Manufacturer"
F 8 "AT90CAN128-16AUR" H 5650 3350 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.atmel.com/Images/7679s.pdf" H 5650 3350 60  0001 C CNN "Datasheet URL"
F 10 "IC MCU 8BIT 128KB FLASH 64TQFP" H 5650 3350 60  0001 C CNN "Description"
F 11 "10.40" H 5650 3350 60  0001 C CNN "Unit Cost"
	1    5650 3350
	1    0    0    -1  
$EndComp
Text Notes 3350 5300 0    60   ~ 0
AVR Decoupling\nCapacitors (U1)
Text Notes 3450 1450 0    100  ~ 0
AVR MICROCONTROLLER
Text Notes 8700 2500 0    100  ~ 0
SYSTEM STATUS LEDS
Text Notes 550  800  0    100  ~ 0
POWER ELECTRONICS
Text Notes 3200 1900 0    40   ~ 0
Maximum Frequency\nDatasheet (Page 368)\nVsafe = 1.8/8*(F-8)+2.7
Text Notes 7850 5200 0    100  ~ 0
EXTERNAL WATCHDOG
$Comp
L ADM6320 U2
U 1 1 558A42AE
P 8950 5750
F 0 "U2" H 8950 5850 60  0000 C CNN
F 1 "ADM6320" H 8950 5650 60  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-5" H 8950 5750 60  0001 C CNN
F 3 "" H 8950 5750 60  0000 C CNN
F 4 "Digikey" H 8950 5750 60  0001 C CNN "Supplier"
F 5 "ADM6320CY29ARJZ-R7CT-ND" H 8950 5750 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/ADM6320CY29ARJZ-R7/ADM6320CY29ARJZ-R7CT-ND/2467999" H 8950 5750 60  0001 C CNN "Supplier URL"
F 7 "Analog Devices" H 8950 5750 60  0001 C CNN "Manufacturer"
F 8 "ADM6320CY29ARJZ-R7" H 8950 5750 60  0001 C CNN "Manufacturer P/N"
F 9 "http://www.mouser.com/ds/2/609/ADM6316_6317_6318_6319_6320_6321_6322-259224.pdf" H 8950 5750 60  0001 C CNN "Datasheet URL"
F 10 "External Watchdog IC 2.9V 1600mS 140mS" H 8950 5750 60  0001 C CNN "Description"
F 11 "1.52" H 8950 5750 60  0001 C CNN "Unit Cost"
	1    8950 5750
	1    0    0    -1  
$EndComp
Text Label 7900 5950 0    60   ~ 0
~RESET
Text Label 7900 5750 0    60   ~ 0
GND
Text Label 7900 5550 0    60   ~ 0
~RESET_AVR
Text Label 9675 5300 0    60   ~ 0
+3.3V
Text Label 10000 5950 2    60   ~ 0
WATCHDOG
Text Label 7550 1650 2    60   ~ 0
WATCHDOG
Text Label 2700 1600 2    60   ~ 0
SDA
Text Label 2700 1800 2    60   ~ 0
SCL
NoConn ~ 4350 4550
NoConn ~ 4350 4650
Text Label 2700 3000 2    60   ~ 0
RXD
Text Label 2700 3100 2    60   ~ 0
TXD
Text Label 2700 3400 2    60   ~ 0
~RESET_AVR
$Sheet
S 1300 4450 1400 800 
U 560A91B4
F0 "Safety Loop Wiring" 60
F1 "safety_loop.sch" 60
F2 "SAFETY_CTRL" I L 1300 4575 60 
F3 "CHARGE_CTRL" I L 1300 4750 60 
F4 "FAN_CTRL" I L 1300 4925 60 
$EndSheet
NoConn ~ 4350 4750
NoConn ~ 4350 4850
NoConn ~ 4350 4950
NoConn ~ 6950 4550
NoConn ~ 6950 4650
Text Notes 700  1150 0    60   ~ 0
**DC-DC Switching Power Regulation**\n5V and 3.3V outputs are isolated from High Voltage,\nbut not each other
Text Notes 600  2600 0    100  ~ 0
FTDI USB UART
NoConn ~ 4350 5050
NoConn ~ 6950 2250
NoConn ~ 6950 2350
$Comp
L R-RESCUE-pacman-main R1
U 1 1 561E7314
P 4750 7000
F 0 "R1" V 4830 7000 40  0000 C CNN
F 1 "10k" V 4757 7001 40  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4680 7000 30  0001 C CNN
F 3 "" H 4750 7000 30  0000 C CNN
	1    4750 7000
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-pacman-main R2
U 1 1 561E731A
P 5050 7000
F 0 "R2" V 5130 7000 40  0000 C CNN
F 1 "10k" V 5057 7001 40  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4980 7000 30  0001 C CNN
F 3 "" H 5050 7000 30  0000 C CNN
	1    5050 7000
	1    0    0    -1  
$EndComp
Text Label 4400 7250 0    60   ~ 0
SDA
Text Label 4400 7350 0    60   ~ 0
SCL
Text Notes 4350 6500 0    100  ~ 0
I2C PULLUP
Text Label 700  6100 0    60   ~ 0
CANTX
Text Label 700  6300 0    60   ~ 0
CANRX
Text Label 700  4575 0    60   ~ 0
SLOOP_CTRL
Text Label 700  4750 0    60   ~ 0
CHRG_CTRL
$Comp
L +3.3V #PWR010
U 1 1 5615C3C9
P 8900 2700
F 0 "#PWR010" H 8900 2550 50  0001 C CNN
F 1 "+3.3V" H 8900 2840 50  0000 C CNN
F 2 "" H 8900 2700 60  0000 C CNN
F 3 "" H 8900 2700 60  0000 C CNN
	1    8900 2700
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR011
U 1 1 5615DEFA
P 5600 1150
F 0 "#PWR011" H 5600 1000 50  0001 C CNN
F 1 "+3.3V" H 5600 1290 50  0000 C CNN
F 2 "" H 5600 1150 60  0000 C CNN
F 3 "" H 5600 1150 60  0000 C CNN
	1    5600 1150
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR012
U 1 1 5615EFBD
P 3400 5600
F 0 "#PWR012" H 3400 5450 50  0001 C CNN
F 1 "+3.3V" H 3400 5740 50  0000 C CNN
F 2 "" H 3400 5600 60  0000 C CNN
F 3 "" H 3400 5600 60  0000 C CNN
	1    3400 5600
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR013
U 1 1 5615F187
P 3700 5600
F 0 "#PWR013" H 3700 5450 50  0001 C CNN
F 1 "+3.3V" H 3700 5740 50  0000 C CNN
F 2 "" H 3700 5600 60  0000 C CNN
F 3 "" H 3700 5600 60  0000 C CNN
	1    3700 5600
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR014
U 1 1 5615F1E9
P 4000 5600
F 0 "#PWR014" H 4000 5450 50  0001 C CNN
F 1 "+3.3V" H 4000 5740 50  0000 C CNN
F 2 "" H 4000 5600 60  0000 C CNN
F 3 "" H 4000 5600 60  0000 C CNN
	1    4000 5600
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR015
U 1 1 561620F3
P 4750 6750
F 0 "#PWR015" H 4750 6600 50  0001 C CNN
F 1 "+3.3V" H 4750 6890 50  0000 C CNN
F 2 "" H 4750 6750 60  0000 C CNN
F 3 "" H 4750 6750 60  0000 C CNN
	1    4750 6750
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR016
U 1 1 561620F9
P 5050 6750
F 0 "#PWR016" H 5050 6600 50  0001 C CNN
F 1 "+3.3V" H 5050 6890 50  0000 C CNN
F 2 "" H 5050 6750 60  0000 C CNN
F 3 "" H 5050 6750 60  0000 C CNN
	1    5050 6750
	1    0    0    -1  
$EndComp
Text Label 700  4925 0    60   ~ 0
FAN_CTRL
$Sheet
S 1300 5900 1400 600 
U 561EAC87
F0 "CAN Transceiver" 60
F1 "can_xcvr.sch" 60
F2 "CANTX" I L 1300 6100 60 
F3 "CANRX" I L 1300 6300 60 
$EndSheet
Text Notes 8600 6500 0    60   ~ 0
Threshold: 2.93 V\nTimeout: 1600 ms\nReset: 140 ms
Text Notes 700  7650 0    60   ~ 0
EXTERNAL CONNECTORS
Text Label 9800 1500 0    60   ~ 0
GND
$Comp
L GND-RESCUE-pacman-main #PWR017
U 1 1 557591DE
P 10300 1600
F 0 "#PWR017" H 10300 1600 30  0001 C CNN
F 1 "GND" H 10300 1530 30  0001 C CNN
F 2 "" H 10300 1600 60  0000 C CNN
F 3 "" H 10300 1600 60  0000 C CNN
	1    10300 1600
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR018
U 1 1 5615E01A
P 9600 1200
F 0 "#PWR018" H 9600 1050 50  0001 C CNN
F 1 "+3.3V" H 9600 1340 50  0000 C CNN
F 2 "" H 9600 1200 60  0000 C CNN
F 3 "" H 9600 1200 60  0000 C CNN
	1    9600 1200
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR019
U 1 1 5611B7C6
P 10300 1200
F 0 "#PWR019" H 10300 1050 50  0001 C CNN
F 1 "+5V" H 10300 1340 50  0000 C CNN
F 2 "" H 10300 1200 60  0000 C CNN
F 3 "" H 10300 1200 60  0000 C CNN
	1    10300 1200
	1    0    0    -1  
$EndComp
Text Label 9100 1300 0    60   ~ 0
+3.3V
Text Label 9800 1300 0    60   ~ 0
+5V
$Sheet
S 700  2800 1500 800 
U 560D7137
F0 "FTDI USB UART" 60
F1 "ftdi_uart.sch" 60
F2 "TXD" O R 2200 3000 60 
F3 "RXD" O R 2200 3100 60 
F4 "~RESET" O R 2200 3400 60 
$EndSheet
Text Notes 8450 800  0    100  ~ 0
GROUNDED LOW VOLTAGE
Text GLabel 7450 4450 2    50   Output ~ 0
SW_SDA
Text GLabel 7450 4350 2    50   Output ~ 0
SW_SCL
Text GLabel 4000 3450 0    50   BiDi ~ 0
ADC0
Text GLabel 4000 3550 0    50   BiDi ~ 0
ADC1
Text GLabel 4000 3950 0    50   BiDi ~ 0
TMS
Text GLabel 4000 3850 0    50   BiDi ~ 0
TCK
Text GLabel 4000 4150 0    50   BiDi ~ 0
TDI
Text GLabel 4000 4050 0    50   BiDi ~ 0
TDO
$Sheet
S 650  6975 2325 925 
U 5623433E
F0 "External Connectors" 60
F1 "connectors.sch" 60
F2 "PB0" O R 2975 7050 60 
F3 "PB1" O R 2975 7200 60 
F4 "PB2" O R 2975 7350 60 
F5 "PB3" O R 2975 7500 60 
F6 "PB4" O R 2975 7675 60 
F7 "PB5" O R 2975 7825 60 
$EndSheet
Text Label 7550 2150 2    60   ~ 0
FAN_CTRL
Text Label 9050 1850 0    60   ~ 0
~RESET
Text GLabel 9850 1850 2    60   Output ~ 0
~RESET
Text GLabel 9850 2000 2    50   Output ~ 0
~RESET_AVR
Text Label 9050 2000 0    60   ~ 0
~RESET_AVR
Text Notes 600  4200 0    100  ~ 0
SAFETY LOOP WIRING
Text Notes 600  6900 0    100  ~ 0
CONNECTORS
Text Notes 600  5750 0    100  ~ 0
CAN TRANCEIVER
Text Label 7550 1950 2    60   ~ 0
SLOOP_CTRL
Text Label 7550 2050 2    60   ~ 0
CHRG_CTRL
$Comp
L R-RESCUE-pacman-main R34
U 1 1 5629F005
P 7300 5950
F 0 "R34" V 7380 5950 40  0000 C CNN
F 1 "10k" V 7307 5951 40  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7230 5950 30  0001 C CNN
F 3 "" H 7300 5950 30  0000 C CNN
	1    7300 5950
	1    0    0    -1  
$EndComp
Text Notes 7150 6600 0    60   ~ 0
Open Drain\nreset pull-up resistor
Text Label 7800 6300 2    60   ~ 0
~RESET_AVR
Text Label 6800 5600 0    60   ~ 0
+3.3V
Text Notes 9500 2750 0    60   ~ 0
GREEN
Text Notes 9500 3150 0    60   ~ 0
RED
Connection ~ 5600 1250
Wire Wire Line
	5600 1250 5600 1150
Connection ~ 5450 1250
Wire Wire Line
	5450 1350 5450 1250
Wire Wire Line
	5850 1250 5850 1350
Wire Wire Line
	5350 1250 5850 1250
Wire Wire Line
	5350 1350 5350 1250
Connection ~ 5600 5450
Wire Wire Line
	5600 5450 5600 5550
Connection ~ 5450 5450
Wire Wire Line
	5450 5350 5450 5450
Wire Wire Line
	5850 5450 5850 5350
Wire Wire Line
	5350 5450 5850 5450
Wire Wire Line
	5350 5350 5350 5450
Wire Wire Line
	4200 2800 4200 2950
Wire Wire Line
	4200 2350 4350 2350
Wire Wire Line
	4200 2350 4200 2500
Connection ~ 3500 2950
Wire Wire Line
	3800 2950 3800 2800
Wire Wire Line
	3200 2950 3800 2950
Wire Wire Line
	3200 2950 3200 2800
Connection ~ 3800 2350
Connection ~ 3200 2350
Wire Wire Line
	3200 1950 3200 2500
Wire Wire Line
	3800 2050 3800 2500
Wire Wire Line
	4350 4450 3850 4450
Wire Wire Line
	4350 4350 3850 4350
Wire Wire Line
	6950 4850 7450 4850
Wire Wire Line
	6950 4950 7450 4950
Wire Wire Line
	4350 1650 3850 1650
Wire Wire Line
	3500 2950 3500 3050
Wire Wire Line
	7700 1250 7900 1250
Wire Wire Line
	7900 1250 7900 1350
Wire Wire Line
	6750 1250 7100 1250
Wire Wire Line
	6950 2550 7550 2550
Wire Wire Line
	9600 2800 9700 2800
Wire Wire Line
	9600 3200 9700 3200
Wire Wire Line
	9100 3200 8900 3200
Wire Wire Line
	9100 2800 8900 2800
Wire Wire Line
	10100 2800 10200 2800
Wire Wire Line
	10200 2800 10200 2900
Wire Wire Line
	10100 3200 10200 3200
Wire Wire Line
	10200 3200 10200 3300
Wire Wire Line
	3800 2050 4350 2050
Wire Wire Line
	3200 1950 4350 1950
Wire Wire Line
	4350 3850 4000 3850
Wire Wire Line
	4350 3950 4000 3950
Wire Wire Line
	4350 4050 4000 4050
Wire Wire Line
	4350 4150 4000 4150
Wire Wire Line
	7900 5950 8400 5950
Wire Wire Line
	8400 5750 7900 5750
Wire Wire Line
	8400 5550 7900 5550
Wire Wire Line
	9500 5550 10275 5550
Wire Wire Line
	9500 5950 10000 5950
Wire Wire Line
	6950 1650 7550 1650
Wire Wire Line
	4350 3450 4000 3450
Wire Wire Line
	4350 3550 4000 3550
Wire Wire Line
	2200 1600 2700 1600
Wire Wire Line
	2200 1800 2700 1800
Wire Wire Line
	2200 3000 2700 3000
Wire Wire Line
	2200 3100 2700 3100
Wire Wire Line
	2200 3400 2700 3400
Wire Wire Line
	6950 2650 7550 2650
Wire Wire Line
	6950 2750 7550 2750
Wire Wire Line
	6950 2850 7550 2850
Wire Wire Line
	6950 2950 7550 2950
Wire Wire Line
	6950 3050 7550 3050
Wire Wire Line
	6950 3450 7450 3450
Wire Wire Line
	6950 3550 7450 3550
Wire Wire Line
	7450 4350 6950 4350
Wire Wire Line
	6950 4450 7450 4450
Wire Wire Line
	4400 7350 5050 7350
Wire Wire Line
	4400 7250 4750 7250
Wire Wire Line
	5050 7350 5050 7250
Wire Wire Line
	1300 6100 700  6100
Wire Wire Line
	1300 6300 700  6300
Wire Wire Line
	1300 4575 700  4575
Wire Wire Line
	1300 4750 700  4750
Wire Wire Line
	8900 2800 8900 2700
Wire Wire Line
	1300 4925 700  4925
Wire Wire Line
	10300 1500 10300 1600
Wire Wire Line
	9800 1500 10300 1500
Wire Wire Line
	9600 1300 9600 1200
Wire Wire Line
	9100 1300 9600 1300
Wire Wire Line
	10300 1300 10300 1200
Wire Wire Line
	9800 1300 10300 1300
Wire Wire Line
	6950 2150 7550 2150
Wire Wire Line
	9850 1850 9050 1850
Wire Wire Line
	9850 2000 9050 2000
Wire Wire Line
	6950 1950 7550 1950
Wire Wire Line
	6950 2050 7550 2050
Wire Wire Line
	7300 6300 7800 6300
Wire Wire Line
	7300 6200 7300 6300
Wire Wire Line
	7300 5600 6800 5600
Wire Wire Line
	7300 5600 7300 5700
Wire Wire Line
	3400 5600 3400 5650
Wire Wire Line
	3700 5600 3700 5650
Wire Wire Line
	4000 5600 4000 5650
Wire Wire Line
	4000 5950 4000 6000
Wire Wire Line
	3700 5950 3700 6000
Wire Wire Line
	3400 5950 3400 6000
NoConn ~ 6950 1750
Wire Wire Line
	10200 3600 10200 3700
Wire Wire Line
	10100 3600 10200 3600
Wire Wire Line
	9100 3600 8900 3600
Wire Wire Line
	9600 3600 9700 3600
Text Notes 9500 3550 0    60   ~ 0
GREEN
$Comp
L GND-RESCUE-pacman-main #PWR020
U 1 1 5573AE62
P 10200 3700
F 0 "#PWR020" H 10200 3700 30  0001 C CNN
F 1 "GND" H 10200 3630 30  0001 C CNN
F 2 "" H 10200 3700 60  0000 C CNN
F 3 "" H 10200 3700 60  0000 C CNN
	1    10200 3700
	1    0    0    -1  
$EndComp
Text Label 8900 3200 0    60   ~ 0
PC1
$Comp
L LED-RESCUE-pacman-main D3
U 1 1 55735E6E
P 9900 3600
F 0 "D3" H 9900 3700 50  0000 C CNN
F 1 "SPARE" H 9900 3500 50  0000 C CNN
F 2 "LEDs:LED_0603" H 9900 3600 60  0001 C CNN
F 3 "" H 9900 3600 60  0000 C CNN
F 4 "0603 LED (BLUE)" H 9900 3600 60  0001 C CNN "Description"
	1    9900 3600
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-pacman-main R8
U 1 1 55735E62
P 9350 3600
F 0 "R8" V 9430 3600 40  0000 C CNN
F 1 "1k" V 9357 3601 40  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 9280 3600 30  0001 C CNN
F 3 "" H 9350 3600 30  0000 C CNN
	1    9350 3600
	0    1    1    0   
$EndComp
NoConn ~ 6950 3750
NoConn ~ 6950 3850
NoConn ~ 6950 3950
NoConn ~ 6950 4050
NoConn ~ 6950 4150
Wire Wire Line
	6950 1850 7550 1850
Text Label 7550 1850 2    60   ~ 0
SLOOP_DET
NoConn ~ 6950 3650
NoConn ~ 4350 3650
NoConn ~ 4350 3750
Text GLabel 7550 1850 2    60   Input ~ 0
SLOOP_DET
NoConn ~ 6950 3150
NoConn ~ 6950 3250
$Comp
L C C18
U 1 1 57F1ABB7
P 8250 6100
F 0 "C18" H 8275 6200 50  0000 L CNN
F 1 "0.1u" H 8275 6000 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 8288 5950 50  0001 C CNN
F 3 "" H 8250 6100 50  0000 C CNN
F 4 "DigiKey" H 8250 6100 60  0001 C CNN "Supplier"
F 5 "490-1524-1-ND" H 8250 6100 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/murata-electronics-north-america/GRM188R71E104KA01D/490-1524-1-ND/587865" H 8250 6100 60  0001 C CNN "Supplier URL"
F 7 "Murata Electronics North America" H 8250 6100 60  0001 C CNN "Manufacturer"
F 8 "GRM188R71E104KA01D" H 8250 6100 60  0001 C CNN "Manufacturer P/N"
F 9 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRM188R71E104KA01-01.pdf" H 8250 6100 60  0001 C CNN "Datasheet URL"
F 10 "0.10µF 25V Ceramic Capacitor X7R 0603 (1608 Metric) 0.063\" L x 0.031\" W (1.60mm x 0.80mm)" H 8250 6100 60  0001 C CNN "Description"
F 11 "0.10" H 8250 6100 60  0001 C CNN "Unit Cost"
	1    8250 6100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR021
U 1 1 57F1B46B
P 10275 5950
F 0 "#PWR021" H 10275 5700 50  0001 C CNN
F 1 "GND" H 10275 5800 50  0000 C CNN
F 2 "" H 10275 5950 50  0000 C CNN
F 3 "" H 10275 5950 50  0000 C CNN
	1    10275 5950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR022
U 1 1 57F1C370
P 8250 6250
F 0 "#PWR022" H 8250 6000 50  0001 C CNN
F 1 "GND" H 8250 6100 50  0000 C CNN
F 2 "" H 8250 6250 50  0000 C CNN
F 3 "" H 8250 6250 50  0000 C CNN
	1    8250 6250
	1    0    0    -1  
$EndComp
Connection ~ 8250 5950
Wire Wire Line
	10025 5300 10025 5550
Wire Wire Line
	10275 5550 10275 5650
Connection ~ 10025 5550
Wire Wire Line
	9675 5300 10025 5300
$Comp
L C C26
U 1 1 580A745A
P 10275 5800
F 0 "C26" H 10300 5900 50  0000 L CNN
F 1 "0.1u" H 10300 5700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 10313 5650 50  0001 C CNN
F 3 "" H 10275 5800 50  0000 C CNN
F 4 "DigiKey" H 10275 5800 60  0001 C CNN "Supplier"
F 5 "490-1524-1-ND" H 10275 5800 60  0001 C CNN "Supplier P/N"
F 6 "http://www.digikey.com/product-detail/en/murata-electronics-north-america/GRM188R71E104KA01D/490-1524-1-ND/587865" H 10275 5800 60  0001 C CNN "Supplier URL"
F 7 "Murata Electronics North America" H 10275 5800 60  0001 C CNN "Manufacturer"
F 8 "GRM188R71E104KA01D" H 10275 5800 60  0001 C CNN "Manufacturer P/N"
F 9 "http://search.murata.co.jp/Ceramy/image/img/A01X/G101/ENG/GRM188R71E104KA01-01.pdf" H 10275 5800 60  0001 C CNN "Datasheet URL"
F 10 "0.10µF 25V Ceramic Capacitor X7R 0603 (1608 Metric) 0.063\" L x 0.031\" W (1.60mm x 0.80mm)" H 10275 5800 60  0001 C CNN "Description"
F 11 "0.10" H 10275 5800 60  0001 C CNN "Unit Cost"
	1    10275 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2975 7050 3325 7050
Wire Wire Line
	2975 7200 3325 7200
Wire Wire Line
	2975 7350 3325 7350
Wire Wire Line
	2975 7500 3325 7500
Wire Wire Line
	2975 7825 3325 7825
Text Label 3325 7050 2    60   ~ 0
PB0
Text Label 3325 7200 2    60   ~ 0
PB1
Text Label 3325 7350 2    60   ~ 0
PB2
Text Label 3325 7500 2    60   ~ 0
PB3
Text Label 3325 7825 2    60   ~ 0
PB5
Text Label 7550 2550 2    60   ~ 0
PB0
Text Label 7550 2650 2    60   ~ 0
PB1
Text Label 7550 2750 2    60   ~ 0
PB2
Text Label 7550 2850 2    60   ~ 0
PB3
Text Label 7550 2950 2    60   ~ 0
PB4
Text Label 7550 3050 2    60   ~ 0
PB5
Wire Wire Line
	2975 7675 3325 7675
Text Label 3325 7675 2    60   ~ 0
PB4
$EndSCHEMATC
