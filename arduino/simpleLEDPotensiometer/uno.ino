int potPin = A0;     // pin potensiometer
int ledPin = 9;      // pin LED
int potValue = 0;    // nilai dari potensiometer
int ledValue = 0;    // nilai PWM untuk LED

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);  // untuk debug nilai
}

void loop() {
  potValue = analogRead(potPin);        // baca nilai 0–1023
  ledValue = map(potValue, 0, 1023, 0, 255); // ubah ke 0–255
  analogWrite(ledPin, ledValue);        // atur kecerahan LED
  Serial.println(ledValue);             // debug
  delay(100);
}
