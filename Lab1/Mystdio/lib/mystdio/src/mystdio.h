#ifndef MYSTDIO_HEADER
#define MYSTDIO_HEADER

#include <stdio.h>
#include <Arduino.h>
#include <Keypad.h>

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

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

static FILE *f;

enum StreamIO { SERIALIO, KEYPADIO, LCDIO };

class Mystdio {
  private:
    static int putCharSerial(char c, FILE *stream);
    static char getCharSerial(FILE *stream);
    static int putCharLCD(char c, FILE *stream);
    static char getCharLCD(FILE *stream);

  public:
    Mystdio(StreamIO streamIO);
    String readStr();
    void writeStr(String str);
    void open(StreamIO streamIo);
};

#endif