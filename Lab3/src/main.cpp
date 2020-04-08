#include <Arduino.h>
#include "L298N.h"
#include "LAMP.h"

L298N motor(A1, 11, 10);
LAMP lamp;


void setup() {
  Serial.begin(9600);
}


void loop() {
  lamp.setOn();
  delay(3000);
  lamp.setOff();
  delay(3000);
}