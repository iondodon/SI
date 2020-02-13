#include <stdio.h>
#include <Arduino.h>
#include "mystdio.h"

#define LED_PIN 12

Mystdio io;
char c;

void setup() {
  Serial.begin(9600);

  printf("1\r");
}

void loop() {
  
}
