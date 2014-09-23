//
//  SPIDiagTests.cpp
//  HealthypHTestV1
//  For now, read the config data for either the Healthy pH or EC Shields.
//
//  Created by Margaret Johnson on 9/21/14.
//  Copyright (c) 2014 Margaret Johnson. All rights reserved.
//

#include "SPIDiagTests.h"
/******************************************************************************
 * Set constants that identify the config registers - refer to the MCP3901 datasheet for more info.
 *******************************************************************************/
//Get comfy with the MCP3901 datasheet - http://ww1.microchip.com/downloads/en/DeviceDoc/22192a.pdf
//see Figure 6-1 which shows the bit layout for the control byte
//Although there are "cool" device address bits, the Healthy Shields will both use the SPI bus.  So this address will always be 00.
//see Table 7-1 (Register Map) of the MCP3901 data sheet -
//the address of CONFIG1 = 0x0A  The address of CONFIG2 = 0x0B
//to make the control byte then the CONFIG1 (or 2) address needs to be bit shifted to the left by 1 so the address does not collide with the R/W bit.
//note the R/W bit (the LSb) = 1 if read and 0 if write.
//
const unsigned int address_register_config1 = (0x0A << 1);  //0X0A = 0000 0000 0000 1010 0X14= 0000 0000 0001 0100
const unsigned int address_register_config2 = (0x0B << 1);  //0X16 = 0000 0000 0001 0110
const char register_read = 1; //read config 1's register = 0x15 (| 1 to 0X14), config 2 = 0x17
const char register_write = 0;
/******************************************************************************
 * read and then write to the two config registers.  Then set back to default.  The bytes returned should be what is expected as defined in the MCP3901 datasheet.
 *******************************************************************************/
char SPIDiagTests::testConfig(byte CS_N,byte RESET_N,byte DR_N)
{
    MCP3901_setup(CS_N, RESET_N, DR_N);
    read_and_print_config(CS_N);
    //Write to and print out the changed values for configs 1 and 2
    //Reset configs to default
    //Print out the default values
}
/******************************************************************************
 * Send a control command to the MCP3901 asking to read the content of a config register then print out what is returned.
 *******************************************************************************/
void SPIDiagTests::read_and_print_config(char CS_N)
{
Serial.print("Address of config 1: ");
print_bits(address_register_config1,2);
char register_value = MCP3901_read_config(CS_N,address_register_config1);
Serial.print("Bits in config 1 register: ");
print_bits(register_value,1);
Serial.print("Address of config 2: ");
print_bits(address_register_config2,2);
register_value = MCP3901_read_config(CS_N,address_register_config2);
Serial.print("Bits in config 2 register: ");
print_bits(register_value,1);
}
/******************************************************************************
 * Set up the SPI pins on the Arduino that vary per MCP3901 sharing the SPI - there are two: 1 for the Healthy pH Shield and 1 for the Healthy EC Shield.
 *******************************************************************************/
void SPIDiagTests::MCP3901_setup(byte CS_N, byte RESET_N, byte DR_N)
{
    Serial.println("**** MCP3901_setup");
    Serial.print("SPI Pins--->  CS: ");
    Serial.print(CS_N);
    Serial.print(" | RESET: ");
    Serial.print(RESET_N);
    Serial.print(" | DR: ");
    Serial.println(DR_N);
    pinMode(CS_N, OUTPUT);
    pinMode(RESET_N, OUTPUT);
//    pinMode(DR_N, INPUT);
    digitalWrite(RESET_N, HIGH);
    //initialize the SPI bus
    SPI.setDataMode(SPI_MODE0);
    SPI.setClockDivider(SPI_CLOCK_DIV128); /* Slowest clock for testing */
    SPI.begin();
}
/******************************************************************************
 * read one of the (two) configuration registers and return the value.
 *******************************************************************************/
char SPIDiagTests:: MCP3901_read_config(char CS_N,unsigned int addr) {
    Serial.println("**** MCP3901_config_read");
    //we're using the SPI bus so set CS pin to LOW
    digitalWrite(CS_N,LOW);
    //send the control byte to the MCP3901 with the config address and a read request
    byte SPIReadControlByte = addr | register_read;
    Serial.print("Control byte: ");
    print_bits(SPIReadControlByte,1);
    char register_value = SPI.transfer(SPIReadControlByte);
    //get back the register value
    //char register_value = SPI.transfer(0xFF);
    //we're done using the SPI bus so set CS pin to HIGH
    digitalWrite(CS_N,HIGH);
    return register_value;
}
/******************************************************************************
 * Helper function to print out bits of one or more bytes in binary and hex format...including leading 0's
 * The second variable determines how many bytes to print.
 *******************************************************************************/
void SPIDiagTests::print_bits(unsigned int bytes,char numBytes)
{
    for (int i = 0; i < 8*numBytes; i++)
    {
        if (bytes < pow(2, i))
            Serial.print(B0);
    }
    Serial.print(bytes,BIN);Serial.print("| 0X");Serial.println(bytes,HEX);
}