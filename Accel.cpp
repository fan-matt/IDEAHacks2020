#include "Accel.h"
#include <Arduino.h>

Accel::Accel()
      : m_prevX(0), m_prevY(0), m_prevZ(0),
        m_x(0), m_y(0), m_z(0)
{
}

void Accel::start()
{
  m_acc = Adafruit_ADXL345_Unified(12345);
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
