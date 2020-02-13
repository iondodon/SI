#include "button.h"

Button::Button(int digitalPin) {
  this->digitalPin = digitalPin;
  pinMode(digitalPin, INPUT_PULLUP);
}

bool Button::pressed() {
  if(digitalRead(this->digitalPin) == LOW) {
    return true;
  }
  return false;
}
