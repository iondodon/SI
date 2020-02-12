#include "global.h"

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  command = Serial.readString();

  if(command.length()) {
    Serial.println(command);
    if(command == "led on") {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED is on");
    } else 
    if(command == "led off") {
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED is off");
    } 
  }
}
