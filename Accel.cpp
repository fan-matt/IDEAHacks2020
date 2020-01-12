#include "Accel.h"
#include <Arduino.h>

Accel::Accel()
      : m_prevX(0), m_prevY(0), m_prevZ(0),
        m_x(0), m_y(0), m_z(0)
{
}

void Accel::start()
{

}

// read from the accelerometer and update its readings.
void Accel::updateAccel()
{
    // Read from accelerometer, update readings and previous reading.
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
    return absolute((m_prevX - m_x)) > HIT_THRESHOLD ||
           absolute((m_prevY - m_y)) > HIT_THRESHOLD ||
           absolute((m_prevZ - m_z)) > HIT_THRESHOLD;
}

// absolute value.
int Accel::absolute(int i) const { return i < 0 ? i*-1 : i; }
