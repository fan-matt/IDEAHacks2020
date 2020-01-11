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
    char first;
    char second;
    
    // get hours
    for (int k = 0; k < 2; k++)
    {
        first = pad.waitForKey() - '0';
        second = pad.waitForKey() - '0';
    }

    for (int k = 0; k < 2; k++)
    {
        first = pad.waitForKey()  - '0';
        second = pad.waitForKey() - '0';
    }

    return ATime();
}

// update the internal clock.
void updateTime()
{
    // clock test, should blink once a second.
    seconds++;
    Serial.println(seconds);
    Serial.println("have passed");    

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

    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
}

// buzz the motor.
void buzz()
{
}

// by default open setTime.
void setup()
{
    // set current time.
    currentTime = getInputTime();
    seconds = 0;

    // alarm defaults to midnight.
    alarm.reset();

    // set up pins.
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    // buzz buzz
    if (currentTime == alarm)
        buzz();

    // TODO: get check for user input.
    char c = pad.waitForKey();
    Serial.println(c);

    // if we need to update the alarm, then do so.
    if (pad.getKey() == CHANGETIME)
        alarm = getInputTime();

    updateTime();
}

int main()
{
    init();
    setup();
    
    for (;;)
        loop();
}