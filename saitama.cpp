#include <Arduino.h>
#include "src/ATime.h"

ATime currentTime;
ATime alarm;
int seconds;

// by default open setTime.
void setup()
{
  currentTime.reset();
  seconds = 0;

  // TODO: Set alarm time.
}

void loop()
{
  // buzz buzz
  //if (currentTime == alarm)
  //  buzz();

  seconds++;
  if (seconds > 60) {
    seconds = 0;
    currentTime.minutes++;
  }

  if (currentTime.minutes >= 60) {
    currentTime.minutes = 0;
    currentTime.hours++;
  }

  if (currentTime.hours > 12) {
    currentTime.hours = 1;
  }

  delay(1000);
}

int main()
{
    init();
    setup();
    
    for (;;) {
        loop();
    }
}