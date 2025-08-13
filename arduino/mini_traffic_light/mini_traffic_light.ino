#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int trigPin = 2;
const int echoPin = 3;

float lastCM = 0;
float lastINCH = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  
  // Scanner I2C (sekali saja)
  Serial.println("Scanning I2C addresses...");
  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("Device found at 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  Serial.println("Scan complete!");

  lcd.init();
  lcd.backlight();
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  lcd.setCursor(0, 0);
  lcd.print("Digital Ruler");
  lcd.setCursor(0, 1);
  lcd.print("Loading...");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("CM: ");
  lcd.setCursor(0, 1); lcd.print("IN: ");
}

void loop() {
  // Generate pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distanceCM = duration * 0.034 / 2;
  float distanceINCH = distanceCM / 2.54;

  // Debug ke Serial Monitor
  Serial.print("Duration: ");
  Serial.print(duration);
  Serial.print(" μs | Distance: ");
  Serial.print(distanceCM);
  Serial.print(" cm | ");
  Serial.print(distanceINCH);
  Serial.println(" inches");

  // Update LCD hanya jika perubahan > 0.5 cm
  if (abs(distanceCM - lastCM) > 0.5) {
    lcd.setCursor(4, 0);
    lcd.print(distanceCM, 1);
    lcd.print("     "); // hapus sisa angka lama
    lastCM = distanceCM;
  }

  if (abs(distanceINCH - lastINCH) > 0.2) {
    lcd.setCursor(4, 1);
    lcd.print(distanceINCH, 1);
    lcd.print("     ");
    lastINCH = distanceINCH;
  }

  // Status
  lcd.setCursor(10, 0);
  if (distanceCM < 10) {
    lcd.print("Dekat ");
  } else if (distanceCM < 50) {
    lcd.print("Sedang");
  } else {
    lcd.print("Jauh  ");
  }

  delay(50);
}
