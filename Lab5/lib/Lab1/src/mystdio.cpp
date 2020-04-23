#include "mystdio.h"

String Mystdio::readStr() {
  char c;
  String str;
  do {
    scanf("%c", &c);
    if(c != 0 && c != '\r'){
      str.concat(c);
    }
  }while(c != '\r');

  return str;
}

void Mystdio::writeStr(String str) {
  for(int i = 0; i < str.length(); i++) {
    printf("%c", str[i]);
  }
}

static int Mystdio::putCharSerial(char c, FILE *stream)
{
    Serial.write(c) ;
    return 0 ;
}

static char Mystdio::getCharSerial(FILE *stream)
{
    char c;
    while(!Serial.available()) {}  
    c = Serial.read();
    printf("%c", c);  
    return c;
}


void Mystdio::open(StreamIO streamIo) {
  if(streamIo == SERIALIO) {
    f = fdevopen(Mystdio::putCharSerial, Mystdio::getCharSerial);
  } else if(streamIo == KEYPADIO) {

  } else if(streamIo == LCDIO) {
    
  }
  stdout = f;
  stdin = f;
}

Mystdio::Mystdio() {
  f = fdevopen(Mystdio::putCharSerial, Mystdio::getCharSerial);
  stdout = f;
  stdin = f;
}