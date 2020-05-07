#include "../include/Lab1/libs.h"
#include "../include/Lab1/conts.h"

Lcd *lcd;
MySerial *serial;
StaticJsonDocument<200> packet;

int distance;
char receive[5];
int nr = 1;
int receiverId = 4;
char command[10];
char request[100];
int x = 0;

void receiveEvent(int);

void setup() {
  lcd = new Lcd(lcdPinOne, lcdPinTwo, lcdPinThree, lcdPinFour, lcdPinFive, lcdPinSix);
  serial = new MySerial();

  Wire.begin(address);
  Wire.onReceive(receiveEvent);
  lcd->openStream();
}

void loop() {
  delay(500);

  if(x % 3 == 0){
    strcpy(command, "blink_led");
  } else {
    strcpy(command, "get_data");
  }
  int size = sizeof(command);
  int checksum = size * 2;

  packet["start"] = "STX";
  packet["pkID"] = nr++;
  packet["data"] = command;
  packet["cksum"] = checksum;

  serializeJson(packet, Serial);

  memset(command, 0, sizeof(command));

  delay(500);
  if(serial->hasMessage()){
    delay(100);
    int i = 0;
    while(serial->hasMessage()){
      char c = Serial.read();
      request[i] = c;
      i++;
    }
  }

  if(strncmp(request, "dist", 4) == 0){
  } else if (strcmp(request, "blink") == 0){
    lcd->setCursorLCD(0,0);
    printf("%s", request);
  }

  delay(200);
  memset(request, 0, sizeof(request));
  memset(receive, 0, sizeof(receive));
  x++;
  lcd->clearScreen();
}

void receiveEvent(int bytes){
  int i = 0;
  while(Wire.available()){
    receive[i] = Wire.read(); 
    i++;
  }
   lcd->setCursorLCD(0,0);
    printf("Result value:");
    lcd->setCursorLCD(0,1);
    printf("%s", receive);
}