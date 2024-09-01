#include <Servo.h>
Servo servo1;
int pos = 180;
void setup() {
  servo1.attach(9);
}
void loop() {
  servo1.write(pos);
  
  // Decrease 'pos' value to move the servo from 180 to 0 degrees
  if (pos > 0) {
    pos--;  // Decrease the position
  }

  delay(15); // Delay to allow the servo to move
}
