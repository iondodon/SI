#include "../include/Lab1/myStdio.h"
#include "../include/Lab1/myKeypad.h"

Stream *stream;
Print *print;
MyKeypad *keypad;

int myPutchar(char c, FILE* fd) {
    print->write(c);
    return 1;
}

int myGetchar(FILE *fd) {
    while (!stream->available());
    int c = stream->read();
    stream->write(c);
    return c;
}

int myKeypadGetchar(FILE *fd) {
    return keypad->getKey();
}

FILE *myStdioOpen(Stream *s) {
    stream = s;
    print = s;
    keypad = NULL;
    return fdevopen(&myPutchar, &myGetchar);
}

FILE *myStdioOpen(Print *p) {
    stream = NULL;
    print = p;
    keypad = NULL;
    return fdevopen(&myPutchar, NULL);
}

FILE *myStdioOpen(MyKeypad *k) {
    stream = NULL;
    print = NULL;
    keypad = k;
    return fdevopen(NULL, &myKeypadGetchar);
}