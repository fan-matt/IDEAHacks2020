#include "ATime.h"

ATime::ATime()
      : hours(0), minutes(0) {}

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

void ATime::reset() {
  minutes = 0;
  hours = 0;
}