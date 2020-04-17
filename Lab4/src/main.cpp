#include <Arduino.h>
#include "L298N.h"
#include "LAMP.h"
#include "LiquidCrystal.h"
#include "mystdio.h"
#include "DHT.h"
#include "PID_v1.h"

#define DHTPIN 2
#define DHTTYPE    DHT22

DHT dht(DHTPIN, DHT22);
L298N motor(A1, 6, 5);
LAMP lamp(7);
LiquidCrystal lcd(10);
Mystdio mystdio;

int humiditySetpoint;

//Define Variables we'll be connecting to
double Input, Output, motorSetpoint;
int msp;
//Specify the links and initial tuning parameters
double Kp=1, Ki=0, Kd=0;
PID myPID(&Input, &Output, &motorSetpoint, Kp, Ki, Kd, DIRECT);

void setup() {
  mystdio.open(StreamIO::SERIALIO);

  motor.setSpeed(200);
  motor.forward();

  lcd.begin(16, 2);
  printf("Started \r");

  lcd.clear();
  lcd.print("Reading setpoints");

  printf("Humidity setpoint: ");
  scanf("%d", &humiditySetpoint);
  // printf("Motor speed setpoint: ");
  // scanf("%d", &msp);
  // motorSetpoint = (double)msp;

  lcd.print("Started");

  //turn the PID on
  myPID.SetMode(AUTOMATIC);

  dht.begin();
}


void loop() {
  delay(1000);
  int humidity = dht.readHumidity();
  lcd.clear();
  lcd.print("hum:");
  lcd.print(humidity);
  lcd.print("sp:");
  lcd.print(humiditySetpoint);


  if(humidity > humiditySetpoint) {
    lamp.setOn();
  } else {
    lamp.setOff();
  }
}
