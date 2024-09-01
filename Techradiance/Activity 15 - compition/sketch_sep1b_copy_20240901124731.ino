#include<Otto.h>
Otto Otto;
#define LeftLeg 2
#define RightLeg 3
#define LeftFoot 4
#define RightFoot 5
#define Buzzer 13
#define Trigger 8
#define Echo 9
long ultrasound() {
  long duration, distance;
  digitalWrite(Trigger, LOW);
  delayMicroseconds(10);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  duration = pulseIn(Echo, HIGH);
  distance = duration/58;
  return distance;
}
void setup() {
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
}

void loop() {
   if (ultrasound() <=15) {
    Otto.sing(S_surprise);
    Otto.playGesture(OttoConfused);
    Otto.walk(2, 1000, -1);
    Otto.turn(3, 1000, 1);
   } 
   Otto.walk(1, 1000, 1);
}
