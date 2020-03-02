#ifndef MYSTDIO_HEADER
#define MYSTDIO_HEADER

#include <stdio.h>
#include <Arduino.h>
#include <Keypad.h>

static FILE *f;

enum StreamIO { SERIALIO, KEYPADIO, LCDIO, ANALOGIO };

class Mystdio {
  private:
    static int putCharSerial(char c, FILE *stream);
    static char getCharSerial(FILE *stream);

  public:
    Mystdio();
    String readStr();
    void writeStr(String str);
    void open(StreamIO streamIo);
    void printDouble(double);
};

#endif