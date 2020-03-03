#include <Arduino.h>
#include <LM35.h>
#include "mystdio.h"
#include "filters.h"

#define pinoSensor 1
#define DELAY_TIME 200

Mystdio mystdio;
LM35Sensor lm35;
double *rawBuff = new double[3];
double *medianBuff = new double[3];

void setup() { 
    mystdio.open(StreamIO::SERIALIO);
    printf("%d\r", 3);

    medianBuff[0] = rawBuff[0] = lm35.getCelsius();
    medianBuff[1] = rawBuff[1] = lm35.getCelsius();
    medianBuff[2] = rawBuff[2] = lm35.getCelsius();

    printf("Clean    Median      WAVG\r");
}

void loop() {
    lm35.read(pinoSensor);
    double newTemp = lm35.getCelsius();

    pushTemp(rawBuff, newTemp);

    calculateMedian(rawBuff, medianBuff);

    mystdio.printDouble(rawBuff[2]);
    printf("    ");
    mystdio.printDouble(medianBuff[2]);
    printf("        ");
    mystdio.printDouble(getWeighterAverage(medianBuff));
    printf("\r");

    delay(DELAY_TIME); 
}