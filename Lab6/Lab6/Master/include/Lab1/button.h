#pragma once
#define debounceDelay 200

class Button{
    private:
    uint8_t pin;
    long lastDebounceTime = 0;
    int  previousState = LOW;

    public:
    Button(uint8_t pin);
    int buttonIsPressed();
};


