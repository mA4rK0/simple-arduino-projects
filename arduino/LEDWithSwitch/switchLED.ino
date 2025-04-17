const int switchPin = A3;
const int ledPin = 5;

void setup() {
  pinMode(switchPin, INPUT_PULLUP); // aktifkan pull-up
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int switchState = digitalRead(switchPin);

  if (switchState == LOW) {
    digitalWrite(ledPin, LOW);
    Serial.println("Switch OFF");
  } else {
    digitalWrite(ledPin, HIGH);
    Serial.println("Switch ON");
  }

  delay(200);
}