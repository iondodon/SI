#include "../include/Lab1/myKeypad.h"
#include <Keypad.h>
#include "../include/Lab1/myStdio.h"

const byte ROWS = 4;
const byte COLS = 4;

char keys[4][4] =
{
  {'7', '8', '9', '/'},
  {'4', '5', '6', 'X'},
  {'1', '2', '3', '-'},
  {'C', '0', '=', '+'}
};

byte rowPins[4] =  {11, 10, 9, 8};
byte colPins[4] =  {7 , 6, 4, 3};

MyKeypad::MyKeypad() {
  this->keypad = new Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
}

char MyKeypad::getKey() {
  if (this->key) {
    char k = this->key;
    this->key = NO_KEY;
    return k;
  }
  return NO_KEY;
}

void MyKeypad::openInputStream() {
  FILE *fd = myStdioOpen(this);
  stdin = fd;
}

int MyKeypad::isKeyPressed() {
  this->key = this->keypad->getKey();
  return key;
}