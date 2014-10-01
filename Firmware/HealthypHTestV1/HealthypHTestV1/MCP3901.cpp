//
//  MCP3901.cpp
//  HealthypHTestV1
//
//  Created by Margaret Johnson on 9/24/14.
//  Copyright (c) 2014 Margaret Johnson. All rights reserved.
//

//used to set the last bit of the control byte - 1 = read, 0 = write
const char register_read = 1;
const char register_write = 0;
const float vRef = 2.37;  //VREF's typical value as stated in the MCP3901 data sheet.
#include "MCP3901.h"
//use the address of config1 to get to both config2 and config 1
const byte address_config1_control = (0x0A << 1); //0X0A = 0000 0000 0000 1010 0X14= 0000 0000 0001 0100

//the ADC CH0 and CH1 bytes begin at the MSB of CH0, then increment from there
const byte address_CH0_msb = 0x00;  //address of MSB of CH0


MCP3901::MCP3901(byte cs_n, byte reset_n, byte dr_n)
{
    Serial.println("****DEBUG: IN MCP3901 INIT");
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
 * channel_num is either 0 for CH0 or 1 for CH1
 * -1.0 is returned if there is an error (say channel_num != 1 or 2)
 *******************************************************************************/
float MCP3901::read_volts(byte channel_num)

{byte readaddress = address_CH0_msb;
    //read in the 24 bit ADC value.  NOTE: This function assumes the channel width = 24 bits
    switch(channel_num){
        case 1:
            break;
        case 2:
            readaddress = address_CH0_msb + 3;
            break;
        default:
            return -1.0;
            break;
    }
    readaddress = readaddress | register_read;
    uint32_t adc_value=0;  //need 3 bytes for the ADC data
    byte adc_value_bytes[3]={0};
    //we're using the SPI bus so set CS pin to LOW
    digitalWrite(CS_N,LOW);
    SPI.transfer(readaddress);
    for (byte i=0;i<3;i++){
        adc_value_bytes[i] = SPI.transfer(0xFF);
    }
    //we're done using the SPI bus so set CS pin to HIGH
    digitalWrite(CS_N,HIGH);
    adc_value =   (unsigned long)adc_value_bytes[0]<<16 | (unsigned long)adc_value_bytes[1] << 8  | (unsigned long)adc_value_bytes[2];
    Serial.print("--> ADC Value: ");
    Serial.println(adc_value);
    float volts = (float)adc_value/(8388608*3)*vRef;  //see sectin 5.6 Equation 5-3 of the MCP3901 datasheet
    return volts;
//    //change the ADC width from 16 bits (default) to 24 bits in order to read voltages > 0.79V
//    //this can be done by setting bits in the CONFIG1 register
//    const unsigned int config1At24Bit = 0X1C;
//    const unsigned int address_register_config1 = (0x0A << 1);
//    //get the current value in config 1
////    byte register_value = MCP3901_read_config(CS_N, address_register_config1);
//    //set the width bits to 1 so the ADC is using 24 bits
////    byte register_value =  0b00011100;
////    //send the command to the MCP3901 to write to CONFIG1
////    byte SPIControlByte = address_register_config1 | register_write;
////    //we're using the SPI bus so set CS pin to LOW
////    digitalWrite(CS_N,LOW);
////    SPI.transfer(SPIControlByte);
////    SPI.transfer(register_value);
////    digitalWrite(CS_N,HIGH);
////    //we're using the SPI bus so set CS pin to LOW
////    digitalWrite(CS_N,LOW);
////    SPI.transfer(address_register_config1 | register_write);
////    SPI.transfer(config1At24Bit);
////    SPI.transfer(address_register_config1|register_read);
////    byte config1 = SPI.transfer(0xFF);
////    Serial.print("  CONFIG 1: 0X");
////    Serial.println(config1,HEX);
//    //we're using the SPI bus so set CS pin to LOW
//    digitalWrite(CS_N,LOW);
//    //ask the MCP3901 to read the data in the CH0 or CH1 register depending on the channel_num
//    //TEST: JUST SHOOT FOR CH 0
//    byte readaddress = address_CH0_msb | register_read;
//SPI.transfer(readaddress);
////    Serial.println(adc_value_bytes[0],HEX);
//    adc_value_bytes[0] = SPI.transfer(0x0);
//        Serial.println(adc_value_bytes[0],HEX);
//    adc_value_bytes[1] = SPI.transfer(0x0);
//           Serial.println(adc_value_bytes[1],HEX);
//    adc_value_bytes[2] = SPI.transfer(0x0);
//    Serial.println(adc_value_bytes[2],HEX);
////    Serial.print("Byte ");
////    Serial.print(0);
////    Serial.print(":");
////    Serial.println(adc_value_bytes[0],HEX);
////    for (byte i=1;i<channel_width;i++){
////        adc_value_bytes[i] = SPI.transfer(0xFF);
////        Serial.print("Byte ");
////        Serial.print(i);
////        Serial.print(":");
////        Serial.println(adc_value_bytes[i],HEX);
////    }
//    //we're done using the SPI bus so set CS pin to HIGH
//    digitalWrite(CS_N,HIGH);
//    adc_value =   (unsigned long)adc_value_bytes[0]<<16 | (unsigned long)adc_value_bytes[1] << 8  | (unsigned long)adc_value_bytes[2];
//
//    
//    Serial.print(adc_value,HEX);
//    Serial.print(",");
//    Serial.print(adc_value,DEC);
//
//    float volts = (float)adc_value/(8388608*3)*vRef;  //see sectin 5.6 Equation 5-3 of the MCP3901 datasheet
//    Serial.print(",");
//    Serial.println(volts);
//    Serial.println(adc_value_bytes[0],HEX);
//    Serial.println(adc_value_bytes[1],HEX);
//    Serial.println(adc_value_bytes[2],HEX);
//    return adc_value;
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
            Serial.println("You entered: ");
            Serial.print(num);
            Serial.println("this routine expected either a 1 for config 1 or 2 for config 2");
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
            Serial.println("You entered: ");
            Serial.print(num);
            Serial.println("this routine expected either a 1 for config 1 or 2 for config 2");
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
