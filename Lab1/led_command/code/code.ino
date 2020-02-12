#include "global.h"
#include <stdio.h>

static FILE uartout = {0} ;

// create a output function
// This works because Serial.write, although of
// type virtual, already exists.
static int uart_putchar (char c, FILE *stream)
{
    Serial.write(c) ;
    return 0 ;
}



void setup() {
  pinMode(LED_PIN, OUTPUT);

  // Start the UART
   Serial.begin(115200) ;

   // fill in the UART file descriptor with pointer to writer.
   fdev_setup_stream (&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);

    // The uart is the standard output device STDOUT.
   stdout = &uartout ;

   printf("Alive %d sec\n", 20 ) ;

//   #if 0
//    // you can explicitly use a FILE structure like this:
//    fprintf( &uartout, "Alive %d sec", 10 ) ;
//   #endif
}

void loop() {
//  String command = Serial.readString();
//
//  if(command.length()) {
//    Serial.println(command);
//    if(command == "led on") {
//      digitalWrite(LED_PIN, HIGH);
//      Serial.println("LED is on");
//    } else 
//    if(command == "led off") {
//      digitalWrite(LED_PIN, LOW);
//      Serial.println("LED is off");
//    } 
//  }

//  printf("%d\n", 10);
}
