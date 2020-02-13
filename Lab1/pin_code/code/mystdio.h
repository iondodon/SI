#ifndef MUSTDIO_HEADER
#define MUSTDIO_HEADER

#include <stdio.h>
#include <Arduino.h>

static FILE *f;

class Mystdio {
  public:
    Mystdio();
    String readStr();
    void writeStr(String str);
    static int putChar(char c, FILE *stream);
    static char getChar(FILE *stream);
};

#endif
