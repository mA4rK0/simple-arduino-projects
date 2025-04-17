const int photoresistorPin = A0;
const int ledPin = 5;
const int ambangGelap = 341;

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int ldrValue = analogRead(photoresistorPin);
  Serial.println(ldrValue);
  
  if (ldrValue < ambangGelap) {
    digitalWrite(ledPin, HIGH); 
  } else {
    digitalWrite(ledPin, LOW); 
  }

  delay(200);
}