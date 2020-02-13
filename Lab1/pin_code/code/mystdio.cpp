#include "mystdio.h"

static int Mystdio::putChar(char c, FILE *stream)
{
    Serial.write(c) ;
    return 0 ;
}

static char Mystdio::getChar(FILE *stream)
{
    char c;
    while(Serial.available()) {  
       c = Serial.read();
       printf("%c", c);  
    }
    return c;
}

String Mystdio::readStr() {
  char c;
  String str;
  do {
    scanf("%c", &c);
    if(c != 0 && c != '\r'){
      str.concat(c);
    }
  }while(c!= '\r');

  return str;
}

void Mystdio::writeStr(String str) {
  for(int i = 0; i < str.length(); i++) {
    printf("%c", str[i]);
  }
}

Mystdio::Mystdio() {
  f = fdevopen(Mystdio::putChar, Mystdio::getChar);
  stdout = f;
  stdin = f;
}
