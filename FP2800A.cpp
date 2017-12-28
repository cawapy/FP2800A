#include "FP2800A.h"

#include <Arduino.h>

FP2800A::FP2800A(uint8_t a0Pin, uint8_t a1Pin, uint8_t a2Pin, uint8_t b0Pin, uint8_t b1Pin, uint8_t dataPin, uint8_t enPin) :
    a0Pin(a0Pin),
    a1Pin(a1Pin),
    a2Pin(a2Pin),
    b0Pin(b0Pin),
    b1Pin(b1Pin),
    dtPin(dataPin),
    enPin(enPin)
{
}

void FP2800A::begin()
{
    pinMode(a0Pin, OUTPUT);
    pinMode(a1Pin, OUTPUT);
    pinMode(a2Pin, OUTPUT);
    pinMode(b0Pin, OUTPUT);
    pinMode(b1Pin, OUTPUT);
    pinMode(dtPin, OUTPUT);
    pinMode(enPin, OUTPUT);
    digitalWrite(enPin, LOW);
}

void FP2800A::EnableDriver(uint8_t c, bool set)
{
    if (c > 20) c += 4;
    else if (c > 13) c += 3;
    else if (c > 6) c += 2;
    else c += 1;

    digitalWrite(a0Pin, (c & (1 << 0)) ? HIGH : LOW);
    digitalWrite(a1Pin, (c & (1 << 1)) ? HIGH : LOW);
    digitalWrite(a2Pin, (c & (1 << 2)) ? HIGH : LOW);
    digitalWrite(b0Pin, (c & (1 << 3)) ? HIGH : LOW);
    digitalWrite(b1Pin, (c & (1 << 4)) ? HIGH : LOW);
    digitalWrite(dtPin, set ? HIGH : LOW);
    digitalWrite(enPin, HIGH);

}

void FP2800A::DisableDriver()
{
    digitalWrite(enPin, LOW);
}
