#ifndef BUTTON_HEADER
#define BUTTON_HEADER

#include <Arduino.h>

class Button {
  private:
    int digitalPin;
  public:
    Button(int digitalPin);
    bool pressed();
};

#endif
