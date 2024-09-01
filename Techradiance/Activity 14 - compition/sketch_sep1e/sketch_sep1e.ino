// Define pin numbers
int ledPin = 13;    // LED connected to digital pin 13
int buzzerPin = 12;

void setup() {
  // Initialize the LED and Buzzer pins as output
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(2000);

  // Turn off the LED
  digitalWrite(ledPin, LOW);

  // Turn on the buzzer for 1 second
  digitalWrite(buzzerPin, HIGH);
  delay(1000);

  // Turn off the buzzer
  digitalWrite(buzzerPin, LOW);

  // Add a delay before the next loop iteration if needed
  delay(1000); // Optional: Wait for 1 second before starting again
}
