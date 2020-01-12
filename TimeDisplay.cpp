#include "TimeDisplay.h"


TimeDisplay::TimeDisplay()
{
    
}


void TimeDisplay::start()
{
    alpha4 = Adafruit_AlphaNum4();
    alpha4.begin(0x70);  // pass in the address

    alpha4.clear();
    alpha4.writeDigitAscii(0, '0');
    alpha4.writeDigitAscii(1, '0');
    alpha4.writeDigitAscii(2, '0');
    alpha4.writeDigitAscii(3, '0');
    alpha4.writeDisplay();
}


void TimeDisplay::setTime(ATime time)
{
    alpha4.writeDigitAscii(0, (time.hours / 10) + '0');
    alpha4.writeDigitAscii(1, (time.hours % 10) + '0');
    alpha4.writeDigitAscii(2, (time.minutes / 10) + '0');
    alpha4.writeDigitAscii(3, (time.minutes % 10) + '0');
    alpha4.writeDisplay();
}
