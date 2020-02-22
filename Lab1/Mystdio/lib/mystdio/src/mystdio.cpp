#include "mystdio.h"

const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns

char keys[ROWS][COLS] = {
  {'7', '8', '9', '/'},
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'c', '0', '=', '+'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; // connect to rows pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; // connect to column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
LiquidCrystal lcd(10);

String Mystdio::readStr() {
  char c;
  String str;
  do {
    scanf("%c", &c);
    if(c != 0 && c != '\r'){
      str.concat(c);
    }
  }while(c != '\r');

  return str;
}

void Mystdio::writeStr(String str) {
  for(int i = 0; i < str.length(); i++) {
    printf("%c", str[i]);
  }
}

static int Mystdio::putCharSerial(char c, FILE *stream)
{
    Serial.write(c) ;
    return 0 ;
}

static char Mystdio::getCharSerial(FILE *stream)
{
    char c;
    while(!Serial.available()) {}  
    c = Serial.read();
    printf("%c", c);  
    return c;
}

static int Mystdio::putCharKeypad(char c, FILE *stream) {
  Serial.println("Keypad can't write.");
  return 0;
}

static char Mystdio::getCharKeypad(FILE *stream) {
  char c;

  do {
    c = 0;
    c = keypad.getKey();
  } while(c == 0);

  return c;
}

static int Mystdio::putCharLcd(char c, FILE *stream) {
  lcd.print(c);
  return 0;
}

static char Mystdio::getCharLcd(FILE *stream) {
  Serial.println("Lcd can't read.");
  return 0;
}

void Mystdio::open(StreamIO streamIO) {
  if(streamIO == SERIALIO) {
    f = fdevopen(Mystdio::putCharSerial, Mystdio::getCharSerial);
  } else if(streamIO == StreamIO::KEYPADIO) {
    f = fdevopen(Mystdio::putCharKeypad, Mystdio::getCharKeypad);
  } else if(streamIO == StreamIO::LCDIO) {
     f = fdevopen(Mystdio::putCharLcd, Mystdio::getCharLcd);
  }
  stdout = f;
  stdin = f;
}

Mystdio::Mystdio() {
  
}