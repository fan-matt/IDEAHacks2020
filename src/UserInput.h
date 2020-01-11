#ifndef USERINPUT_H_
#define USERINPUT_H_

#include "Accel.h"
#include "../Keypad/src/Keypad.h"

class UserInput
{
public:
    UserInput(const Keypad, const Accel);

    int len() const;
    char operator[](const int) const;
    bool hit() const;

    void update();

private:
    Accel m_a;
    Keypad m_k;
    int m_buttonsPressed;
    char m_pressed[LIST_MAX];
    bool m_hit;
};

#endif  // USERINPUT_H_