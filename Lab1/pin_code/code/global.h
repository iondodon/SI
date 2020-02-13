#ifndef HEADER_FILE
#define HEADER_FILE

#include<Keypad.h>
#include <SPI.h>
#include "LiquidCrystal.h"

#define LED_RED 15
#define LED_GREEN 14

const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns

char keys[ROWS][COLS] = {
  {'7', '8', '9', '/'},
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'c', '0', '=', '+'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; // connect to rows pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; // connect to column pinouts of the keypad

int i = 0;
char arr[10];

int secret_code = 1234;
int inserted_code = 0;

#endif
