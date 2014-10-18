//
//  pH.h
//  HealthypHTestV1
//
//  Created by Margaret Johnson on 10/13/14.
//  Copyright (c) 2014 Margaret Johnson. All rights reserved.
//

#ifndef __HealthypHTestV1__pH__
#define __HealthypHTestV1__pH__
#include "Arduino.h"
typedef uint8_t byte;
//Copied from Sparky's Widgets minipH.ino:https://github.com/SparkysWidgets/MinipHBFW/blob/master/MinipH.ino
//Keep info on the slope used to calculate pH readings in EEPROM so that the probe does not need to be calibrated every time the Arduino's memory is refreshed.
struct parameters_T
{
    unsigned int WriteCheck;
    float pH7MV, pH4MV;
    float pHSlopeMV;
};
#define Write_Check              0x1234                 //EEPROM trigger check
#define ADC_reading_period       10000                   //the number of milliseconds to take ADC readings
class pH
{public:
    pH ();
    void calibrate(byte pHToCalibrate);
    float getpH(void);
    void printParams(void);
private:
    void reset_params(void);
    void calibratepH4(void);
    void calibratepH7(void);
    void calcpHSlope(void);
    float getpHmV(void);
};
#endif /* defined(__HealthypHTestV1__pH__) */