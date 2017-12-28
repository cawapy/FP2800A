#pragma once

#include <inttypes.h>

class FP2800A
{
    const uint8_t a0Pin;
    const uint8_t a1Pin;
    const uint8_t a2Pin;
    const uint8_t b0Pin;
    const uint8_t b1Pin;
    const uint8_t dtPin;
    const uint8_t enPin;

public:
    FP2800A(uint8_t a0Pin, uint8_t a1Pin, uint8_t a2Pin, uint8_t b0Pin, uint8_t b1Pin, uint8_t dataPin, uint8_t enPin);

    void begin();
    void EnableDriver(uint8_t c, bool set);
    void DisableDriver();
};
