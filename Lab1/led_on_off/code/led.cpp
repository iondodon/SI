#include "led.h"

Led::Led(int digitaPin) {
  this->digitalPin = digitalPin;
  pinMode(digitalPin, OUTPUT);
}

void Led::turnOn(){
  digitalWrite(this->digitalPin, HIGH);
}

void Led::turnOff(){
  digitalWrite(this->digitalPin, LOW);
}
