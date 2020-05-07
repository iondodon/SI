#include <Arduino.h>
#include "../include/Lab1/button.h"

Button::Button(uint8_t pin) {
    this->pin = pin;
    pinMode(pin, INPUT_PULLUP);
}

int Button::buttonIsPressed(){
    int pressed = 0;
    int buttonState = digitalRead(this->pin);  
    if (buttonState == HIGH && previousState == LOW && millis() - lastDebounceTime > debounceDelay) {
        pressed = 1;
        lastDebounceTime = millis();
    }
    previousState = buttonState;
    return pressed;
}