#include <Arduino.h>
#include "ATime.h"
#include "UserInput.h"
#include "Buzzer.h"
#include "MatrixPad.h"
#include "TimeDisplay.h"
#include "Adafruit_ADXL345_U.h"

// Motor pins
#define M1P1 2
#define M1P2 3
#define M2P1 4
#define M2P2 5

// Accelerometer diff.
#define HIT_THRESHOLD 50

double m_x, m_y, m_z, m_prevX, m_prevY, m_prevZ;

ATime currentTime;
ATime alarm;
ATime timer;
bool updated;
Buzzer b(M1P1, M1P2, M2P1, M2P2);
TimeDisplay tDisplay;
Adafruit_ADXL345_Unified acc;
UserInput u(MATRIXPAD);

// by default open setTime.
void setup()
{
    tDisplay.start();
  
    // set up pins.
    Serial.begin(9600);
    
    // set current time.
    Serial.println("Input the time:");
    currentTime = u.getInputTime();

    // alarm defaults to midnight.
    alarm.reset();

    // start accel
    m_x = 0;
    m_y = 0;
    m_z = 0;
    m_prevX = 0;
    m_prevY = 0;
    m_prevZ = 0;
    acc = Adafruit_ADXL345_Unified(12345);
    if (!acc.begin()){
      Serial.println("this shit broke dog");
    }
    acc.setRange(ADXL345_RANGE_16_G);
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
    if (abs((m_prevX - m_x)) > HIT_THRESHOLD ||
        abs((m_prevY - m_y)) > HIT_THRESHOLD ||
        abs((m_prevZ - m_z)) > HIT_THRESHOLD)
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
        Serial.print(currentTime.seconds);
        Serial.print(" accel X: ");
        Serial.println(m_x);
        updated = true;

        tDisplay.setTime(currentTime);
    }

    // Read from accelerometer, update readings and previous reading.
    sensors_event_t e;
    acc.getEvent(&e);

    m_prevX = m_x;
    m_prevY = m_y;
    m_prevZ = m_z;
    m_x = e.acceleration.x;
    m_y = e.acceleration.y;
    m_z = e.acceleration.z;
}
