#include "Buzzer.h"
#include <Arduino.h>


Buzzer::Buzzer(int m1p1 , int m1p2 , int m2p1 , int m2p2)
{
    _m1p1 = m1p1;
    _m1p2 = m1p2;
    _m2p1 = m2p1;
    _m2p2 = m2p2;

    pinMode(_m1p1 , OUTPUT);
    pinMode(_m1p2 , OUTPUT);
    pinMode(_m2p1 , OUTPUT);
    pinMode(_m2p2 , OUTPUT);
}


void Buzzer::buzz()
{
    digitalWrite(_m1p1 , HIGH);
    digitalWrite(_m1p2 , LOW);
    digitalWrite(_m2p1 , HIGH);
    digitalWrite(_m2p2 , LOW);
}


void Buzzer::stop()
{
    digitalWrite(_m1p1 , LOW);
    digitalWrite(_m1p2 , LOW);
    digitalWrite(_m2p1 , LOW);
    digitalWrite(_m2p2 , LOW);
}