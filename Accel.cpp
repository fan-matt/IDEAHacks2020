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

int* Accel::read()
{
      int a = analogRead(m_x);
      int b = analogRead(m_y);
      int c = analogRead(m_z);

      int res[3] = {a, b, c};
      return res;
}