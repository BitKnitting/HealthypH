//
//  MCP3901.cpp
//  HealthypHTestV1
//
//  Created by Margaret Johnson on 9/24/14.
//  Copyright (c) 2014 Margaret Johnson. All rights reserved.
//
#define ADC_WIDTH 2
#define CHAR_BIT 8
//used to set the last bit of the control byte - 1 = read, 0 = write
const char register_read = 1;
const char register_write = 0;
const float vRef = 2.37;  //VREF's typical value as stated in the MCP3901 data sheet.
#include "MCP3901.h"
//use the address of config1 to get to both config2 and config 1
const byte address_config1_control = (0x0A << 1); //0X0A = 0000 0000 0000 1010 0X14= 0000 0000 0001 0100

//the ADC CH0 and CH1 bytes begin at the MSB of CH0, then increment from there
const byte address_CH0_msb = 0x00;  //address of MSB of CH0
const byte address_CH1_msb = 0x03 << 1;


MCP3901::MCP3901(byte cs_n, byte reset_n, byte dr_n)
{
    Serial.println(F("****DEBUG: IN MCP3901 INIT"));
    CS_N = cs_n;
    RESET_N = reset_n;
    DR_N = dr_n;
    pinMode(CS_N, OUTPUT);
    pinMode(RESET_N, OUTPUT);
    pinMode(DR_N, INPUT);
    //reset registers to default
    //initialize the SPI bus
    SPI.setDataMode(SPI_MODE0);
    SPI.setClockDivider(SPI_CLOCK_DIV128); /* Slowest clock for testing */
    SPI.begin();
    //RESET_N - first set config to default thent high so that communication can happen with the ADC
    digitalWrite(RESET_N,LOW);
    digitalWrite(RESET_N,HIGH);    
}
/******************************************************************************
 * Read the 24 bit ADC value from either CH0 or CH1
 * TEST: 16 bit read.
 *******************************************************************************/
int32_t MCP3901::read_value(byte channel_num)
{
    byte readaddress = address_CH0_msb;
    //read in the 24 bit ADC value.  NOTE: This function assumes the channel width = 24 bits
    switch(channel_num){
        case 0:
            break;
        case 1:
            //CH1 starts at address 3.  This needs to be bit shifted one since the address bits
            //are bits 1 - 5.  3 << 1 = 6.  Bit 0 = read or write.  Can ignore bits 6 & 7.
            readaddress = address_CH1_msb;
            break;
        default:
            return -1.0;
            break;
    }
    readaddress = readaddress | register_read;
    Serial.print("Readaddress: ");
    Serial.println(readaddress,HEX);
    long adc_value=0;  //need 3 bytes for the ADC data
   // byte adc_value_bytes[4]={0};
    byte adc_value_bytes[2] = {0};
    //we're using the SPI bus so set CS pin to LOW
    digitalWrite(CS_N,LOW);
    //send in the control byte
    SPI.transfer(readaddress);
    //start with the 2nd byte since this is a 24 bit number and bit twiddling is needed if the number is negative.
    //MSB first (adc_value_bytes[1] = MSB, adc_value_bytes[3] = LSB)
//    for (byte i=1;i<4;i++){
//        adc_value_bytes[i] = SPI.transfer(0xFF);
//        Serial.println(adc_value_bytes[i],HEX);
//    }
    int16_t iADC_value=0;
    for (byte i = 0;i<2;i++)
    {
        byte ret = SPI.transfer(0xFF);
        Serial.println(ret,HEX);
        iADC_value += ret;
        iADC_value <<= (ADC_WIDTH-1-i)*CHAR_BIT;
    }
//    for (byte i = 0;i<2;i++)
//    {
//        adc_value_bytes[i] = SPI.transfer(0xFF);
//        Serial.println(adc_value_bytes[i],HEX);
//    }
    //we're done using the SPI bus so set CS pin to HIGH
    digitalWrite(CS_N,HIGH);
    //numbers are stored in two's complement.  This would be super easy if what was returned was a 32 bit number.  But alas, 24 bits are returned.
    //I check the 24th bit to see if it is a 1.  If it is, this is a negative number.  If a negative number, set the MSB byte to 0xFFFF.
    //i then set the first bit of the 2nd to MSB to 0 since this is the two's complement bit for the 24 bit value.
    //i found this post on two's complement helpful: http://www.cs.cornell.edu/~tomf/notes/cps104/twoscomp.html#intro
//    if (CHECK_BIT(adc_value_bytes[1],7)) {
//        Serial.println("negative number");
//        adc_value_bytes[0]  = 0xFFFF;
//        adc_value_bytes[1] &= ~0x8000;
//    }
    //adc_value =   (long)adc_value_bytes[0] << 24 | (long)adc_value_bytes[1]<<16 | (long)adc_value_bytes[2] << 8  | (long)adc_value_bytes[3];
//   uint16_t tadc_value = adc_value_bytes[0] << 8 | adc_value_bytes[1];
    Serial.print("ADC Value: 0x");
    Serial.print(iADC_value,HEX);
    Serial.print(" | ");
    Serial.println(iADC_value);
    return(iADC_value);
}

/******************************************************************************
 * channel_num is either 0 for CH0 or 1 for CH1
 * -1.0 is returned if there is an error (say channel_num != 0 or 1)
 *******************************************************************************/
float MCP3901::read_volts(byte channel_num)

{
    int32_t adc_value =   read_value(channel_num);
    float volts = (float)adc_value/(8388608*3)*vRef;  //see sectin 5.6 Equation 5-3 of the MCP3901 datasheet
    return volts;
}
/******************************************************************************
 * Helper function to return the CONFIG bytes
 *******************************************************************************/
byte MCP3901::read_config(byte num)
{
    //num must be either 1 or 2.  1 for Config1 and 2 for Config2
    //start by assuming the read request is for config 1.
    byte address_config_control_action = address_config1_control | register_read;
    byte config_value;
    switch (num){
        case 1:
            config_value = read_byte(address_config_control_action);
            break;
        case 2:
            //config 2's address is 0X0B - set the lsbit of the address (which starts at bit 2) to 1 to go from config 1 to config 2
             address_config_control_action = address_config1_control | register_read | 0x02;
            config_value = read_byte(address_config_control_action);
            break;
        default:
            Serial.println(F("You entered: "));
            Serial.print(num);
            Serial.println(F("this routine expected either a 1 for config 1 or 2 for config 2"));
            return 0xFF;
    }
    return config_value;
}
/******************************************************************************
 * Helper function to write the bits in value into a CONFIG (num = 1 or 2) register
 *******************************************************************************/
void MCP3901::write_config(byte num,byte value)
{
    //num must be either 1 or 2.  1 for Config1 and 2 for Config2
    //start by assuming the read request is for config 1.
    byte address_config_control_action = address_config1_control | register_write;
    byte config_value;
    switch (num){
        case 1:
            write_byte(address_config_control_action,value);
            break;
        case 2:
            //config 2's address is 0X0B - set the lsbit of the address (which starts at bit 2) to 1 to go from config 1 to config 2
            address_config_control_action = address_config1_control | register_write | 0x02;
            write_byte(address_config_control_action,value);
            break;
        default:
            Serial.println(F("You entered: "));
            Serial.print(num);
            Serial.println(F("this routine expected either a 1 for config 1 or 2 for config 2"));
    }
}

/******************************************************************************
 * read the value byte at the register given by addr
 *******************************************************************************/
byte MCP3901::read_byte(byte addr)
{
    //using the SPI bus so set CS pin to LOW
    digitalWrite(CS_N,LOW);
    //tell the MCP3901 which register to read from
    SPI.transfer(addr);
    //Push dummy 1's and get byte return
    byte register_value = SPI.transfer(0XFF);
    //done with the SPI bus - set CS pin to HIGH
    digitalWrite(CS_N,HIGH);
    return register_value;
}

/******************************************************************************
 * write the value byte at the register given by addr
 *******************************************************************************/
void MCP3901::write_byte(byte addr,byte value)
{
    //using the SPI bus so set CS pin to LOW
    digitalWrite(CS_N,LOW);
    //tell the MCP3901 which register to write to
    SPI.transfer(addr);
    //write the value
    SPI.transfer(value);
    //done with the SPI bus - set CS pin to HIGH
    digitalWrite(CS_N,HIGH);
}
/******************************************************************************
 * This is for a debugging check to see if the RESET line in hw can be seen as set.  The RESET line might show LOW for example, if the wrong RESET pin is initialized in software.  Just a simple check when debugging the SPI.
 *******************************************************************************/
void MCP3901::set_reset(bool high)
{
    if (high) digitalWrite(RESET_N,HIGH);
    else digitalWrite(RESET_N,LOW);
}
