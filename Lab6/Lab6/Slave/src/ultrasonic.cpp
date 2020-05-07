#include "../include/ultrasonic.h"
#include "../include/Lab1/conts.h"

Ultrasonic::Ultrasonic(int pin1, int pin2){
    this->pinTrigger = pin1;
    this->pinEcho = pin2;

    pinMode(pin1, OUTPUT);
    pinMode(pin2, INPUT);
}

int Ultrasonic::microsecondsToCm(int microseconds){
    return microseconds / 29 / 2;
}

int Ultrasonic::getDistance(){
    digitalWrite(this->pinTrigger, LOW);
    delayMicroseconds(2);
    digitalWrite(this->pinTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->pinTrigger, LOW);

    this->duration = pulseIn(this->pinEcho, HIGH);
    this->distance = this->microsecondsToCm(this->duration);
    return this->distance;
}