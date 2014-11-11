//
//  MCP3901.h
//  HealthypHTestV1
//
//  Created by Margaret Johnson on 9/24/14.
//  Copyright (c) 2014 Margaret Johnson. All rights reserved.
//

#ifndef __HealthypHTestV1__MCP3901__
#define __HealthypHTestV1__MCP3901__
#include "Arduino.h"
#include "SPI.h"
//figure out if a bit is on.
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
typedef uint8_t byte;
class MCP3901
{public:
    MCP3901 (byte cs_n,byte reset_n,byte dr_n);
    int32_t read_value(byte channel_num);
    float read_volts(byte channel_num);
    void write_byte(byte addr,byte value);
    byte read_byte(byte addr);
    byte read_config(byte num);
    void write_config(byte num,byte value);
    void set_reset(bool high);
private:
    byte CS_N,RESET_N, DR_N;
    
};

#endif /* defined(__HealthypHTestV1__MCP3901__) */
