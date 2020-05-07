#pragma once
#include <Arduino.h>

class Ultrasonic{
    private:
    int pinTrigger, pinEcho;
    int distance;
    long duration;
    int microsecondsToCm(int);

    public:
    Ultrasonic(int pin1, int pin2);
    int getDistance();
};