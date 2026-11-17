
#include <Servo.h>
#define SERVO_PIN   10

Servo myservo;                          // create servo object to control a servo

int pos = 0;                            // variable to store the servo position

void setup() {
  myservo.attach(SERVO_PIN);            // attaches the servo on pin 9 to the servo object
  myservo.write(pos);                   // go to position zero first
  delay(2000);                          // wait for some time
}

void loop() {
  delay(1000);                          // delay of 1 second before start
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees in steps of 1 degree
    myservo.write(pos);                 // tell servo to go to position in variable 'pos'
    delay(15);                          // waits 15 ms for the servo to reach the position
  }
  delay(1000);                          // delay of 1 second before changing direction of rotation
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);                 // tell servo to go to position in variable 'pos'
    delay(15);                          // waits 15 ms for the servo to reach the position
  }
}