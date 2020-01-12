#include <Arduino.h>
#include "src/ATime.h"
#include "src/UserInput.h"
#include "src/Accel.h"
#include "src/MatrixPad.h"

#define ACCELPOWER 1
#define ACCELGROUND 2
#define ACCELX 3
#define ACCELY 4
#define ACCELZ 5

ATime currentTime;
ATime alarm;
ATime timer;
bool updated;
bool buzzing;
UserInput u(MATRIXPAD, Accel(ACCELPOWER, ACCELGROUND, ACCELX, ACCELY, ACCELZ));

// buzz the motor.
void toggleBuzz()
{
    buzzing = !buzzing;
    Serial.println("BUZZ");
}

// by default open setTime.
void setup()
{
    // set up pins.
    Serial.begin(9600);
    
    // set current time.
    Serial.println("Input the time:");
    currentTime = u.getInputTime();

    // alarm defaults to midnight.
    alarm.reset();

    // buzz buzz
    buzzing = false;
}

void loop()
{
    // buzz buzz
    if (currentTime == alarm)
        toggleBuzz();

    // check for user input.
    // check if we need to set a timer, update the alarm, or set the time.
    u.update();

    // if the pillow is being hit, stop the buzzing.
    if (u.hit())
        toggleBuzz();

    // check the keys that are pressed at this instant.
    if (u.len() == 2 && (u[0] | u[1]) == CHANGETIME)
    {
        Serial.println("Update the current time.");
        currentTime = u.getInputTime();
    }
    if (u.len() == 1)
    {
        switch (u[0])
        {
        case KA:
            Serial.println("Set the alarm.");
            alarm = u.getInputTime();
            break;
        case KT:
            Serial.println("Set the timer.");
            timer = u.getInputTime();
        }
    }

    // update time
    if (millis() % 1000 != 0)
        updated = false;
    
    if (!updated && millis() % 1000 == 0)
    {
        currentTime++;
        Serial.print("current time: ");
        Serial.print(currentTime.hours);
        Serial.print(':');
        Serial.print(currentTime.minutes);
        Serial.print(':');
        Serial.println(currentTime.seconds);
        updated = true;
    }
}

int main()
{
    init();
    setup();
    
    for (;;)
        loop();
}