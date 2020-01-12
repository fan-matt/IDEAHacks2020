#ifndef ACCEL_H_
#define ACCEL_H_

// Threshold beyond which a hit is registered.
#define HIT_THRESHOLD 200

// Accel represents a hardware accelerometer.
class Accel
{
public:
    Accel(int, int, int, int, int);
    void updateAccel();
    int* readAccel() const;
    bool bigShift() const;

private:
    int m_powerPin;
    int m_ground;
    int m_prevX;
    int m_prevY;
    int m_prevZ;
    int m_x;
    int m_y;
    int m_z;

    int abs(int) const;
};

#endif  // ACCEL_H_