#include <Arduino.h>
#include "src/ATime.h"
#include "src/MatrixPad.h"

ATime currentTime;
ATime alarm;
ATime timer;
int seconds;
bool updated;
Keypad pad = MATRIXPAD;

// get the time from the keypad and return
// it as a struct.
// this is a blocking function, and will
// interrupt the internal clock.
ATime getInputTime()
{
    int hours;
    int minutes;
    Serial.println("Updating time.");
    char first;
    char second;
    
    // get hours
    first = pad.waitForKey() - '0';
    second = pad.waitForKey() - '0';
    hours = first * 10 + second;

    Serial.print("Hour: ");
    Serial.println(hours);

    first = pad.waitForKey()  - '0';
    second = pad.waitForKey() - '0';
    minutes = first * 10 + second;

    Serial.print("Minute: ");
    Serial.println(minutes);

    return ATime(hours, minutes);
}

// update the internal clock.
void updateTime()
{
    if (millis() % 1000 != 0)
        updated = false;

    // clock test, should blink once a second.
    if (!updated && millis() % 1000 == 0)
    {
        updated = true;
        Serial.print("current time: ");
        Serial.print(currentTime.hours);
        Serial.print(':');
        Serial.print(currentTime.minutes);
        Serial.print(':');
        Serial.println(seconds);
        seconds++;
    }

    if (seconds >= 60)
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

// buzz the motor.
void buzz()
{
}

// by default open setTime.
void setup()
{
    // set current time.
    //currentTime = getInputTime();
    seconds = 0;

    // alarm defaults to midnight.
    alarm.reset();

    // set up pins.
    Serial.begin(9600);
}

void loop()
{
    // buzz buzz
    if (currentTime == alarm)
        buzz();

    // get check for user input.
    // check if we need to set a timer, update the alarm, or set the time.
    char pressed[LIST_MAX];
    int updatedCount = 0;
    if (pad.getKeys())
    {
        for (int k = 0; k < LIST_MAX; k++)
        {
            if (!pad.key[k].stateChanged)
                continue;
            
            if (pad.key[k].kstate == PRESSED)
            {
                pressed[updatedCount] = pad.key[k].kchar;
                updatedCount++;
            }
        }
    }

    // check the keys that are pressed at this instant.
    if (updatedCount == 2 && (pressed[0] | pressed[1]) == CHANGETIME)
    {
        Serial.println("Update the current time.");
        currentTime = getInputTime();
    }
    if (updatedCount == 1)
    {
        switch (pressed[0])
        {
        case KA:
            Serial.println("Set the alarm.");
            alarm = getInputTime();
            break;
        case KT:
            Serial.println("Set the timer.");
            timer = getInputTime();
        }
    }

    updateTime();
}

int main()
{
    init();
    setup();
    
    for (;;)
        loop();
}