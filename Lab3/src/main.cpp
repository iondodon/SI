#include <Arduino.h>
#include "L298N.h"
#include "LAMP.h"
#include "LiquidCrystal.h"
#include "mystdio.h"

L298N motor(A1, 6, 5);
LAMP lamp(7);
LiquidCrystal lcd(10);
Mystdio mystdio;


void setup() {
  mystdio.open(StreamIO::SERIALIO);

  motor.setSpeed(200);
  motor.backward();

  lcd.begin(16, 2);
  printf("Started");
  lcd.print("Started");
}


void loop() {
  lamp.setOn();
  delay(3000);
  lamp.setOff();
  delay(3000);
}