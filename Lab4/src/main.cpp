#include <Arduino.h>
#include "L298N.h"
#include "LAMP.h"
#include "LiquidCrystal.h"
#include "mystdio.h"
#include "DHT.h"
#include "Encoder.h"

#define DHTPIN 2
#define DHTTYPE    DHT22

int temperatureSetpoint;

DHT dht(DHTPIN, DHT22);
L298N motor(A1, 6, 5);
LAMP lamp(7);
LiquidCrystal lcd(10);
Mystdio mystdio;

Encoder myEnc(4, 3);

void setup() {
  mystdio.open(StreamIO::SERIALIO);

  motor.setSpeed(200);
  motor.forward();

  lcd.begin(16, 2);
  printf("Started \r");

  lcd.clear();
  lcd.print("Reading setpoints");

  printf("Temperature setpoint: ");
  scanf("%d", &temperatureSetpoint);

  lcd.print("Started");

  dht.begin();
}

void loop() {
  delay(1000);
  int temperature = dht.readTemperature();
  lcd.clear();
  lcd.print("temp:");
  lcd.print(temperature);
  lcd.print("sp:");
  lcd.print(temperatureSetpoint);

  long newPosition = myEnc.read();
  printf("%ld\r", newPosition);

  if(temperature > temperatureSetpoint) {
    lamp.setOn();
  } else {
    lamp.setOff();
  }
}
