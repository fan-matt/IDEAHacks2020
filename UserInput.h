#ifndef USERINPUT_H_
#define USERINPUT_H_

#include "ATime.h"
#include <Keypad.h>

class UserInput
{
public:
    // TODO: Add display functionality.
    UserInput(Keypad);

    int len() const;
    char operator[](const int) const;
    bool hit() const;

    ATime getInputTime() const;
    void update();

private:
    Keypad m_pad;
    int m_count;
    char m_pressed[LIST_MAX];
    bool m_hit;
};

#endif  // USERINPUT_H_
