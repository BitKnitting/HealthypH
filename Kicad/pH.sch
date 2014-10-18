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
Date "18 oct 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 1400 1200 0    60   Input ~ 0
V+_WallWart
Text HLabel 1350 3200 0    60   Input ~ 0
ph_ADC_IN+
Wire Wire Line
	3900 3500 3900 3750
$Comp
L R R4
U 1 1 53D7D158
P 7450 3850
F 0 "R4" V 7530 3850 40  0000 C CNN
F 1 "1K" V 7457 3851 40  0000 C CNN
F 2 "~" V 7380 3850 30  0000 C CNN
F 3 "~" H 7450 3850 30  0000 C CNN
	1    7450 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 3200 3450 3200
Text HLabel 7950 1900 0    60   Input ~ 0
pH_ADC_IN-
$Comp
L AGND #PWR07
U 1 1 53DCC7DA
P 3900 3750
F 0 "#PWR07" H 3900 3750 40  0001 C CNN
F 1 "AGND" H 3900 3680 50  0000 C CNN
F 2 "" H 3900 3750 60  0000 C CNN
F 3 "" H 3900 3750 60  0000 C CNN
	1    3900 3750
	1    0    0    -1  
$EndComp
$Comp
L MCP6241 U1
U 1 1 53ECAB65
P 3800 3200
F 0 "U1" H 3800 3350 60  0000 L CNN
F 1 "MCP6241" H 3800 3050 60  0000 L CNN
F 2 "~" H 3800 3200 60  0000 C CNN
F 3 "~" H 3800 3200 60  0000 C CNN
	1    3800 3200
	-1   0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 53F37946
P 7450 2950
F 0 "R3" V 7530 2950 40  0000 C CNN
F 1 "10K" V 7457 2951 40  0000 C CNN
F 2 "~" V 7380 2950 30  0000 C CNN
F 3 "~" H 7450 2950 30  0000 C CNN
	1    7450 2950
	1    0    0    -1  
$EndComp
$Comp
L CONN_1 TP1
U 1 1 53F5D6D1
P 2350 2900
F 0 "TP1" H 2430 2900 40  0000 L CNN
F 1 "CONN_1" H 2350 2955 30  0001 C CNN
F 2 "" H 2350 2900 60  0000 C CNN
F 3 "" H 2350 2900 60  0000 C CNN
	1    2350 2900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2350 3050 2350 3200
Connection ~ 2350 3200
Wire Wire Line
	7450 3200 7450 3600
Text HLabel 5700 3100 2    60   Input ~ 0
pH_Probe_V
Wire Wire Line
	4150 3100 5700 3100
Wire Wire Line
	2950 3200 2950 4100
Wire Wire Line
	2950 4100 4750 4100
Wire Wire Line
	4750 4100 4750 3300
Wire Wire Line
	4750 3300 4150 3300
Connection ~ 2950 3200
$Comp
L AGND #PWR08
U 1 1 540C92AB
P 7450 4400
F 0 "#PWR08" H 7450 4400 40  0001 C CNN
F 1 "AGND" H 7450 4330 50  0000 C CNN
F 2 "" H 7450 4400 60  0000 C CNN
F 3 "" H 7450 4400 60  0000 C CNN
	1    7450 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 4400 7450 4100
Text HLabel 8600 3400 2    60   Input ~ 0
pH_Probe_GND
Wire Wire Line
	8050 1900 8050 3400
Wire Wire Line
	8050 1900 7950 1900
Wire Wire Line
	7450 3400 8600 3400
Connection ~ 7450 3400
Connection ~ 8050 3400
$Comp
L C C3
U 1 1 5441038F
P 2000 1650
F 0 "C3" H 2000 1750 40  0000 L CNN
F 1 ".1" H 2006 1565 40  0000 L CNN
F 2 "~" H 2038 1500 30  0000 C CNN
F 3 "~" H 2000 1650 60  0000 C CNN
	1    2000 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 2450 7450 2450
Text Notes 1850 1050 0    60   ~ 0
Added .1uF
Wire Wire Line
	1400 1200 2750 1200
Wire Wire Line
	2000 1450 2000 1200
Connection ~ 2000 1200
$Comp
L AGND #PWR09
U 1 1 5441062F
P 2000 2050
F 0 "#PWR09" H 2000 2050 40  0001 C CNN
F 1 "AGND" H 2000 1980 50  0000 C CNN
F 2 "" H 2000 2050 60  0000 C CNN
F 3 "" H 2000 2050 60  0000 C CNN
	1    2000 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 1850 2000 2050
Wire Wire Line
	3900 2900 3900 2400
Wire Wire Line
	7450 2450 7450 2700
Text GLabel 2750 1200 2    60   Output ~ 0
V+_Clean
Text GLabel 3900 2400 2    60   Output ~ 0
V+_Clean
Text GLabel 6100 2300 2    60   Output ~ 0
V+_Clean
Wire Wire Line
	5950 2450 5950 2300
Wire Wire Line
	5950 2300 6100 2300
$EndSCHEMATC
