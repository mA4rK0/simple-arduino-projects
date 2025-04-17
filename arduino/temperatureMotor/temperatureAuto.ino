const int motorPin = 5;
const int tmpPin = A0;
float temperature;

void setup(){
  pinMode(motorPin, OUTPUT);
  pinMode(tmpPin, INPUT);
  Serial.begin(9600);
}

void loop(){
  int analogValue = analogRead(tmpPin);
  float volt = analogValue * (5.0 / 1023.0);
  temperature = (volt - 0.5) * 100;
  
  if(temperature >= 30){
    analogWrite(motorPin, 400);
  } else {
    analogWrite(motorPin, 0);
  }
  
  Serial.print("temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  delay(1000);
}