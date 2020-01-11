typedef struct Time
{
  int minutes;
  int hours;

  Time& operator=(const Time& t) {
    if (&t == this)
      return *this;
      
    minutes = t.minutes;
    hours = t.hours;

    return *this;
  }
};
int seconds = 0;

Time currentTime, alarm;

// by default open setTime.
void setup() {
  resetTime();
}

void resetTime() {
  currentTime.minutes = 0;
  currentTime.hours = 0;
}

Time getTime() {
  return Time();
}

void setTime() {
  resetTime();

  alarm = getTime();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  currentTime.hours++;
  currentTime.hours &= 13;
}
