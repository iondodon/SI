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

char str[10];

void readString() {
  char c;
  int i = 0;
  do {
    scanf("%c", &c);
    if(c != 0 && c != '\r'){
      str[i] = c;
      i = i + 1;
    }
  }while(c!= '\r');

  printf("%c", str[0]);
}

void setup() {
  Serial.begin(9600) ;
  
  f = fdevopen(putChar, getChar);
  stdout = f;
  stdin = f;

  printf("7\r");
}

void loop() {
  readString();
}
