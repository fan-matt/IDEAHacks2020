#include "Accel.h"
#include <Arduino.h>

Accel::Accel(int power, int ground, int x, int y, int z)
      : m_powerPin(power), m_ground(ground), m_x(x), m_y(y), m_z(z)
{
    pinMode(m_powerPin, OUTPUT);
    pinMode(m_ground, OUTPUT);
    digitalWrite(m_ground, LOW);
    digitalWrite(m_powerPin, HIGH);
}

// read from the accelerometer and update its readings.
void Accel::updateAccel()
{
    // TODO: Read from accelerometer, update readings and previous reading.
}

// return an array of three integers, being the
// readings for the x, y, and z acceleration
// of the accelerometer at the current time.
int* Accel::readAccel() const
{
    int a = analogRead(m_x);
    int b = analogRead(m_y);
    int c = analogRead(m_z);

    int res[3] = {a, b, c};
    return res;
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
int Accel::abs(int i) const { return i < 0 ? i*-1 : i; }