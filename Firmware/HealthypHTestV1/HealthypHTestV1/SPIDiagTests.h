//
//  SPIDiagTests.h
//  HealthypHTestV1
//
//  Created by Margaret Johnson on 9/21/14.
//  Copyright (c) 2014 Margaret Johnson. All rights reserved.
//

#ifndef __HealthypHTestV1__SPIDiagTests__
#define __HealthypHTestV1__SPIDiagTests__
#include "Arduino.h"
#include "SPI.h"
typedef uint8_t byte;
class SPIDiagTests
{
public:
    char testConfig(byte CS_N,byte RESET_N,byte DR_N);
private:
    void MCP3901_setup(byte CS_N,byte RESET_N,byte DR_N);
    char MCP3901_read_config(char CS_N,unsigned int addr);
    void print_bits(unsigned int bytes,char numBytes);
    void read_and_print_config(char CS_N);
};

#endif /* defined(__HealthypHTestV1__SPIDiagTests__) */
