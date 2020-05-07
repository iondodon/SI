#include "../include/Lab1/lcd.h"
#include "../include/Lab1/myStdio.h"

Lcd::Lcd(uint8_t pin1, uint8_t pin2, uint8_t pin3, 
         uint8_t pin4, uint8_t pin5, uint8_t pin6){
    this->lcd = new LiquidCrystal(pin1, pin2, pin3, pin4, pin5, pin6);
    this->lcd -> begin(16, 2);
}

void Lcd::setCursorLCD(uint8_t col, uint8_t row){
    this->lcd->setCursor(col, row);
}

void Lcd::clearScreen(){
    this->lcd->clear();
}

void Lcd::openStream() {
    FILE *fd = myStdioOpen(this->lcd);
    stdout = fd;
    stdin = NULL;
}
