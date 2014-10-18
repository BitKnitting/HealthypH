//
//  LEDDiags.cpp
//  HealthypHTestV1
//
//  Created by Margaret Johnson on 9/23/14.
//  Copyright (c) 2014 Margaret Johnson. All rights reserved.
//

#include "LEDDiags.h"

LEDDiagTests::LEDDiagTests (byte red_pin,byte green_pin,byte blue_pin)
{
    Red_pin = red_pin;
    Green_pin = green_pin;
    Blue_pin = blue_pin;
    pinMode(Red_pin, OUTPUT);
    pinMode(Green_pin,OUTPUT);
    pinMode(Blue_pin,OUTPUT);
    //turn LED off to start
    analogWrite(Red_pin,255);
    analogWrite(Green_pin, 255);
    analogWrite(Blue_pin, 255);
    
}
void LEDDiagTests::turnLEDon(byte red, byte green, byte blue)
{
    Serial.println(F("***turnLEDon***"));

    // constrain the values to 0 - 255 and invert]
    // if you're using a common-cathode LED, just use "constrain(color, 0, 255);"
    red = constrain(red, 0, 255);
    green = constrain(green, 0, 255);
    blue = constrain(blue, 0, 255);
    Serial.print(F("Red: "));
    Serial.print(red);
    Serial.print(F(", Green: "));
    Serial.print(green);
    Serial.print(F(", Blue: "));
    Serial.println(blue);
    analogWrite(Red_pin, red);
    analogWrite(Green_pin, green);
    analogWrite(Blue_pin, blue);
}
void LEDDiagTests::turnLEDoff()
{
    analogWrite(Red_pin,255);
    analogWrite(Green_pin,255);
    analogWrite(Blue_pin,255);
}
