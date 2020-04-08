#include <Arduino.h>
#include "L298N.h"
#include "LAMP.h"
#include "LiquidCrystal.h"

L298N motor(A1, 6, 5);
LAMP lamp(7);
LiquidCrystal lcd(10);


void setup() {
  Serial.begin(9600);

  motor.setSpeed(200);
  motor.backward();

  lcd.begin(16, 2);
  lcd.print("Started");
}


void loop() {
  lamp.setOn();
  delay(3000);
  lamp.setOff();
  delay(3000);
}