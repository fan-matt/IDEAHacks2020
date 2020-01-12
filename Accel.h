#ifndef ACCEL_H_
#define ACCEL_H_

#include <Adafruit_ADXL345_U.h>

// Threshold beyond which a hit is registered.
#define HIT_THRESHOLD 200

// Accel represents a hardware accelerometer.
class Accel
{
public:
    Accel();
    void start();
    void updateAccel();
    int* readAccel() const;
    bool bigShift() const;
    int m_powerPin;
    int m_groundPin;
    double m_prevX;
    double m_prevY;
    double m_prevZ;
    double m_x;
    double m_y;
    double m_z;

    Adafruit_ADXL345_Unified m_acc;

    int absolute(int) const;
};

#endif  // ACCEL_H_
