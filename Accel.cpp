#include "Accel.h"
#include <Arduino.h>

Accel::Accel(int power, int ground, int x, int y, int z)
      : m_acc(Adafruit_ADXL345_Unified()), m_powerPin(power), m_groundPin(ground), m_x(x), m_y(y), m_z(z)
{
    pinMode(m_powerPin, OUTPUT);
    pinMode(m_groundPin, OUTPUT);
    digitalWrite(m_groundPin, LOW);
    digitalWrite(m_powerPin, HIGH);
    m_acc.begin();
    m_acc.setRange(ADXL345_RANGE_16_G);
}

// read from the accelerometer and update its readings.
void Accel::updateAccel()
{
    // TODO: Read from accelerometer, update readings and previous reading.
    sensors_event_t e;
    m_acc.getEvent(&e);

    m_prevX = m_x;
    m_prevY = m_y;
    m_prevZ = m_z;
    m_x = e.acceleration.x;
    m_y = e.acceleration.y;
    m_z = e.acceleration.z;
}

// returns whether the accelerometer has moved a "big" amount
// since the past update.
bool Accel::bigShift() const
{
    return abs((m_prevX - m_x)) > HIT_THRESHOLD ||
           abs((m_prevY - m_y)) > HIT_THRESHOLD ||
           abs((m_prevZ - m_z)) > HIT_THRESHOLD;
}

// absolute value.
int Accel::absolute(int i) const { return i < 0 ? i*-1 : i; }
