#ifndef USERINPUT_H_
#define USERINPUT_H_

#define HIT_THRESHOLD 200

#include "Accel.h"
#include "ATime.h"
#include "../Keypad/src/Keypad.h"

class UserInput
{
public:
    // TODO: Add display functionality.
    UserInput(Keypad, Accel);

    int len() const;
    char operator[](const int) const;
    bool hit() const;

    ATime getInputTime() const;
    void update();

private:
    Accel m_accel;
    Keypad m_pad;
    int m_count;
    char m_pressed[LIST_MAX];
    bool m_hit;
};

#endif  // USERINPUT_H_