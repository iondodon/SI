#include <Arduino.h>
#include "L298N.h"
#include "LAMP.h"
#include "LiquidCrystal.h"
#include "mystdio.h"
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE    DHT22

DHT dht(DHTPIN, DHT22);
L298N motor(A1, 6, 5);
LAMP lamp(7);
LiquidCrystal lcd(10);
Mystdio mystdio;

void setup() {
  mystdio.open(StreamIO::SERIALIO);

  motor.setSpeed(200);
  motor.forward();

  lcd.begin(16, 2);
  printf("Started \r");
  lcd.print("Started");

  dht.begin();
}

void setMotorSpped() {
  lcd.clear();

  printf("speed (percent): ");
  int percent;
  scanf("%d", &percent);

  lcd.print("Motor speed: ");
  lcd.print(percent);
  delay(3000);
  lcd.clear();

  motor.speedUpByPercent(percent);
}

void setLamp() {
  printf("on/off?: ");
  int on;
  scanf("%d", &on);
  lcd.clear();
  if(on) {
    lamp.setOn();
    lcd.print("Lamp is on");
  } else {
    lamp.setOff();
    lcd.print("Lamp is off");
  }
  delay(3000);
  lcd.clear();
}

void loop() {
  delay(1000);
  int RH = dht.readHumidity();
  int temperature = dht.readTemperature();
  printf("%d, %d\r", RH, temperature);
  
  String cmd = mystdio.readStr();
  if(cmd == "motor_speed:") {
    setMotorSpped();      
  } else if(cmd == "set_lamp:") {
    setLamp();
  }
}
