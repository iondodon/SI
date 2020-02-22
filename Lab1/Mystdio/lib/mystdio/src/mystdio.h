#ifndef MYSTDIO_HEADER
#define MYSTDIO_HEADER

#include <stdio.h>
#include <Arduino.h>
#include <Keypad.h>
#include "LiquidCrystal.h"

static FILE *f;

enum StreamIO { SERIALIO, KEYPADIO, LCDIO };

class Mystdio {
  private:
    static int putCharSerial(char c, FILE *stream);
    static char getCharSerial(FILE *stream);
    static int putCharKeypad(char c, FILE *stream);
    static char getCharKeypad(FILE *stream);
    static int putCharLcd(char c, FILE *stream);
    static char getCharLcd(FILE *stream);

  public:
    Mystdio();
    String readStr();
    void writeStr(String str);
    void open(StreamIO streamIo);
};

#endif