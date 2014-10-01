/// 
/// @mainpage	HealthypHTestV1 
///
/// @details	Diagnostic Test for HealthypH Shield
/// @n 		
/// @n 
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
/// Thanks to https://github.com/jonblack/arduino-menusystem for the menuing system.
/// 
/// @author		Margaret Johnson
/// @author		Margaret Johnson
/// @date		9/21/14 3:47 AM
/// @version	<#version#>
/// 
/// @copyright	(c) Margaret Johnson, 2014
/// @copyright	License
///
/// @see		ReadMe.txt for references
///
///
/// @file		HealthypHTestV1.ino
/// @brief		Main sketch
///
/// @details	<#details#>
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
/// 
/// @author		Margaret Johnson
/// @author		Margaret Johnson
/// @date		9/21/14 3:47 AM
/// @version	1.0
/// 
/// @copyright	(c) Margaret Johnson, 2014
/// @copyright	License
///
/// @see		ReadMe.txt for references
/// @n
///


// Core library for code-sense
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(DIGISPARK) // Digispark specific
#include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad MSP430 G2 and F5529, Stellaris and Tiva, Experimeter Board FR5739 specific
#include "Energia.h"
#elif defined(MICRODUINO) // Microduino specific
#include "Arduino.h"
#elif defined(TEENSYDUINO) // Teensy specific
#include "Arduino.h"
#elif defined(ARDUINO) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#else // error
#error Platform not defined
#endif

// Include application, user and local libraries
#include "MenuSystem.h"
#include "SPIDiagTests.h"
#include "LEDDiags.h"
#include "MCP3901.h"

// Prototypes
//Help
static void showHelp();
static void showString(PGM_P s);
//Menu system
void serialHandler();
void displayMenu();


// Define variables and constants
/******************************************************************************
 * Using menuing system from https://github.com/jonblack/arduino-menusystem
 *******************************************************************************/
MenuSystem ms;
Menu mm("Healthy pH Shield Diagnostic Tests ");
Menu menuLED("LED");
MenuItem pH("pH");
MenuItem pumps("pumps");
Menu menuSPI("SPI");
MenuItem temperature("temperature");

MenuItem menuSPI_mi1("read CONFIG bytes");
MenuItem menuSPI_mi2("set CONFIG 1 to 24 bits and OSR=256");
MenuItem menuSPI_mi3("read ADC");

MenuItem menuLED_mi1("Turn LED on");
MenuItem menuLED_mi2("Turn LED off");
/******************************************************************************
 * All SPI tests are in the SPIDiagTests class
 *******************************************************************************/
SPIDiagTests SPITests;
/******************************************************************************
 * LED Diag tests are in LEDDiags.cpp
 * see the Arduino schematic in the Healthy pH Shield schematic for pin assignment
 *******************************************************************************/
const byte red_pin = A4;
const byte green_pin = A3;
const byte blue_pin = A2;

LEDDiagTests LEDTests(red_pin,blue_pin,green_pin);
MCP3901 adc_mcp3901(10,4,2);
// Menu callback functions
/******************************************************************************
 * Type in values for R G B on Serial Port
 *******************************************************************************/
void on_turn_LED_on(MenuItem* p_menu_item)
{
    int red,green,blue;
    Serial.println("\n****> Turn on LED Selected (Common Anode LED)");
    Serial.println("ENTER RRR,GGG,BBB for the RED, GREEN, BLUE values of the LED (e.g. red is 0,255,255):");
    //wait for input
    while (Serial.available () == 0) {;}
    // used (copy/pasted) reading a CSV from this link: http://arduino.cc/en/Tutorial/ReadASCIIString
    // look for the next valid integer in the incoming serial stream:
    red = Serial.parseInt();
    // do it again:
    green = Serial.parseInt();
    // do it again:
    blue = Serial.parseInt();
    LEDTests.turnLEDon(red,green,blue);
}
/******************************************************************************
 * if the LED light in on, turn it off
 *******************************************************************************/
void on_turn_LED_off(MenuItem* p_menu_item)
{
    Serial.println("\n****> Turn off LED Selected");
    LEDTests.turnLEDoff();
}

void on_pH_selected(MenuItem* p_menu_item)
{
    Serial.println("\n****> pH Selected");
}

void on_pumps_selected(MenuItem* p_menu_item)
{
    Serial.println("\n****> pumps Selected");
    const byte pump_down = 5;
    pinMode(pump_down,OUTPUT);
    analogWrite(pump_down,255);
    delay(3000);
    analogWrite(pump_down,0);
}

void on_temperature_selected(MenuItem* p_menu_item)
{
    Serial.println("\n****> temperature Selected");
}
/******************************************************************************
 * The Healthy pH schematic shows the pH circuit uses CS = 10 for SPI.  Reset and DR are discussed in the MCP3901 data sheet.
 * The SPI test reads/writes to the config registers as shown in the MCP3901 datasheet.
 *******************************************************************************/
void on_SPI_readConfigs_selected(MenuItem* p_menu_item)
{
    Serial.println("\n*********************************");
    byte config = adc_mcp3901.read_config(1);
    Serial.print("---> Config 1: 0X");
    Serial.println(config,HEX);
    config = adc_mcp3901.read_config(2);
    Serial.print("---> Config 2: 0X");
    Serial.println(config,HEX);
//    byte CS_N = 10;
//    byte RESET_N = 4;
//    byte DR_N = 2;
//    SPITests.testConfig(CS_N,RESET_N,DR_N);
}
/******************************************************************************
 * Change config 1 from default to sampling at 24 bit width and OSR = 256
 *******************************************************************************/
void on_SPI_set24bits_selected(MenuItem* p_menu_item)
{
    adc_mcp3901.write_config(1,0x3C);
    //verify
    byte config = adc_mcp3901.read_config(1);
    Serial.print("---> Config 1 should be 0X3C..here is the value in memory: 0X");
    Serial.println(config,HEX);
}
/******************************************************************************
 * The Healthy EC schematic shows the EC circuit uses CS = 9 for SPI
 *******************************************************************************/
void on_SPI_readADC_selected(MenuItem* p_menu_item)
{
    Serial.println("***********************************");
    float volts = adc_mcp3901.read_volts(1);
    Serial.print("Volt reading: ");
    Serial.println(volts);
//    //start with the default OSR is 64, 16 bit width
//    adc_mcp3901.read_channel(0);
//    //set OSR to 256, 16 bit width
////    Serial.print("---> OSR = 256 -->");
////    byte address_register_config1 = (0x0A << 1);
////    byte config1Value = B00110000;
////    adc_mcp3901.write_byte(address_register_config1,config1Value);
////    adc_mcp3901.read_channel(0);
////    //set OSR to 128
////    Serial.print("---> OSR = 128-->");
////    config1Value = B00100000;
////    adc_mcp3901.write_byte(address_register_config1,config1Value);
////    adc_mcp3901.read_channel(0);
////    //set OSR to 32
////    Serial.print("---> OSR = 32-->");
////    config1Value = B00000000;
////    adc_mcp3901.write_byte(address_register_config1,config1Value);
////    adc_mcp3901.read_channel(0);
////    Serial.println("Press any key to START reading the ADC volt values for the pH");
////    Serial.println("The ADC volt values will continue to be displayed until another character is typed");
////    //wait for input
////    while (Serial.available () == 0) {;}
////    Serial.read();
////    while (Serial.available() == 0) {
////        adc_mcp3901.read_channel(0);
////    }

}
// Add setup code 
void setup() 
{
    Serial.begin(9600);
    showHelp();
    //set up the menu
    mm.add_menu(&menuSPI);
    menuSPI.add_item(&menuSPI_mi1, &on_SPI_readConfigs_selected);
    menuSPI.add_item(&menuSPI_mi2, &on_SPI_set24bits_selected);
    menuSPI.add_item(&menuSPI_mi3, &on_SPI_readADC_selected);
    mm.add_menu(&menuLED);
    menuLED.add_item(&menuLED_mi1, &on_turn_LED_on);
    menuLED.add_item(&menuLED_mi2, &on_turn_LED_off);
    mm.add_item(&pH, &on_pH_selected);
    mm.add_item(&pumps, &on_pumps_selected);
    mm.add_item(&temperature, &on_temperature_selected);

    ms.set_root_menu(&mm);
    displayMenu();
    
}

// Add loop code 
void loop() 
{
    // Handle serial commands
    serialHandler();
}
/******************************************************************************
 * Check to see if a character was typed on the keyboard.  If it was, figure out what command to execute on.
 *******************************************************************************/
void serialHandler() {
    char inChar;
    if((inChar = Serial.read())>0) {
        switch (inChar) {
            case 'u': // Previus item
                ms.prev();
                displayMenu();
                break;
            case 'n': // Next item
                ms.next();
                displayMenu();
                break;
            case 'b': // Back pressed
                ms.back();
                displayMenu();
                break;
            case 'd': // Select pressed
                ms.select();
                displayMenu();
                break;
            case '?':
            case 'h': // Display help
                showHelp();
                break;
            default:
                break;
        }
    }
}
/******************************************************************************
 * From the example sketches at https://github.com/jonblack/arduino-menusystem
 *******************************************************************************/
void displayMenu() {
    Serial.println("");
    // Display the menu
    Menu const* cp_menu = ms.get_current_menu();
    
    Serial.print("Current menu name: ");
    Serial.println(cp_menu->get_name());
    
    MenuComponent const* cp_menu_sel = cp_menu->get_selected();
    for (int i = 0; i < cp_menu->get_num_menu_components(); ++i)
    {
        MenuComponent const* cp_m_comp = cp_menu->get_menu_component(i);
        Serial.print(cp_m_comp->get_name());
        
        if (cp_menu_sel == cp_m_comp)
            Serial.print("<<< ");
        
        Serial.println("");
    }
}
/*-----------------------------------------------------------
 Method for doing help this way from https://github.com/jcw/jeelib/blob/master/examples/RF12/RF12demo/RF12demo.ino
 ----------------------------------------------------------*/
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

const char helpText[] PROGMEM =
"\n"
"Available commands:" "\n"
"  ?     - shows available comands" "\n"
"  d     - selected \"selected\" item" "\n"
"  u     - go to previous item" "\n"
"  n     - go to next item" "\n"
"  b     - go back" "\n"
;
/*-----------------------------------------------------------
 show command line menu
 -----------------------------------------------------------*/
static void showHelp () {
    showString(helpText);
}
static void showString (PGM_P s) {
    for (;;) {
        char c = pgm_read_byte(s++);
        if (c == 0)
            break;
        if (c == '\n')
            Serial.print('\r');
        Serial.print(c);
    }
}

