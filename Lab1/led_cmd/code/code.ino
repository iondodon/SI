#include <stdio.h>
#include "mystdio.h"

#define LED_PIN 12
static FILE *f;

static int putChar(char c, FILE *stream)
{
    Serial.write(c) ;
    return 0 ;
}

static char getChar(FILE *stream)
{
    char c;
    while(Serial.available()) {  
       c = Serial.read();
       printf("%c", c);  
    }
    return c;
}

String readString() {
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

void writeString(String str) {
  for(int i = 0; i < str.length(); i++) {
    printf("%c", str[i]);
  }
}

void setup() {
  Serial.begin(9600) ;
  
  f = fdevopen(putChar, getChar);
  stdout = f;
  stdin = f;

  printf("3\r");
}

void loop() {
  String str = readString();
  writeString(str);
}
