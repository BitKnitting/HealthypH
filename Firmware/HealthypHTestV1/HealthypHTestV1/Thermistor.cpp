//
//  Thermistor.cpp
//  HealthypHTestV1
//
//  Created by Margaret Johnson on 10/2/14.
//  Copyright (c) 2014 Margaret Johnson. All rights reserved.
//

#include "Thermistor.h"
/******************************************************************************
 * The thermistor readings come from CH1 of the MCP3901
 *******************************************************************************/
#include "MCP3901.h"
MCP3901 therm_mcp3901(10,4,2);
//this is the value of the known resistance
#define KNOWN_RESISTANCE 10000.0
/******************************************************************************
 * return the resistance of the Thermistor
 *******************************************************************************/
float Thermistor::read_thermistor_R(void)
{
    float volts = therm_mcp3901.read_volts(1);
    Serial.print("--> volts: ");
    Serial.print(volts);
    Serial.print(" | Thermistor Resistance: ");
    Serial.println(KNOWN_RESISTANCE/volts);
    return (KNOWN_RESISTANCE/volts);
}
/******************************************************************************
 * Return a temperature reading in F if scale = 'F' or C if scale = 'C'
 *******************************************************************************/
float Thermistor::get_temperature(char scale)
{
    
}