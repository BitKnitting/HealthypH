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
Sheet 5 7
Title ""
Date "12 aug 2014"
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
Wire Wire Line
	5750 2600 6350 2600
Text HLabel 2500 3550 0    60   Output ~ 0
PumpDown
Text HLabel 6400 3800 2    60   Output ~ 0
~RESET
Wire Wire Line
	5750 3800 6400 3800
Text HLabel 6450 4200 2    60   Input ~ 0
~DR
Wire Wire Line
	5750 4200 6450 4200
Text HLabel 2500 2450 0    60   Output ~ 0
V+_ARD
Wire Wire Line
	3550 2450 2500 2450
$Comp
L ARDUINOPINS ARD1
U 1 1 53E0F48C
P 4650 3150
F 0 "ARD1" H 4000 4750 60  0000 C CNN
F 1 "ARDUINOPINS" H 4150 4950 60  0000 C CNN
F 2 "~" H 5200 2200 60  0000 C CNN
F 3 "~" H 5200 2200 60  0000 C CNN
	1    4650 3150
	1    0    0    -1  
$EndComp
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
$EndSCHEMATC
