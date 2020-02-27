#include "mystdio.h"

Mystdio mystdio;

void setup() {
  Serial.begin(9600);
  mystdio.open(StreamIO::KEYPADIO);
  
  Serial.print("1");
}

void loop() {
  char c;
  mystdio.open(StreamIO::KEYPADIO);
  scanf("%c", &c);
  mystdio.open(StreamIO::LCDIO);
  printf("%c", c);
}