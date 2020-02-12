#include "global.h"

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
