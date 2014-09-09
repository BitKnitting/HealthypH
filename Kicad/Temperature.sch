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
Sheet 6 7
Title ""
Date "9 sep 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 5400 2000 0    60   Input ~ 0
V+_WallWart
$Comp
L AGND #PWR012
U 1 1 53CE414D
P 5400 4300
F 0 "#PWR012" H 5400 4300 40  0001 C CNN
F 1 "AGND" H 5400 4230 50  0000 C CNN
F 2 "" H 5400 4300 60  0000 C CNN
F 3 "" H 5400 4300 60  0000 C CNN
	1    5400 4300
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 540DEB6D
P 5400 3550
F 0 "R?" V 5480 3550 40  0000 C CNN
F 1 "10K" V 5407 3551 40  0000 C CNN
F 2 "~" V 5330 3550 30  0000 C CNN
F 3 "~" H 5400 3550 30  0000 C CNN
	1    5400 3550
	1    0    0    -1  
$EndComp
Text HLabel 6400 2700 2    60   Input ~ 0
TempR
Text HLabel 3500 3000 0    60   Output ~ 0
TempV
Text HLabel 6450 4150 2    60   Input ~ 0
AGND
$Comp
L CONN_1 TP?
U 1 1 540E05A9
P 4200 2800
F 0 "TP?" H 4280 2800 40  0000 L CNN
F 1 "CONN_1" H 4200 2855 30  0001 C CNN
F 2 "" H 4200 2800 60  0000 C CNN
F 3 "" H 4200 2800 60  0000 C CNN
	1    4200 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 3800 5400 4300
Wire Wire Line
	5400 2000 5400 3300
Wire Wire Line
	3500 3000 5400 3000
Wire Wire Line
	5400 4150 6450 4150
Connection ~ 5400 4150
Wire Wire Line
	4050 3000 4050 2800
Connection ~ 5400 3000
Connection ~ 4050 3000
Wire Wire Line
	6400 2700 5400 2700
Connection ~ 5400 2700
Text Label 6250 2550 0    60   ~ 0
Thermistor is in water
$EndSCHEMATC
