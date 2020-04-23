#ifndef LAMP_h
#define LAMP_h

#include <Arduino.h>

class LAMP {
    public:
        LAMP();
        LAMP(uint8_t pin);
        void setOn();
        void setOff();
        boolean isOn();
    private:
        boolean on;
        uint8_t pin;
};

#endif