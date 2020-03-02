#include <Arduino.h>
#include <LM35.h>
#include "mystdio.h"

#define pinoSensor 1 
#define DELAY_TIME 200 

Mystdio mystdio;
LM35Sensor lm35;
double rawBuff[3];
double medianBuff[3];

void pushTemp(double arr[3], double newTemp) {
    arr[0] = arr[1];
    arr[1] = arr[2];
    arr[2] = newTemp;
}

void swap(double &a, double &b) {
    double c = a;
    a = b;
    b = c;
}

void sortArr(double arr[3]) {
    if(arr[0] > arr[1]) swap(arr[0], arr[1]);
    if(arr[1] > arr[2]) swap(arr[1], arr[2]);
    if(arr[0] > arr[1]) swap(arr[0], arr[1]);
}

void calculateMedian() {
    sortArr(rawBuff);
    pushTemp(medianBuff, rawBuff[1]);
}

double getWeighterAverage() {
    sortArr(medianBuff);
    return medianBuff[2];
}

void setup() { 
    mystdio.open(StreamIO::SERIALIO);
    printf("%d\r", 6);

    rawBuff[0] = lm35.getCelsius();
    rawBuff[1] = lm35.getCelsius();
    rawBuff[2] = lm35.getCelsius();

    medianBuff[0] = rawBuff[0];
    medianBuff[1] = rawBuff[1];
    medianBuff[2] = rawBuff[2];
}

void loop() {
    lm35.read(pinoSensor);
    double newTemp = lm35.getCelsius();
    pushTemp(rawBuff, newTemp);
    calculateMedian();

    mystdio.printDouble(rawBuff[2]);
    printf("    ");
    mystdio.printDouble(medianBuff[2]);
    printf("    ");
    mystdio.printDouble(getWeighterAverage());
    printf("\r");

    delay(DELAY_TIME); 
}