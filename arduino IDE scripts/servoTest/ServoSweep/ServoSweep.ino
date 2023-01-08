#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
Servo myservo2;
int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);//Setup serial communication on TX/RX
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
 Serial.println("Hello world!");
delay(1000);
}
