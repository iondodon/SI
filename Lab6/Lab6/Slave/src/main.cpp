#include "../include/Lab1/libs.h"
#include "../include/Lab1/conts.h"

Lcd *lcd;
MySerial *serial;
Ultrasonic *ultrasonic;
Led *led;

DynamicJsonDocument doc(1024);

int distance;
char distArray[5];
const char* command;
String request = "";
int checksum;
bool isValid = false;
char response[10];
int receiverId = 9;
int address = 4;

void checkCommand();
void validatePacket();

void setup() {
  lcd = new Lcd(lcdPinOne, lcdPinTwo, lcdPinThree, lcdPinFour, lcdPinFive, lcdPinSix);
  ultrasonic = new Ultrasonic(ultrasonicTrigger, ultrasonicEcho);
  serial = new MySerial();
  led = new Led(ledPin);

  Wire.begin();
  lcd->openStream();
}

void loop() {
  lcd->setCursorLCD(0,0);
  if(serial->hasMessage()){
    delay(500);
    while(serial->hasMessage()){
      char c = Serial.read();
      request += c;
    }

    validatePacket();

    delay(200);
      printf("Result");
      lcd->setCursorLCD(0,1);
      printf("%s", command);

      delay(400);
      lcd->setCursorLCD(0,1);
      printf("                ");

      checkCommand();
  }
  request = "";
  command = "";
  delay(100);
}

void validatePacket(){
  if(request.charAt(0) == '{' && request.charAt(request.length() - 1) == '}'){
      deserializeJson(doc, request );
      const char* startPacket = doc["start"];
      const char* endPacket = doc["end"];
      if(strcmp(startPacket, "STX") == 0 ){
        command = doc["data"];
        checksum = doc["cksum"];
        int sizeOfCommand = strlen(command) + 2;
        if(checksum / 2 == sizeOfCommand){
          isValid = true;
        }
      }
    }
}

void checkCommand(){

      if(strncmp(command, "get_data", 9) == 0){
       
        Serial.write("value distance:");

        distance = ultrasonic->getDistance();
        sprintf(distArray, "%d", distance);
        Wire.beginTransmission(mcu2Address);
        Wire.write(distArray);
        Wire.endTransmission();
        
      } else if(strncmp(command, "blink_led", 10) == 0){
        strcpy(response, "led on");

        Serial.write("led on");

        led->blink(500);
      }
}