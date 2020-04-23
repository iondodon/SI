#include "Lab2.h"

#define ULTRASONIC_TRIG 3
#define ULTRASONIC_ECHO 2
#define DELAY_TIME 200

int *rawBuff = new int[3];
int *medianBuff = new int[3];

Mystdio mystdio;
Ultrasonic ultrasonic(ULTRASONIC_TRIG, ULTRASONIC_ECHO);

void Lab2::setup() 
{
  mystdio.open(StreamIO::SERIALIO);
  printf("6\r");

  medianBuff[0] = rawBuff[0] = ultrasonic.read();
  medianBuff[1] = rawBuff[1] = ultrasonic.read();
  medianBuff[2] = rawBuff[2] = ultrasonic.read();

  printf("Clean    Median      WAVG\r");
}

void Lab2::loop()
{
  int newDist = ultrasonic.read();

  pushTemp(rawBuff, newDist);

  calculateMedian(rawBuff, medianBuff);

  printf("%d    ", rawBuff[2]);
  printf("%d        ", medianBuff[2]);
  printf("%d\r", getWeighterAverage(medianBuff));

  delay(DELAY_TIME); 
}
