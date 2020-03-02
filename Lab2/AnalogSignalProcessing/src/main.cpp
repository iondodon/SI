#include <Arduino.h>
#include <LM35.h>
#include "mystdio.h"

#define pinoSensor 1 
#define DELAY_TIME 500 

Mystdio mystdio;
LM35Sensor lm35;

void setup() { 
    mystdio.open(StreamIO::SERIALIO);
    printf("%d\r", 1);
}

void loop() {
    lm35.read(pinoSensor);

    mystdio.printDouble(lm35.getCelsius());
    printf("\r");

    delay(DELAY_TIME); 
}