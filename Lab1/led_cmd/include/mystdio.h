#ifndef MUSTDIO_HEADER
#define MUSTDIO_HEADER

#include <stdio.h>
#include <Arduino.h>

static FILE *f;

enum StreamIO { SERIALIO, KEYPADIO, LCDIO };

class Mystdio {
  private:
    static int putCharSerial(char c, FILE *stream);
    static char getCharSerial(FILE *stream);



  public:
    Mystdio();
    String readStr();
    void writeStr(String str);
    void open(StreamIO streamIo);
};

#endif