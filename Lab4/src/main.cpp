#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 2

#define DHTTYPE    DHT22
DHT dht(DHTPIN, DHT22);

void setup() {
  Serial.begin(9600);

  dht.begin();
}

void loop() {
  delay(1000);

  int RH = dht.readHumidity();
  int temp = dht.readTemperature();

  Serial.println(temp);
  Serial.println(RH);
}