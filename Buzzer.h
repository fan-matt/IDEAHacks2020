#ifndef BUZZER_H
#define BUZZER_H

class Buzzer
{
public:
    /*
     * Motor 1 pin 1 , motor 1 pin 2 , etc.
     */
    Buzzer(int m1p1 , int m1p2 , int m2p1 , int m2p2);

    void buzz();

    void stop();

private:
    /*
     * Motor 1 pin 1 , motor 1 pin 2 , etc.
     */
    int _m1p1;
    int _m1p2;
    int _m2p1;
    int _m2p2;
};

#endif