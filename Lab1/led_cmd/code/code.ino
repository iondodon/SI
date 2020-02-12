#include "global.h"
#include <stdio.h>

static FILE *f;

static int putChar(char c, FILE *stream)
{
    Serial.write(c) ;
    return 0 ;
}

static char getChar(FILE *stream)
{
    char c;
    while(!Serial.available()) {  
       c = Serial.read();
    }
    return c;
}

char c;

void setup() {
  Serial.begin(9600) ;
  
  f = fdevopen(putChar, getChar);
  stdout = f;
  stdin = f;

  printf("aaa\n");
  printf("1");
}

void loop() {
  scanf("%c", &c);
  printf("%c", c);
}
