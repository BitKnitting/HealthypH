//
//  Thermistor.h
//  HealthypHTestV1
//
//  Created by Margaret Johnson on 10/2/14.
//  Copyright (c) 2014 Margaret Johnson. All rights reserved.
//
#ifndef __HealthypHTestV1__Thermistor__
#define __HealthypHTestV1__Thermistor__
#include "Arduino.h"
#include "SPI.h"
typedef uint8_t byte;
class Thermistor
{public:
    float read_thermistor_R(void);
    float get_temperature(char scale);
};


#endif /* defined(__HealthypHTestV1__Thermistor__) */
