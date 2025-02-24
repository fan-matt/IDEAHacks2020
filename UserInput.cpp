#include "UserInput.h"

UserInput::UserInput(Keypad k)
          : m_pad(k) {}

int UserInput::len() const { return m_count; }

char UserInput::operator[](const int i) const { return m_pressed[i]; }

// get the time from the keypad and return
// it as a struct.
// this is a blocking function, and will
// interrupt the internal clock.
ATime UserInput::getInputTime() const
{
    int hours;
    int minutes;

    char first;
    char second;
    
    // get hours
    first = m_pad.waitForKey() - '0';
    second = m_pad.waitForKey() - '0';
    hours = first * 10 + second;

    first = m_pad.waitForKey()  - '0';
    second = m_pad.waitForKey() - '0';
    minutes = first * 10 + second;

    return ATime(hours, minutes);
}

// update UserInput to reflect most recent
// input.
void UserInput::update()
{
    // update keys being pressed.
    m_count = 0;
    if (m_pad.getKeys())
    {
        for (int k = 0; k < LIST_MAX; k++)
        {
            if (!m_pad.key[k].stateChanged)
                continue;
            
            if (m_pad.key[k].kstate == PRESSED)
            {
                m_pressed[m_count] = m_pad.key[k].kchar;
                m_count++;
            }
        }
    }
}
