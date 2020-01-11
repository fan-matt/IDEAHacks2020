#include <Arduino.h>
#include "src/ATime.h"
#include "src/MatrixPad.h"

ATime currentTime;
ATime alarm;
int seconds;
Keypad pad = MATRIXPAD;

// get the time from the keypad and return
// it as a struct.
ATime getInputTime()
{
    return ATime();
}

// buzz the motor.
void buzz() {}

// by default open setTime.
void setup()
{
    currentTime.reset();
    seconds = 0;

    alarm = getInputTime();
}

void loop()
{
    // buzz buzz
    if (currentTime == alarm)
        buzz();

    // check for user input.
    if (pad.getKeys())
    {
        // TODO: handle input.
    }

    // if we need to update the time, then do so.
    if (pad.getKey() == CHANGETIME)
        alarm = getInputTime();

    if (!(millis() % 1000))
        seconds++;

    if (seconds > 60)
    {
      seconds = 0;
      currentTime.minutes++;
    }

    if (currentTime.minutes >= 60)
    {
      currentTime.minutes = 0;
      currentTime.hours++;
    }

    if (currentTime.hours > 12)
      currentTime.hours = 1;
}

int main()
{
    init();
    setup();
    
    for (;;)
        loop();
}