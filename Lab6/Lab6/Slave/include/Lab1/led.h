#pragma once
#include <Arduino.h>

class Led {
    private:
    uint8_t pin;
    uint8_t state;
    void setState(uint8_t);
    int ledIsOn();

    public:
    Led(uint8_t);
    void on();
    void off();
    void toggle();
    void blink(unsigned long);
};