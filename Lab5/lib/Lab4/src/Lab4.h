#ifndef LAB4_H
#define LAB4_H

#include <Arduino.h>
#include "L298N.h"
#include "LAMP.h"
#include "LiquidCrystal.h"
#include "mystdio.h"
#include "DHT.h"
#include "PID_v1.h"

class Lab4 {
    public:
        Lab4(void);
        void setup(void);
        void loop(void);
}

#endif