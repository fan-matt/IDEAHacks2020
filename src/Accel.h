#ifndef ACCEL_H_
#define ACCEL_H_

class Accel
{
public:
    Accel(int, int, int, int, int);
    int* read();

private:
    int m_powerPin;
    int m_ground;
    int m_x;
    int m_y;
    int m_z;
};

#endif  // ACCEL_H_