//
//  Common.h
//  HealthypHTestV1
//
//  Created by Margaret Johnson on 10/14/14.
//  Copyright (c) 2014 Margaret Johnson. All rights reserved.
//

#ifndef HealthypHTestV1_Common_h
#define HealthypHTestV1_Common_h
//#ifdef DEBUG
//#define DEBUG_PRINT(x)  Serial.print (x)
//#define DEBUG_PRINTHEX(x) Serial.print(x,HEX)
//#define DEBUG_PRINTF(x) Serial.print(F(x))
//#define DEBUG_PRINTLN(x) Serial.println(x)
//#define DEBUG_PRINTLNF(x) Serial.println(F(x))
//#else
//#define DEBUG_PRINT(x)
//#define DEBUG_PRINTF(x)
//#define DEBUG_PRINTLN(x)
//#define DEBUG_PRINTLNF(x)
//#define DEBUG_PRINTHEX(x)
//#endif
#define PRINTLNF(x) Serial.println(F(x));
#define PRINTF(x) Serial.print(F(x));
int freeRam () {
    extern int __heap_start, *__brkval;
    int v;
    return (int)&v - (__brkval ==0 ? (int) &__heap_start : (int) __brkval);
}
#endif
