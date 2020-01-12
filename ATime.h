#ifndef ATIME_H_
#define ATIME_H_

// Arduino Time => ATime
struct ATime
{
  ATime();
  ATime(const int, const int);
  ATime& operator=(const ATime& t);
  bool operator==(const ATime& t) const;
  ATime& operator++(int);
  void reset();

  int hours;
  int minutes;
  int seconds;
};

#endif  // ATIME_H_
