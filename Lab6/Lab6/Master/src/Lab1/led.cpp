#include "../include/Lab1/led.h"
#include <Arduino.h>

Led::Led(uint8_t pin) {
    this->pin = pin;
    pinMode(pin, OUTPUT);
    setState(LOW);
}

void Led::on() {
    setState(HIGH);
}

void Led::off() {
    setState(LOW);
}

void Led::toggle() {
    if (ledIsOn()) {
        off();
    } else {
        on();
    }
}

void Led::setState(uint8_t state) {
    this->state = state;
    digitalWrite(this->pin, state);
}

int Led::ledIsOn() {
    return this->state == HIGH;
}

void Led::blink(unsigned long d) {
    on();
    delay(d);
    off();
}