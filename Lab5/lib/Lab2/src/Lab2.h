#ifndef LAB2_H
#define LAB2_H

#include <Arduino.h>
#include "Ultrasonic.h"
#include "mystdio.h"
#include "filters.h"

class Lab2 {
    public:
        Lab2(void);
        void setup(void);
        void loop(void);
}

#endif