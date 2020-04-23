#include "Lab1.h"

Mystdio io;
Ledd *ledd = new Ledd(12);

void Lab1::setup() {
  Serial.begin(19200);
  printf("3\r");
}

void Lab1::loop() {
  String command = io.readStr();
  
  if(command.length()) { 
    if(command == "led on") { 
      ledd->turnOn();
      printf("LED is on\r"); 
    } else  
    if(command == "led off") {
      ledd->turnOff();
      printf("LED is off\r"); 
    }
  }
}