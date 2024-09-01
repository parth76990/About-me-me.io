#include <Servo.h>

Servo lefttop, righttop, leftbottom, rightbottom;
int pos = 60;

void setup() {
  lefttop.attach(2);
  leftbottom.attach(3);
  righttop.attach(4);
  rightbottom.attach(5); // Corrected the servo name and pin number
}

void loop() {
  lefttop.write(pos);
  leftbottom.write(pos);
  righttop.write(pos);
  rightbottom.write(pos + 90); // Adjusted to correct the foot angle
}
