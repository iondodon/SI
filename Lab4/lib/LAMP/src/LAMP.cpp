#include <LAMP.h>

LAMP::LAMP() {
    this->pin = LED_BUILTIN;
    pinMode(this->pin, OUTPUT);
    this->on = false;
}

LAMP::LAMP(uint8_t pin) {
    this->pin = pin;
    pinMode(this->pin, OUTPUT);
    this->on = false;
}

boolean LAMP::isOn() {
    return this->on;
}

void LAMP::setOn() {
    digitalWrite(this->pin, HIGH);
    this->on = true;
}

void LAMP::setOff() {
    digitalWrite(this->pin, LOW);
    this->on = false;
}