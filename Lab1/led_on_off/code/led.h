#ifndef LED_HEADER
#define LED_HEADER

#include <Arduino.h>

class Led {
  private:
    int digitalPin;
  public:
    Led(int digitalPin);
    void turnOn();
    void turnOff();
};

#endif
