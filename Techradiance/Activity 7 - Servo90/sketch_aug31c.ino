#include <Servo.h>

// Define the pins for the ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

// Define the pins for the servo motors
Servo leftArmServo; // Left arm
Servo rightArmServo; // Right arm
const int leftArmPin = 3;
const int rightArmPin = 5;

// Function to measure distance using the ultrasonic sensor
long measureDistance() {
  // Send a 10us pulse to trigger the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time for the echo to return
  long duration = pulseIn(echoPin, HIGH);

  // Convert time to distance
  long distance = duration * 0.034 / 2;

  return distance;
}

void setup() {
  // Initialize the servo motors
  leftArmServo.attach(leftArmPin);
  rightArmServo.attach(rightArmPin);

  // Initialize the ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Start the serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Measure the distance to an object in front of the robot
  long distance = measureDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Example: Move arms based on distance
  if (distance < 20) {
    // If an object is detected within 20 cm, raise the arms
    leftArmServo.write(90);  // Move left arm to 90 degrees
    rightArmServo.write(90); // Move right arm to 90 degrees
  } else {
    // Otherwise, lower the arms
    leftArmServo.write(0);   // Move left arm to 0 degrees
    rightArmServo.write(0);  // Move right arm to 0 degrees
  }

  // Add a delay to avoid rapid movements
  delay(500);
}
