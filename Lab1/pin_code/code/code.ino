#include<Keypad.h>
#include<LiquidCrystal.h>

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 1, d7 = 0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns

const bytes = {
  {'7', '8', '9', '/'},
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'c', '0', '=', '+'}
}

byte rowPins[ROWS] = {2, 3, 4, 5} // connect to rows pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9} // connect to column pinouts of the keypad

int i = 0;
char arr[10];

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.}
  // lcd.cursor();
}

void loop() {
  char key = keypad.getKey();

  if(key) {
    lcd.setCursor(1, 1);
    lcd.print("   ROBOTICS");
    lcd.display();
    lcd.scrollDisplayRight();
  }
}
