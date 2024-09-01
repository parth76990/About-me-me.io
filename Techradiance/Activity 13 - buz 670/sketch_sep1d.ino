
const int buzzerPin = 8;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  analogWrite(buzzerPin, 255);  
  delay(1000);  
  analogWrite(buzzerPin, 128); 
  delay(1000);  
  analogWrite(buzzerPin, 0);  
  delay(1000); 
  while(1);
}
