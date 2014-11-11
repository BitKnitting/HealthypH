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
Date "10 nov 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 6350 2000 2    60   Output ~ 0
SCLK
Wire Wire Line
	6350 2000 5750 2000
Text HLabel 6350 2200 2    60   Input ~ 0
MISO
Text HLabel 6350 2400 2    60   Output ~ 0
MOSI
Text HLabel 6350 2600 2    60   Output ~ 0
~CS
Wire Wire Line
	5750 2200 6350 2200
Wire Wire Line
	5750 2400 6350 2400
Text HLabel 2500 3550 0    60   Output ~ 0
PumpDown
Text HLabel 6350 3000 2    60   Output ~ 0
~RESET
Text HLabel 2500 2450 0    60   Output ~ 0
V+_ARD
Wire Wire Line
	3550 2450 2500 2450
Text HLabel 2500 2650 0    60   Input ~ 0
GND_ARD
Wire Wire Line
	2500 2650 3550 2650
Wire Wire Line
	3550 3550 2500 3550
Text HLabel 2500 3750 0    60   Output ~ 0
PumpUp
Wire Wire Line
	2500 3750 3550 3750
$Comp
L R R14
U 1 1 540F4E5D
P 2850 4350
F 0 "R14" V 2930 4350 40  0000 C CNN
F 1 "499" V 2857 4351 40  0000 C CNN
F 2 "~" V 2780 4350 30  0000 C CNN
F 3 "~" H 2850 4350 30  0000 C CNN
	1    2850 4350
	0    -1   -1   0   
$EndComp
$Comp
L R R13
U 1 1 540F4E9E
P 2850 4750
F 0 "R13" V 2930 4750 40  0000 C CNN
F 1 "499" V 2857 4751 40  0000 C CNN
F 2 "~" V 2780 4750 30  0000 C CNN
F 3 "~" H 2850 4750 30  0000 C CNN
	1    2850 4750
	0    -1   -1   0   
$EndComp
$Comp
L R R12
U 1 1 540F4F03
P 2850 3950
F 0 "R12" V 2930 3950 40  0000 C CNN
F 1 "499" V 2857 3951 40  0000 C CNN
F 2 "~" V 2780 3950 30  0000 C CNN
F 3 "~" H 2850 3950 30  0000 C CNN
	1    2850 3950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5750 2600 6350 2600
Wire Wire Line
	3550 3950 3100 3950
Wire Wire Line
	1900 3950 2600 3950
Wire Wire Line
	1900 4350 2600 4350
Wire Wire Line
	1900 4750 2600 4750
Text HLabel 950  4350 0    60   Output ~ 0
V+_ARD
$Comp
L LB_RGBLED D4
U 1 1 544128B0
P 1700 3950
F 0 "D4" H 1700 4050 50  0000 C CNN
F 1 "LB_RGBLED" H 1700 3850 50  0000 C CNN
F 2 "~" H 1700 3950 60  0000 C CNN
F 3 "~" H 1700 3950 60  0000 C CNN
	1    1700 3950
	1    0    0    -1  
$EndComp
$Comp
L LB_RGBLED D4
U 2 1 544128BD
P 1700 4350
F 0 "D4" H 1700 4450 50  0000 C CNN
F 1 "LB_RGBLED" H 1700 4250 50  0000 C CNN
F 2 "~" H 1700 4350 60  0000 C CNN
F 3 "~" H 1700 4350 60  0000 C CNN
	2    1700 4350
	1    0    0    -1  
$EndComp
$Comp
L LB_RGBLED D4
U 3 1 544128C3
P 1700 4750
F 0 "D4" H 1700 4850 50  0000 C CNN
F 1 "LB_RGBLED" H 1700 4650 50  0000 C CNN
F 2 "~" H 1700 4750 60  0000 C CNN
F 3 "~" H 1700 4750 60  0000 C CNN
	3    1700 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  4350 1500 4350
Wire Wire Line
	1050 3950 1050 4750
Wire Wire Line
	1050 3950 1500 3950
Connection ~ 1050 4350
Wire Wire Line
	1050 4750 1500 4750
Wire Wire Line
	3550 2850 3300 2850
Wire Wire Line
	3300 2850 3300 2650
Connection ~ 3300 2650
Wire Wire Line
	3400 4750 3100 4750
Wire Wire Line
	3100 4350 3150 4350
Wire Wire Line
	3150 4350 3150 4150
Wire Wire Line
	3150 4150 3550 4150
Wire Wire Line
	3400 4750 3400 4350
Wire Wire Line
	3400 4350 3550 4350
Wire Wire Line
	5750 3000 6350 3000
Text HLabel 6350 2800 2    60   Input ~ 0
~DR
Wire Wire Line
	5750 2800 6350 2800
$Comp
L ARDUINOPINS ARD?
U 1 1 545EEF21
P 4650 3150
F 0 "ARD?" H 4000 4750 60  0000 C CNN
F 1 "ARDUINOPINS" H 4150 4950 60  0000 C CNN
F 2 "~" H 5200 2200 60  0000 C CNN
F 3 "~" H 5200 2200 60  0000 C CNN
	1    4650 3150
	1    0    0    -1  
$EndComp
$EndSCHEMATC
