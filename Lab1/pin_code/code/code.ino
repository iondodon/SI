#include<Keypad.h>
#include <SPI.h>
#include<LiquidCrystal.h>

#define LED_RED 1
#define LED_GREEN 0
  
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

int i = 0;
char arr[10];

int secret_code = 1234;
int inserted_code = 0;

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
LiquidCrystal lcd(10);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);
  // Print a message to the LCD.}
  // lcd.cursor();
}

void loop() {
  char key = keypad.getKey();

  if(key) {
    if(key == 61) {
      lcd.setCursor(1, 1);
      if(inserted_code == secret_code) {
        lcd.print("Correct");
        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_RED, LOW);
      } else {
        lcd.print("Incorrect");
        digitalWrite(LED_GREEN, LOW);
        digitalWrite(LED_RED, HIGH);
      }
      lcd.display();
      delay(1000);
      lcd.clear();
      inserted_code = 0;
    } else if(key >= 48 && key <= 57 && inserted_code * 10 < 9999) {
      inserted_code = inserted_code * 10 + (key - 48);
      lcd.setCursor(1, 1);
      lcd.print(String(inserted_code));
      lcd.display(); 
    }
  }
}
