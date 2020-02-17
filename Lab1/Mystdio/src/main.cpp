#include "mystdio.h"

Mystdio lcdio(StreamIO::SERIALIO);

void setup() {
  Serial.begin(9600);
  lcdio.open(StreamIO::KEYPADIO);
  
  Serial.print("1");
  char c;
  scanf("%c", &c);
  Serial.print(c);
}

void loop() {

}