#include "button.h"
#include "led.h"

Button *btn;
Led *led;

void setup() {
  btn = new Button(4);
  led = new Led(7);
}

void loop() {
    if(bth->pressed()) {
      led->turnOn();
    } else {
      led->turnOff();
    }
}
