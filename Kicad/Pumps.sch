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
Date "21 aug 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L TIP120 Q1
U 1 1 53CBD30E
P 3800 2650
F 0 "Q1" H 3750 2500 40  0000 R CNN
F 1 "TIP122" H 3800 2800 40  0000 R CNN
F 2 "TO220" H 3680 2755 29  0001 C CNN
F 3 "~" H 3800 2650 60  0000 C CNN
	1    3800 2650
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 53CBD483
P 3100 2650
F 0 "R1" V 3180 2650 40  0000 C CNN
F 1 "2.2K" V 3107 2651 40  0000 C CNN
F 2 "~" V 3030 2650 30  0000 C CNN
F 3 "~" H 3100 2650 30  0000 C CNN
	1    3100 2650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3350 2650 3600 2650
Wire Wire Line
	2000 2650 2850 2650
$Comp
L DIODE D1
U 1 1 53CBD4B8
P 4700 1500
F 0 "D1" H 4700 1600 40  0000 C CNN
F 1 "4004" H 4700 1400 40  0000 C CNN
F 2 "~" H 4700 1500 60  0000 C CNN
F 3 "~" H 4700 1500 60  0000 C CNN
	1    4700 1500
	0    1    1    0   
$EndComp
Wire Wire Line
	4700 1150 4700 1300
Text HLabel 2000 2650 0    59   Input ~ 0
DownPump
$Comp
L GND #PWR013
U 1 1 53DC3138
P 3900 3250
F 0 "#PWR013" H 3900 3250 30  0001 C CNN
F 1 "GND" H 3900 3180 30  0001 C CNN
F 2 "" H 3900 3250 60  0000 C CNN
F 3 "" H 3900 3250 60  0000 C CNN
	1    3900 3250
	1    0    0    -1  
$EndComp
Text HLabel 1750 1150 0    60   Input ~ 0
V+_ARD
Wire Wire Line
	3900 2350 6000 2350
Wire Wire Line
	3900 2350 3900 2450
Wire Wire Line
	4700 1700 4700 2150
Wire Wire Line
	4700 2150 6000 2150
$Comp
L C C14
U 1 1 53E26DDA
P 2800 1500
F 0 "C14" H 2800 1600 40  0000 L CNN
F 1 "1u" H 2806 1415 40  0000 L CNN
F 2 "~" H 2838 1350 30  0000 C CNN
F 3 "~" H 2800 1500 60  0000 C CNN
	1    2800 1500
	-1   0    0    1   
$EndComp
Wire Wire Line
	1750 1150 4700 1150
Wire Wire Line
	3900 2850 3900 3250
Text HLabel 2000 3150 0    59   Output ~ 0
GND_ARD
Wire Wire Line
	2000 3150 3900 3150
Connection ~ 3900 3150
Wire Wire Line
	2800 1300 2800 1150
Connection ~ 2800 1150
$Comp
L GND #PWR014
U 1 1 53E3E3F6
P 2800 1850
F 0 "#PWR014" H 2800 1850 30  0001 C CNN
F 1 "GND" H 2800 1780 30  0001 C CNN
F 2 "" H 2800 1850 60  0000 C CNN
F 3 "" H 2800 1850 60  0000 C CNN
	1    2800 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 1700 2800 1850
Text HLabel 6000 2150 2    60   Input ~ 0
V+_DownPump
Text HLabel 6000 2350 2    60   Input ~ 0
SW_DownPump
$Comp
L TIP120 Q2
U 1 1 53EA6E0F
P 3800 4150
F 0 "Q2" H 3750 4000 40  0000 R CNN
F 1 "TIP122" H 3800 4300 40  0000 R CNN
F 2 "TO220" H 3680 4255 29  0001 C CNN
F 3 "~" H 3800 4150 60  0000 C CNN
	1    3800 4150
	1    0    0    -1  
$EndComp
$Comp
L R R11
U 1 1 53EA6E15
P 3100 4150
F 0 "R11" V 3180 4150 40  0000 C CNN
F 1 "2.2K" V 3107 4151 40  0000 C CNN
F 2 "~" V 3030 4150 30  0000 C CNN
F 3 "~" H 3100 4150 30  0000 C CNN
	1    3100 4150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3350 4150 3600 4150
Wire Wire Line
	2000 4150 2850 4150
Text HLabel 2000 4150 0    59   Input ~ 0
UpPump
$Comp
L GND #PWR015
U 1 1 53EA6E1E
P 3900 4750
F 0 "#PWR015" H 3900 4750 30  0001 C CNN
F 1 "GND" H 3900 4680 30  0001 C CNN
F 2 "" H 3900 4750 60  0000 C CNN
F 3 "" H 3900 4750 60  0000 C CNN
	1    3900 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 3850 6000 3850
Wire Wire Line
	3900 3850 3900 3950
Wire Wire Line
	3900 4350 3900 4750
Text HLabel 6000 3850 2    60   Input ~ 0
SW_UpPump
Wire Wire Line
	5300 2150 5300 3500
Wire Wire Line
	5300 3500 6000 3500
Connection ~ 5300 2150
Text HLabel 6000 3500 2    60   Input ~ 0
V+_UpPump
Wire Wire Line
	2550 3150 2550 4600
Wire Wire Line
	2550 4600 3900 4600
Connection ~ 3900 4600
Connection ~ 2550 3150
$EndSCHEMATC
