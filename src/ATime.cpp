#include "ATime.h"

ATime::ATime()
      : hours(0), minutes(0), seconds(0) {}

// TODO: Sanitize input
ATime::ATime(const int hours, const int minutes)
      : hours(hours), minutes(minutes), seconds(0) {}

ATime& ATime::operator=(const ATime& t)
{
    if (&t == this)
      return *this;
    
    hours = t.hours;
    minutes = t.minutes;

    return *this;
}

bool ATime::operator==(const ATime& t) const
{
    return minutes == t.minutes && hours == t.hours;
}

void ATime::reset()
{
    minutes = 0;
    hours = 0;
    seconds = 0;
}

ATime& ATime::operator++(int i)
{
    seconds++;

    if (seconds >= 60)
    {
        seconds = 0;
        minutes++;
    }

    if (minutes >= 60)
    {
        minutes = 0;
        hours++;
    }

    if (hours > 12)
        hours = 1;

    return *this;
}