#ifndef MATRIXPAD_H_
#define MATRIXPAD_H_

#include "../Keypad/src/Keypad.h"

enum
{
    K0 = '0',
    K1 = '1',
    K2 = '2',
    K3 = '3',
    K4 = '4',
    K5 = '5',
    K6 = '6',
    K7 = '7',
    K8 = '8',
    K9 = '9',
    KT = '*',
    KA = '#',
    CHANGETIME = KT|KA
};

const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS] = {
    {K1, K2, K3},
    {K4, K5, K6},
    {K7, K8, K9},
    {KT, K0, KA}
};
byte rowPins[ROWS] = {12, 11, 10, 9};
byte colPins[COLS] = {8, 7, 6};

#define MATRIXPAD Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS)

#endif  // MATRIXPAD_H_