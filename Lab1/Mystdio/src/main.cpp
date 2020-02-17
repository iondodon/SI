#include "mystdio.h"

Mystdio lcdio(StreamIO::SERIALIO);

void setup() {
  Serial.begin(9600);
  lcdio.open(StreamIO::LCDIO);
}

void loop() {
  // if(key) {
  //   Serial.print(key);
  // }
}