//
//  LEDDiags.h
//  HealthypHTestV1
//
//  Created by Margaret Johnson on 9/23/14.
//  Copyright (c) 2014 Margaret Johnson. All rights reserved.
//

#ifndef __HealthypHTestV1__LEDDiags__
#define __HealthypHTestV1__LEDDiags__
#include "Arduino.h"
typedef uint8_t byte;
class LEDDiagTests
{
public:
    LEDDiagTests (byte red_pin,byte blue_pin,byte green_pin);
    void turnLEDon(byte red,byte green,byte blue);
    void turnLEDoff();
private:
    byte Red_pin,Green_pin,Blue_pin;

};



#endif /* defined(__HealthypHTestV1__LEDDiags__) */
