#ifndef LEDD_HEADER
#define LEDD_HEADER

#include <Arduino.h>

class Ledd {
  private:
    int digitalPin;
    bool on;
  
  public:
    Ledd(int digitalPin);
    void turnOn();
    void turnOff();
    bool isOn();
};

#endif