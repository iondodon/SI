#include "mystdio.h"

Mystdio keypadio;
Mystdio lcdio;

void setup() {
  Serial.begin(9600);
  keypadio.open(StreamIO::KEYPADIO);
  
  Serial.print("8");
}

void loop() {
  char c;
  scanf("%c", &c);
  lcdio.open(StreamIO::LCDIO);
  printf("%c", c);
}