//
//  pH.cpp
//  HealthypHTestV1
//
//  A lot of code borrowed from Sparky's Widgets MinipH.ino - https://github.com/SparkysWidgets/MinipHBFW/blob/master/MinipH.ino
//  Created by Margaret Johnson on 10/13/14.
//  Copyright (c) 2014 Margaret Johnson. All rights reserved.
//

#include "pH.h"
//We'll want to save calibration and configration information in EEPROM
#include <avr/eeprom.h>
#include "MCP3901.h"
#include "Statistic.h"
MCP3901 adc_pH(10,4,2);
parameters_T params;
Statistic stats;
/******************************************************************************
 * Initialize
 *******************************************************************************/
pH::pH()
{
    Serial.println(F("****DEBUG: IN pH INIT"));
    eeprom_read_block(&params, (void *)0, sizeof(params));
    Serial.print(F("--> Sanity check on params.  Here is the value for pHStep: "));
    Serial.println(params.pHSlopeMV);
    //if its a first time setup or our magic number in eeprom is wrong reset to default
    if (params.WriteCheck != Write_Check){
        reset_params();
    }
}
/******************************************************************************
 * return the pH value
 *******************************************************************************/
float pH::getpH()
{
    Serial.println(F("****DEBUG: IN getpH"));
    float pH_mV = getpHmV();
    Serial.print(F("--->AVERAGE pH mV: "));
    Serial.println(pH_mV);
    //adjust for slope difference from ideal (remembering pH voltage measurements use mV).
    return(7. - pH_mV*1000./params.pHSlopeMV);
}
/******************************************************************************
 * Figure out the calibrated value for the slope at either a pH 4 or 7 (determined by pHToCalibrate).
 * Several readings are taken to smooth out the noise.
 * once an average reading is made, store it in EEPROM
 *******************************************************************************/
void pH::calibrate(byte pHToCalibrate) {
    Serial.println(F("****DEBUG: IN calibrate"));
    if (pHToCalibrate == 4)calibratepH4();
    if( pHToCalibrate == 7 ) calibratepH7();
    uint32_t last_pH_slope = params.pHSlopeMV;
    params.pHSlopeMV  = .7 * params.pHSlopeMV + .3*last_pH_slope;
    printParams();
    //write the new pH voltage step unit to EEPROM so that it is stored in 'permanent' memory
    eeprom_write_block(&params, (void *)0, sizeof(params)); //write these settings back to eeprom
}
/******************************************************************************
 * Resetting pH slope variables happens if this is the first time and nothing is in EEPROM, or the Write_Check somehow got corrupted.
 *******************************************************************************/
void pH::reset_params(void)
{
    params.WriteCheck = Write_Check;
    params.pH7MV = 0.; //ideal pH 7 volt reading is 0V
    params.pH4MV = 189.; //ideal pH 4 volt reading is 0.189V
    params.pHSlopeMV = 59.16;//ideal probe slope
    eeprom_write_block(&params, (void *)0, sizeof(params)); //write these settings back to eeprom
}
/******************************************************************************
 * The pH probe is in the pH 4 calibration solution.  The slope used to calculate the pH will be adjusted from ideal based on results.
 * the biggest change in slope is typically due to the condition of the pH probe.
 *******************************************************************************/
void pH::calibratepH4()
{
    params.pH4MV = getpHmV();
    Serial.println("---> in Calibrate pH4.  pH 4 in mV: ");
    Serial.println(params.pH4MV);
    calcpHSlope();
    //write these settings back to eeprom
    eeprom_write_block(&params, (void *)0, sizeof(params));
}
/******************************************************************************
 * Same as when the pH probe is in pH 4, only this time it's in pH 7 calibration solution
 *******************************************************************************/
void pH::calibratepH7()
{
    params.pH7MV = getpHmV();
    Serial.println("---> in Calibrate ph7.  pH 7 in mV: ");
    Serial.println(params.pH7MV);
    calcpHSlope();
    //write these settings back to eeprom
    eeprom_write_block(&params, (void *)0, sizeof(params));
}
float pH::getpHmV(void)
{
    stats.clear();
    unsigned long currentMillis = millis();
    unsigned long lastpHCalibrationMillis = millis();
    float pH_mV;
    while (currentMillis - lastpHCalibrationMillis < ADC_reading_period)
    {
        //get a pH reading (assumes pH probe is in a calibration solution)
        pH_mV = adc_pH.read_volts(0)*1000.;
//        Serial.print(F("--->pH mV: "));
        Serial.println(pH_mV);
        stats.add(pH_mV);
        currentMillis = millis();
    }
    pH_mV = stats.average();
    return(pH_mV);
}

void pH::calcpHSlope (void)
{   //y = mx + b   m = (y2-y1)/(x2-x1)  x2 = 7 and x1 = 4.  y2 = pH7Volts (in mV) and y1 = pH4Volts (in mV) - mV because ideal slope = 59.16mV
    params.pHSlopeMV = fabs(params.pH7MV - params.pH4MV)/3; //the way the pH is calculated assumes a + slope.
    eeprom_write_block(&params, (void *)0, sizeof(params));
}
void pH::printParams(void)
{
    calcpHSlope(); //TESTING....
    Serial.println(F("---------------------------------"));
    Serial.print(F("pH 4 mV    : "));
    Serial.println(params.pH4MV);
    Serial.print(F("pH 7 mV    : "));
    Serial.println(params.pH7MV);
    Serial.print(F("pH Slope mV: "));
    Serial.println(params.pHSlopeMV);
    
}
