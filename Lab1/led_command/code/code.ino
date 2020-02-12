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
      c = Serial.read() ;     
    }
    return c;
}

void setup() {
  Serial.begin(9600) ;
  
  f = fdevopen(putChar, getChar);
  stdout = f;
  stdin = f;

  printf("Alive %d sec\n", 20 ) ;
  char c;
  scanf("%c", &c);
}

void loop() {
  
}
