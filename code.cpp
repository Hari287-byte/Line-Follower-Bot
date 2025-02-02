#include <Ultrasonic.h>

// Motor pins
const int motor1Pin1 = 2;
const int motor1Pin2 = 3;
const int motor2Pin1 = 4;
const int motor2Pin2 = 5;

// IR sensor pins
const int irSensorLeft = A0;
const int irSensorRight = A1;

// Ultrasonic sensor pins
const int trigPin = 8;
const int echoPin = 9;

// Ultrasonic object detection threshold (in cm)
const int objectThreshold = 20;

Ultrasonic ultrasonic(trigPin, echoPin);

void setup() {
  // Set motor pins as output
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  // Set IR sensor pins as input
  pinMode(irSensorLeft, INPUT);
  pinMode(irSensorRight, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Read IR sensor values
  int leftValue = digitalRead(irSensorLeft);
  int rightValue = digitalRead(irSensorRight);

  // Read distance from ultrasonic sensor
  int distance = ultrasonic.Ranging(CM);
  
  if (distance < objectThreshold) {
    // Stop the bot if an object is detected within threshold distance
    stop();
  } else {
    // Move based on IR sensor values
    if (leftValue == LOW && rightValue == LOW) {
      // Move forward
      forward();
    } else if (leftValue == LOW && rightValue == HIGH) {
      // Turn left
      turnLeft();
    } else if (leftValue == HIGH && rightValue == LOW) {
      // Turn right
      turnRight();
    } else {
      // Stop
      stop();
    }
  }
}

void forward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void turnLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void stop() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
