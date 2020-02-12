#define LED_PIN 3

String command;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("LED is on"); 
}
