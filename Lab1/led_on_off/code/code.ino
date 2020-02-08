void setup() {
  pinMode(4, INPUT_PULLUP);
  pinMode(7, OUTPUT);
}

void loop() {
    if(digitalRead(4) == LOW) {
      digitalWrite(7, HIGH);
    } else {
      digitalWrite(7, LOW);
    }
}
