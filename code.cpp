#include <Servo.h>
Servo myServo;
const int trigPin = 5;
const int echoPin = 6;
const int buttonPin = 7;  // Button pin
long duration;
int distance;
bool buttonState = 0;

void setup() {
  myServo.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT); 
  myServo.write(0);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) { 
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;

    if (distance <= 30) {
      myServo.write(90);
      delay(3000);
      myServo.write(0);
    }
  }
  delay(500);
}


