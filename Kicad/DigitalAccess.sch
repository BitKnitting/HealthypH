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
Sheet 7 7
Title ""
Date "11 nov 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	5650 4600 5650 4950
$Comp
L AGND #PWR?
U 1 1 5461F6EC
P 5650 4950
F 0 "#PWR?" H 5650 4950 40  0001 C CNN
F 1 "AGND" H 5650 4880 50  0000 C CNN
F 2 "" H 5650 4950 60  0000 C CNN
F 3 "" H 5650 4950 60  0000 C CNN
	1    5650 4950
	1    0    0    -1  
$EndComp
$Comp
L VREF U?
U 1 1 5461FB75
P 5700 2150
F 0 "U?" H 6200 2000 60  0000 C CNN
F 1 "VREF" H 6250 2300 60  0000 C CNN
F 2 "" H 5450 2250 60  0000 C CNN
F 3 "" H 5450 2250 60  0000 C CNN
	1    5700 2150
	1    0    0    -1  
$EndComp
Text HLabel 4650 1400 0    60   Input ~ 0
V+_WallWart
Wire Wire Line
	5700 1400 5700 1600
Wire Wire Line
	5700 3200 5700 2800
Text HLabel 4150 3700 0    60   BiDi ~ 0
SCL
Wire Wire Line
	4150 3700 4800 3700
Text HLabel 4150 4000 0    60   BiDi ~ 0
SDA
Wire Wire Line
	4800 4000 4150 4000
Text HLabel 7600 3850 2    60   Input ~ 0
ADC_IN
$Comp
L MCP3221 U?
U 1 1 5461FD90
P 5750 3850
F 0 "U?" H 6150 3300 60  0000 C CNN
F 1 "MCP3221" H 6250 4350 60  0000 C CNN
F 2 "~" H 5750 3850 60  0000 C CNN
F 3 "~" H 5750 3850 60  0000 C CNN
	1    5750 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 3850 7600 3850
$Comp
L C C?
U 1 1 5461FDB2
P 5050 1700
F 0 "C?" H 5050 1800 40  0000 L CNN
F 1 ".1u" H 5056 1615 40  0000 L CNN
F 2 "~" H 5088 1550 30  0000 C CNN
F 3 "~" H 5050 1700 60  0000 C CNN
	1    5050 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 1400 5050 1400
Wire Wire Line
	5050 1400 5050 1500
Wire Wire Line
	4650 1400 5100 1400
Connection ~ 5100 1400
$Comp
L AGND #PWR?
U 1 1 5461FDE8
P 5050 2050
F 0 "#PWR?" H 5050 2050 40  0001 C CNN
F 1 "AGND" H 5050 1980 50  0000 C CNN
F 2 "" H 5050 2050 60  0000 C CNN
F 3 "" H 5050 2050 60  0000 C CNN
	1    5050 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 1900 5050 2050
$Comp
L C C?
U 1 1 5461FE10
P 4850 3100
F 0 "C?" H 4850 3200 40  0000 L CNN
F 1 ".1u" H 4856 3015 40  0000 L CNN
F 2 "~" H 4888 2950 30  0000 C CNN
F 3 "~" H 4850 3100 60  0000 C CNN
	1    4850 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 2900 5700 2900
Connection ~ 5700 2900
$Comp
L AGND #PWR?
U 1 1 5461FE35
P 4850 3450
F 0 "#PWR?" H 4850 3450 40  0001 C CNN
F 1 "AGND" H 4850 3380 50  0000 C CNN
F 2 "" H 4850 3450 60  0000 C CNN
F 3 "" H 4850 3450 60  0000 C CNN
	1    4850 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 3300 4850 3450
$Comp
L R R?
U 1 1 5461FE56
P 4400 3200
F 0 "R?" V 4480 3200 40  0000 C CNN
F 1 "R" V 4407 3201 40  0000 C CNN
F 2 "~" V 4330 3200 30  0000 C CNN
F 3 "~" H 4400 3200 30  0000 C CNN
	1    4400 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 2950 4400 2900
Connection ~ 4850 2900
Wire Wire Line
	4400 3450 4400 3700
Connection ~ 4400 3700
$EndSCHEMATC
