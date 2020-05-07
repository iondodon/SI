#pragma once

#include <LiquidCrystal.h>

class Lcd{
    private:
    LiquidCrystal *lcd;
    public:
    Lcd(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, uint8_t pin5, uint8_t pin6);
    void setCursorLCD(uint8_t col, uint8_t row);
    void clearScreen();
    void openStream();
};