const int redPin = 2;
const int greenPin = 3;
const int yellowPin = 4;

const int DELAY = 5000;
const int DELAY_YELLOW = 3000;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600); 
  Serial.println("Go");

  allOff();
}

void loop() {
  Serial.println("red on");
  toggleLED(redPin, DELAY);
  Serial.println("red off");
  Serial.println("green on");
  toggleLED(greenPin, DELAY);
  Serial.println("green off");
  Serial.println("yellow on");
  toggleLED(yellowPin, DELAY_YELLOW);
  Serial.println("yellow off");
}

void toggleLED(int led_pin, int led_delay) {
  digitalWrite(led_pin, HIGH);
  delay(led_delay);
  digitalWrite(led_pin, LOW);
}

void allOff() {
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
}
