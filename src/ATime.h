#ifndef ATIME_H_
#define ATIME_H_

// Arduino Time => ATime
struct ATime
{
  ATime();
  ATime(const int, const int);
  ATime& operator=(const ATime& t);
  bool operator==(const ATime& t) const;
  void reset();

  int hours;
  int minutes;
};

#endif  // ATIME_H_