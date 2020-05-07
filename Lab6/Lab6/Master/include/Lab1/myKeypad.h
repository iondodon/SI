#pragma once
#include <Keypad.h>

class MyKeypad {
    private:
    Keypad *keypad;
    char key;
    
    public:
    MyKeypad();
    char getKey();
    void openInputStream();
    int isKeyPressed();
};