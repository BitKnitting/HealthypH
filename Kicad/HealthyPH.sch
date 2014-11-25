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
Sheet 1 7
Title ""
Date "25 nov 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 7250 2800 1950 600 
U 53DB8BC1
F0 "Wall Wart" 50
F1 "WallWart.sch" 50
F2 "V+_WallWart" O L 7250 3150 60 
$EndSheet
Text Notes 2900 4900 0    118  ~ 0
Arduino +5V
Text Notes 4300 750  0    118  ~ 0
9-12V Wall Wart
$Comp
L R R6
U 1 1 53E4B553
P 3400 1650
F 0 "R6" V 3480 1650 40  0000 C CNN
F 1 "499" V 3407 1651 40  0000 C CNN
F 2 "~" V 3330 1650 30  0000 C CNN
F 3 "~" H 3400 1650 30  0000 C CNN
	1    3400 1650
	0    -1   -1   0   
$EndComp
$Comp
L R R7
U 1 1 53E4B560
P 3400 2000
F 0 "R7" V 3480 2000 40  0000 C CNN
F 1 "499" V 3407 2001 40  0000 C CNN
F 2 "~" V 3330 2000 30  0000 C CNN
F 3 "~" H 3400 2000 30  0000 C CNN
	1    3400 2000
	0    -1   -1   0   
$EndComp
$Sheet
S 7250 1900 1900 600 
U 53C98328
F0 "Temperature" 50
F1 "Temperature.sch" 50
F2 "10K Therm" I R 9150 2150 60 
F3 "V+_WallWart" I L 7250 2350 60 
F4 "V+_WallWart_Out" O R 9150 2350 60 
F5 "Temp_Vin" O L 7250 2100 60 
$EndSheet
$Sheet
S 7300 3750 2200 1100
U 53C2998C
F0 "Pumps" 50
F1 "Pumps.sch" 50
F2 "DownPump" I L 7300 4600 60 
F3 "V+_ARD" I L 7300 3900 60 
F4 "GND_ARD" O L 7300 4100 60 
F5 "V+_DownPump" I R 9500 4000 60 
F6 "SW_DownPump" I R 9500 4150 60 
F7 "UpPump" I L 7300 4350 60 
F8 "SW_UpPump" I R 9500 4500 60 
F9 "V+_UpPump" I R 9500 4350 60 
$EndSheet
$Comp
L CONN_8 P1
U 1 1 53EA8DDA
P 11050 1450
F 0 "P1" V 11000 1450 60  0000 C CNN
F 1 "CONN_8" V 11100 1450 60  0000 C CNN
F 2 "" H 11050 1450 60  0000 C CNN
F 3 "" H 11050 1450 60  0000 C CNN
	1    11050 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 1400 6800 3150
Wire Wire Line
	6800 3150 7250 3150
Wire Wire Line
	6650 2950 6800 2950
Connection ~ 6800 2950
Wire Notes Line
	9950 550  9950 3600
Wire Notes Line
	9950 3600 4000 3600
Wire Notes Line
	4000 3600 4000 600 
Wire Notes Line
	4000 600  9950 600 
Wire Notes Line
	3000 600  3000 3700
Wire Notes Line
	3000 3700 9950 3700
Wire Notes Line
	9950 3700 9950 5000
Wire Notes Line
	9950 5000 600  5000
Wire Notes Line
	600  5000 600  600 
Wire Notes Line
	600  600  3000 600 
Wire Wire Line
	3650 1650 4700 1650
Wire Wire Line
	3650 2000 4700 2000
Wire Wire Line
	10000 2150 9150 2150
Wire Wire Line
	10300 1500 10300 4000
Wire Wire Line
	10300 1500 10700 1500
Wire Wire Line
	10700 1600 10450 1600
Wire Wire Line
	10450 1600 10450 4150
Wire Wire Line
	2700 3900 7300 3900
Wire Wire Line
	2700 4100 7300 4100
Wire Wire Line
	2700 4350 7300 4350
Wire Wire Line
	2700 4600 7300 4600
Wire Wire Line
	10300 4000 9500 4000
Wire Wire Line
	10450 4150 9500 4150
Wire Wire Line
	10700 1700 10600 1700
Wire Wire Line
	10600 1700 10600 4350
Wire Wire Line
	10600 4350 9500 4350
Wire Wire Line
	10700 1800 10700 4500
Wire Wire Line
	10700 4500 9500 4500
Wire Wire Line
	3150 1650 2700 1650
Wire Wire Line
	3150 2000 2700 2000
Wire Wire Line
	7250 1400 6800 1400
Wire Wire Line
	10100 2350 9150 2350
Wire Wire Line
	7250 2350 6800 2350
Connection ~ 6800 2350
Wire Wire Line
	9150 1200 10700 1200
Wire Wire Line
	9150 1000 10450 1000
Wire Wire Line
	10100 2350 10100 1400
Wire Wire Line
	10100 1400 10700 1400
Wire Wire Line
	10000 2150 10000 1300
Wire Wire Line
	10000 1300 10700 1300
Wire Wire Line
	10450 1000 10450 1100
Wire Wire Line
	10450 1100 10700 1100
$Sheet
S 800  900  1900 3900
U 53DCD805
F0 "Arduino" 50
F1 "Arduino.sch" 50
F2 "V+_ARD" O R 2700 3900 60 
F3 "GND_ARD" I R 2700 4100 60 
F4 "PumpUp" O R 2700 4350 60 
F5 "PumpDown" O R 2700 4600 60 
F6 "SDA" B R 2700 2000 60 
F7 "SCL" B R 2700 1650 60 
F8 "pH_ON" O R 2700 2700 60 
F9 "Temp_ON" O R 2700 2950 60 
$EndSheet
$Sheet
S 4700 900  1950 2200
U 53CA7F21
F0 "Digital Access" 50
F1 "DigitalAccess.sch" 50
F2 "V+_WallWart" I R 6650 2950 60 
F3 "SCL" B L 4700 1650 60 
F4 "SDA" B L 4700 2000 60 
F5 "pH_Vin" I R 6650 1100 60 
F6 "Temp_Vin" I R 6650 2100 60 
F7 "pH_ON" I L 4700 2700 60 
F8 "Temp_ON" I L 4700 2950 60 
$EndSheet
$Sheet
S 7250 800  1900 700 
U 53C9635B
F0 "pH" 50
F1 "pH.sch" 50
F2 "V+_WallWart" I L 7250 1400 60 
F3 "pH_Probe_V" I R 9150 1200 60 
F4 "pH_Probe_GND" I R 9150 1000 60 
F5 "pH_Vin" O L 7250 1100 60 
$EndSheet
Wire Wire Line
	7250 1100 6650 1100
Wire Wire Line
	7250 2100 6650 2100
Wire Wire Line
	2700 2700 4700 2700
Wire Wire Line
	4700 2950 2700 2950
$EndSCHEMATC
