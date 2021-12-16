EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATmega:ATmega328P-AU U1
U 1 1 61BA16AD
P 3275 3450
F 0 "U1" H 3725 2000 50  0000 C CNN
F 1 "ATmega328P-AU" H 3150 3475 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 3275 3450 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 3275 3450 50  0001 C CNN
	1    3275 3450
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:KCSA02-105 U2
U 1 1 61BA24EE
P 5675 3250
F 0 "U2" H 5675 3917 50  0000 C CNN
F 1 "KCSA02-105" H 5675 3826 50  0000 C CNN
F 2 "Display_7Segment:KCSC02-105" H 5675 2650 50  0001 C CNN
F 3 "http://www.kingbright.com/attachments/file/psearch/000/00/00/KCSA02-105(Ver.10A).pdf" H 5175 3725 50  0001 L CNN
	1    5675 3250
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 61BA4C94
P 4800 4100
F 0 "SW1" H 4800 4275 50  0000 C CNN
F 1 "SW_Push" H 4800 4050 50  0000 C CNN
F 2 "MoireLabs:SW_PUSH_6mm_H9.5mm_center" H 4800 4300 50  0001 C CNN
F 3 "~" H 4800 4300 50  0001 C CNN
	1    4800 4100
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 61BA5CA2
P 4800 4500
F 0 "SW2" H 4800 4675 50  0000 C CNN
F 1 "SW_Push" H 4800 4450 50  0000 C CNN
F 2 "MoireLabs:SW_PUSH_6mm_H9.5mm_center" H 4800 4700 50  0001 C CNN
F 3 "~" H 4800 4700 50  0001 C CNN
	1    4800 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3875 4150 4375 4150
Wire Wire Line
	4375 4150 4375 4100
Wire Wire Line
	4375 4100 4600 4100
Wire Wire Line
	3875 4250 4400 4250
Wire Wire Line
	4400 4250 4400 4500
Wire Wire Line
	4400 4500 4600 4500
$Comp
L power:GND #PWR0101
U 1 1 61BA84E1
P 5200 4600
F 0 "#PWR0101" H 5200 4350 50  0001 C CNN
F 1 "GND" H 5205 4427 50  0000 C CNN
F 2 "" H 5200 4600 50  0001 C CNN
F 3 "" H 5200 4600 50  0001 C CNN
	1    5200 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 4100 5200 4100
Wire Wire Line
	5200 4100 5200 4500
Wire Wire Line
	5000 4500 5200 4500
Connection ~ 5200 4500
Wire Wire Line
	5200 4500 5200 4600
Wire Wire Line
	3875 3150 4625 3150
Wire Wire Line
	4625 3150 4625 2950
Wire Wire Line
	4625 2950 5375 2950
Wire Wire Line
	3875 3250 4725 3250
Wire Wire Line
	4725 3250 4725 3050
Wire Wire Line
	4725 3050 5375 3050
Wire Wire Line
	3875 3350 4850 3350
Wire Wire Line
	4850 3350 4850 3150
Wire Wire Line
	4850 3150 5375 3150
Wire Wire Line
	3875 3450 4925 3450
Wire Wire Line
	4925 3450 4925 3250
Wire Wire Line
	4925 3250 5375 3250
Wire Wire Line
	3875 3550 5050 3550
Wire Wire Line
	5050 3550 5050 3350
Wire Wire Line
	5050 3350 5375 3350
Wire Wire Line
	3875 3650 5150 3650
Wire Wire Line
	5150 3650 5150 3450
Wire Wire Line
	5150 3450 5375 3450
Wire Wire Line
	3875 4450 4175 4450
Wire Wire Line
	4175 4450 4175 3725
Wire Wire Line
	4175 3725 5225 3725
Wire Wire Line
	5225 3725 5225 3550
Wire Wire Line
	5225 3550 5375 3550
Wire Wire Line
	3875 4550 4275 4550
Wire Wire Line
	4275 4550 4275 3800
Wire Wire Line
	4275 3800 5325 3800
Wire Wire Line
	5325 3800 5325 3650
Wire Wire Line
	5325 3650 5375 3650
$Comp
L power:VCC #PWR0102
U 1 1 61BAE1EC
P 6300 3425
F 0 "#PWR0102" H 6300 3275 50  0001 C CNN
F 1 "VCC" H 6315 3598 50  0000 C CNN
F 2 "" H 6300 3425 50  0001 C CNN
F 3 "" H 6300 3425 50  0001 C CNN
	1    6300 3425
	1    0    0    -1  
$EndComp
Wire Wire Line
	5975 3550 6300 3550
Wire Wire Line
	6300 3550 6300 3425
Wire Wire Line
	5975 3650 6300 3650
Wire Wire Line
	6300 3650 6300 3550
Connection ~ 6300 3550
$Comp
L power:VCC #PWR0103
U 1 1 61BB04C3
P 3325 1750
F 0 "#PWR0103" H 3325 1600 50  0001 C CNN
F 1 "VCC" H 3340 1923 50  0000 C CNN
F 2 "" H 3325 1750 50  0001 C CNN
F 3 "" H 3325 1750 50  0001 C CNN
	1    3325 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3275 1950 3275 1850
Wire Wire Line
	3275 1850 3325 1850
Wire Wire Line
	3325 1850 3325 1750
Wire Wire Line
	3325 1850 3375 1850
Wire Wire Line
	3375 1850 3375 1950
Connection ~ 3325 1850
$Comp
L power:GND #PWR0104
U 1 1 61BB24E0
P 3275 5200
F 0 "#PWR0104" H 3275 4950 50  0001 C CNN
F 1 "GND" H 3280 5027 50  0000 C CNN
F 2 "" H 3275 5200 50  0001 C CNN
F 3 "" H 3275 5200 50  0001 C CNN
	1    3275 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3275 4950 3275 5200
$Comp
L Connector_Generic:Conn_02x04_Odd_Even J1
U 1 1 61BB4B38
P 8275 3600
F 0 "J1" H 8325 3917 50  0000 C CNN
F 1 "ICP" H 8325 3826 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x04_P2.54mm_Vertical" H 8275 3600 50  0001 C CNN
F 3 "~" H 8275 3600 50  0001 C CNN
	1    8275 3600
	1    0    0    -1  
$EndComp
Text Label 8075 3500 2    50   ~ 0
MISO
Text Label 8575 3600 0    50   ~ 0
MOSI
Text Label 8075 3600 2    50   ~ 0
SCK
Text Label 7625 3700 2    50   ~ 0
RST
Wire Wire Line
	7625 3700 7725 3700
Text Label 8075 3800 2    50   ~ 0
RX
Text Label 8575 3800 0    50   ~ 0
TX
$Comp
L power:VCC #PWR0105
U 1 1 61BAAD83
P 8675 3075
F 0 "#PWR0105" H 8675 2925 50  0001 C CNN
F 1 "VCC" H 8690 3248 50  0000 C CNN
F 2 "" H 8675 3075 50  0001 C CNN
F 3 "" H 8675 3075 50  0001 C CNN
	1    8675 3075
	1    0    0    -1  
$EndComp
Wire Wire Line
	8575 3500 8675 3500
$Comp
L power:GND #PWR0106
U 1 1 61BAC708
P 8775 3850
F 0 "#PWR0106" H 8775 3600 50  0001 C CNN
F 1 "GND" H 8780 3677 50  0000 C CNN
F 2 "" H 8775 3850 50  0001 C CNN
F 3 "" H 8775 3850 50  0001 C CNN
	1    8775 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8575 3700 8775 3700
Wire Wire Line
	8775 3700 8775 3850
$Comp
L Device:R R1
U 1 1 61BAE1A1
P 7725 3200
F 0 "R1" H 7795 3246 50  0000 L CNN
F 1 "10k" H 7795 3155 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7655 3200 50  0001 C CNN
F 3 "~" H 7725 3200 50  0001 C CNN
	1    7725 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7725 3350 7725 3700
Connection ~ 7725 3700
Wire Wire Line
	7725 3700 8075 3700
Wire Wire Line
	8675 3075 8675 3175
Wire Wire Line
	7725 3050 7725 2950
Wire Wire Line
	7725 2950 8350 2950
Wire Wire Line
	8350 2950 8350 3175
Wire Wire Line
	8350 3175 8675 3175
Connection ~ 8675 3175
Wire Wire Line
	8675 3175 8675 3500
Text Label 3875 3750 0    50   ~ 0
RST
$Comp
L MoireLabs:ABS07-120-32.768KHZ-T Y1
U 1 1 61BC8828
P 4550 2250
F 0 "Y1" V 4325 2225 50  0000 L CNN
F 1 "ABS07-120-32.768KHZ-T" V 4250 1750 50  0000 L CNN
F 2 "Crystal:Crystal_SMD_3215-2Pin_3.2x1.5mm" H 4550 2250 50  0001 C CNN
F 3 "~" H 4550 2250 50  0001 C CNN
F 4 "2467864" H 4550 2250 50  0001 C CNN "FARNELL"
	1    4550 2250
	0    1    1    0   
$EndComp
Wire Wire Line
	3875 2950 4300 2950
Wire Wire Line
	4300 2950 4300 2400
Wire Wire Line
	4300 2400 4550 2400
Wire Wire Line
	3875 2850 4175 2850
Wire Wire Line
	4175 2850 4175 2100
Wire Wire Line
	4175 2100 4550 2100
$Comp
L Device:C C1
U 1 1 61BDA6CC
P 5325 2100
F 0 "C1" V 5073 2100 50  0000 C CNN
F 1 "6p" V 5164 2100 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5363 1950 50  0001 C CNN
F 3 "~" H 5325 2100 50  0001 C CNN
	1    5325 2100
	0    1    1    0   
$EndComp
$Comp
L Device:C C2
U 1 1 61BDB50F
P 5325 2425
F 0 "C2" V 5550 2425 50  0000 C CNN
F 1 "6p" V 5475 2425 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5363 2275 50  0001 C CNN
F 3 "~" H 5325 2425 50  0001 C CNN
	1    5325 2425
	0    1    1    0   
$EndComp
Wire Wire Line
	4550 2100 5175 2100
Connection ~ 4550 2100
Wire Wire Line
	4550 2400 5000 2400
Wire Wire Line
	5000 2400 5000 2425
Wire Wire Line
	5000 2425 5175 2425
Connection ~ 4550 2400
$Comp
L power:GND #PWR0107
U 1 1 61BDEE1A
P 5850 2250
F 0 "#PWR0107" H 5850 2000 50  0001 C CNN
F 1 "GND" H 5855 2077 50  0000 C CNN
F 2 "" H 5850 2250 50  0001 C CNN
F 3 "" H 5850 2250 50  0001 C CNN
	1    5850 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5475 2425 5625 2425
Wire Wire Line
	5625 2425 5625 2175
Wire Wire Line
	5625 2175 5850 2175
Wire Wire Line
	5850 2175 5850 2250
Wire Wire Line
	5475 2100 5625 2100
Wire Wire Line
	5625 2100 5625 2175
Connection ~ 5625 2175
$EndSCHEMATC
