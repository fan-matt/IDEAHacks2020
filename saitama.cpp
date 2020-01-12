#include <Arduino.h>
#include "src/ATime.h"
#include "src/UserInput.h"
#include "src/Accel.h"
#include "src/Buzzer.h"
#include "src/MatrixPad.h"

// Accelerometer pins
#define ACCELPOWER 1
#define ACCELGROUND 2
#define ACCELX 3
#define ACCELY 4
#define ACCELZ 5

// Motor pins
#define M1P1 2
#define M1P2 3
#define M2P1 4
#define M2P2 5

ATime currentTime;
ATime alarm;
ATime timer;
bool updated;
Buzzer b(M1P1, M1P2, M2P1, M2P2);
UserInput u(MATRIXPAD, Accel(ACCELPOWER, ACCELGROUND, ACCELX, ACCELY, ACCELZ));

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
}

void loop()
{
    // buzz buzz
    if (currentTime == alarm)
        b.buzz();

    // check for user input.
    // check if we need to set a timer, update the alarm, or set the time.
    u.update();

    // if the pillow is being hit, stop the buzzing.
    if (u.hit())
        b.stop();

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