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

private:
    int m_powerPin;
    int m_groundPin;
    int m_prevX;
    int m_prevY;
    int m_prevZ;
    int m_x;
    int m_y;
    int m_z;

    Adafruit_ADXL345_Unified m_acc;

    int absolute(int) const;
};

#endif  // ACCEL_H_
