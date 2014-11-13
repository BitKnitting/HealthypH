EESchema Schematic File Version 2
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
LIBS:special
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
LIBS:BenchBuddy
LIBS:LettuceBuddy
LIBS:HealthyPH-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 7
Title ""
Date "12 nov 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L AGND #PWR04
U 1 1 53CE414D
P 2650 3650
F 0 "#PWR04" H 2650 3650 40  0001 C CNN
F 1 "AGND" H 2650 3580 50  0000 C CNN
F 2 "" H 2650 3650 60  0000 C CNN
F 3 "" H 2650 3650 60  0000 C CNN
	1    2650 3650
	1    0    0    -1  
$EndComp
$Comp
L R R15
U 1 1 540DEB6D
P 3700 3300
F 0 "R15" V 3780 3300 40  0000 C CNN
F 1 "1K  .1%" V 3707 3301 40  0000 C CNN
F 2 "~" V 3630 3300 30  0000 C CNN
F 3 "~" H 3700 3300 30  0000 C CNN
	1    3700 3300
	0    -1   -1   0   
$EndComp
Text HLabel 5300 3300 2    60   Input ~ 0
10K Therm
Text HLabel 1400 2700 0    60   Output ~ 0
Temp_Vin
Wire Wire Line
	2650 3300 2650 3650
Wire Wire Line
	3950 3300 5300 3300
Wire Wire Line
	4550 2700 4550 3300
Connection ~ 4550 3300
Wire Notes Line
	6000 3100 6000 3500
Wire Notes Line
	6000 3500 5350 3500
Wire Notes Line
	5350 3500 5350 3100
Wire Notes Line
	5350 3100 6000 3100
Text HLabel 1250 1500 0    60   Input ~ 0
V+_WallWart
Text HLabel 8450 1500 2    60   Output ~ 0
V+_WallWart_Out
Wire Wire Line
	1250 1500 8450 1500
$Comp
L C C3
U 1 1 544542CF
P 1750 1950
F 0 "C3" H 1750 2050 40  0000 L CNN
F 1 ".1" H 1756 1865 40  0000 L CNN
F 2 "~" H 1788 1800 30  0000 C CNN
F 3 "~" H 1750 1950 60  0000 C CNN
	1    1750 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 1750 1750 1500
Connection ~ 1750 1500
$Comp
L AGND #PWR05
U 1 1 544542EA
P 1750 2350
F 0 "#PWR05" H 1750 2350 40  0001 C CNN
F 1 "AGND" H 1750 2280 50  0000 C CNN
F 2 "" H 1750 2350 60  0000 C CNN
F 3 "" H 1750 2350 60  0000 C CNN
	1    1750 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 2150 1750 2350
Wire Notes Line
	6000 3300 6500 3300
Wire Notes Line
	6500 3300 6500 1500
Text Notes 6700 3000 0    60   ~ 0
Thermistor hangs off two of the 8 TB connectors.
Wire Wire Line
	3450 3300 2650 3300
Wire Wire Line
	2100 2700 4550 2700
Wire Wire Line
	2100 2700 1400 2700
$EndSCHEMATC
