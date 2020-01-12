#ifndef TIME_DISPLAY_H
#define TIME_DISPLAY_H

#include "ATime.h"

#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include <Wire.h>

class TimeDisplay 
{
public:
    TimeDisplay();

    void start();
    
    void setTime(ATime time);

private:
    Adafruit_AlphaNum4 alpha4;
};

#endif
