#ifndef MYSTDIO_HEADER
#define MYSTDIO_HEADER

#include <stdio.h>
#include <Arduino.h>
#include <Keypad.h>

static FILE *f;

enum StreamIO { SERIALIO, KEYPADIO, LCDIO };

class Mystdio {
  private:
    static int putCharSerial(char c, FILE *stream);
    static char getCharSerial(FILE *stream);
    static int putCharKeypad(char c, FILE *stream);
    static char getCharKeypad(FILE *stream);

  public:
    Mystdio(StreamIO streamIO);
    String readStr();
    void writeStr(String str);
    void open(StreamIO streamIo);
};

#endif