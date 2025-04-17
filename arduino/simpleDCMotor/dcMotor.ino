const int switchPin = A0;
const int motorPin = 5;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int switchState = digitalRead(switchPin);
  
  if(switchState == HIGH){
    digitalWrite(motorPin, 0);
    Serial.println("Switch OFF");
  } else {
    digitalWrite(motorPin, 200);
    Serial.println("Switch ON");
  }
  
  delay(200);
}