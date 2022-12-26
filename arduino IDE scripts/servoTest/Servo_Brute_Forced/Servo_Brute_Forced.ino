#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int timing = 1000;
char input = 'n';
int temp = 0; //not opened
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  delay(timing);
}

void Open(){
  myservo.write(110);
  delay(timing);
  myservo.write(90);
delay(1000);
}

void Close(){
  myservo.write(70);
  delay(timing);
  myservo.write(90);
delay(1000);
}

void loop() {  
    if(Serial.available()){
        input = Serial.read();
        Serial.print("You typed: " );
        Serial.println(input);
        if(input == 'a'){
          Open();
          input = 'n';
          temp = 1;
        }
        if(input == 's' && temp != 0){
          Close();
          input == 'n';
          temp = 0;
        }
    }
    delay(200);
}
