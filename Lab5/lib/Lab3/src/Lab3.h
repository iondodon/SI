#ifndef LAB3_H
#define LAB3_H

#include <Arduino.h>
#include "L298N.h"
#include "LAMP.h"
#include "LiquidCrystal.h"
#include "mystdio.h"


class Lab3 {
    public:
        Lab3(void);
        void setup(void);
        void loop(void);
}

#endif