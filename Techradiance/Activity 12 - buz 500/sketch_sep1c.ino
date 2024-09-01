#include <Servo.h>

// Servo objects
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// Ultrasonic sensor pins
const int trigPin = 8;
const int echoPin = 9;

// Variables for distance measurement
long duration;
int distance;

void setup() {
  // Attach servos to pins
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);

  // Set ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initial position
  moveLegsToInitialPosition();
}

void loop() {
  // Measure distance
  distance = getDistance();

  // If obstacle is closer than 10 cm, stop
  if (distance < 10) {
    stopMoving();
  } else {
    walkForward();
  }

  delay(10); // Small delay for smooth movement
}

void moveLegsToInitialPosition() {
  // Move servos to a neutral position
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);
}

void walkForward() {
  // Move servos in sequence to walk forward
  servo1.write(90);
  servo3.write(90);
  delay(500);
  servo2.write(120);
  servo4.write(120);
  delay(0);

  // Return to the initial position
  moveLegsToInitialPosition();
}

void stopMoving() {
  // Stop all servos
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);
}

int getDistance() {
  // Send a pulse to the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the pulse duration
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  distance = duration * 0.034 / 2;

  return distance;
}
