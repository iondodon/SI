#include "ledd.h"

Ledd::Ledd(int digitalPin) {
  this->digitalPin = 12;
  pinMode(this->digitalPin, OUTPUT);
  this->on = false;
}

bool Ledd::isOn() {
  return this->on;
}

void Ledd::turnOn() {
  digitalWrite(this->digitalPin, HIGH); 
  this->on = true;
}

void Ledd::turnOff() {
  digitalWrite(this->digitalPin, LOW);
  this->on = false;
}