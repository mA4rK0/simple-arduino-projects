#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Change the I2C address if necessary

const int trigPin = 2;
const int echoPin = 3;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0343 / 2;  // Speed of sound in cm/ms

  lcd.setCursor(0, 1); // Set the cursor to the second line
  lcd.print("            "); // Clear any previous distance value
  lcd.setCursor(0, 1); // Set the cursor to the second line
  lcd.print(distance);
  lcd.print(" cm");

  delay(500);  // Update the display every half second
}
