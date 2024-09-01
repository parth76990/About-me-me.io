#include <Servo.h>

Servo lefttop, righttop, leftbottom, rightbottom;
int pos = 60;
int trigPin = 8;
int echoPin = 9;
int buz= 13;

void setup() {
  lefttop.attach(2);
  leftbottom.attach(3);
  righttop.attach(4);
  rightbottom.attach(5); // Corrected the servo name and pin number
  pinMode (trigPin, OUTPUT) ;
  pinMode (echoPin, INPUT) ;
  pinMode (buz, OUTPUT);
  Serial.begin (9600) ;
digitalWrite(buz, LOW) ;
}

void loop() {
  lefttop.write(pos);
  leftbottom.write(pos);
  righttop.write(pos);
  rightbottom.write(pos); // Adjusted to correct the foot angle
  digitalWrite(trigPin, LOW) ;
  delayMicroseconds (4);
  digitalWrite(trigPin, HIGH) ;
  delayMicroseconds (10);
  digitalWrite(trigPin, LOW) ;
  long t = pulseIn (echoPin, HIGH);
  long inches = t / 74 /2;
  long cm = t / 29 / 2;
  String inch = " inches";
  String CM = " cm ";
  if (cm<=10)
  {
  digitalWrite(buz, HIGH);
 }
 else
 {
  digitalWrite(buz,LOW);
 }
 {
  Serial.print(inches+inch);
  Serial.println();
  Serial.println(cm +CM);
  Serial.println();
  delay(500);
 }
} 
