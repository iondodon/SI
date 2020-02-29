#include <Arduino.h>
#include "mystdio.h"

void setup() {
    Serial.begin(9600);
    pinMode(10, OUTPUT);
}

void loop() {
    int sensorValue = analogRead(A0);
    Serial.println(sensorValue);

    if(sensorValue < 15) {
        digitalWrite(10, HIGH);
    } else {
        digitalWrite(10, LOW);
    }

    delay(1000);
}