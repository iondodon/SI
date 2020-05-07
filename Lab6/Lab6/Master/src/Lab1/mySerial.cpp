#include "../include/Lab1/mySerial.h"
#include "../include/Lab1/myStdio.h"
#include <Arduino.h>

MySerial::MySerial() {
    Serial.begin(9600);
}

void MySerial::openStream() {
    FILE *fd = myStdioOpen(&Serial);
    stdout = fd;
    stdin = fd;
}

int MySerial::hasMessage() {
    return Serial.available();
}