const int stepPin = 3;
const int dirPin = 4;


const int stepPin1 = 6;
const int dirPin1 = 7;

const int stepPin2 = 9;
const int dirPin2 = 8;

float ratio = 45/21;

bool direction = true;
const int stepsPerRevolution = 200;
void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  delay(2000);
}

void loop() {
  digitalWrite(dirPin, direction);
  digitalWrite(dirPin1, direction);
  digitalWrite(dirPin2, direction);

  for(float x = 0; x < 200 * 16; x++)
  {
    digitalWrite(stepPin, HIGH);
    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    
    delayMicroseconds(2000);
    
    digitalWrite(stepPin, LOW);
    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    
    delayMicroseconds(2000);
  }
  direction = !direction;
  delay(1000); // Wait a second
}
