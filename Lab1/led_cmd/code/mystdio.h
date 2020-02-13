#ifndef HEADER_FILE
#define HEADER_FILE

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
