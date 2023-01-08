const int pin_mainStep = 3;
const int pin_mainDir = 4;

const int pin_baseStep = 6;
const int pin_baseDir = 7;

const int pin_secStep = 9;
const int pin_secDir = 8;

char input;

void rotate(int pin_step, int steps){
    steps = steps * 2;
    for(int i = 0; i < steps; i++)
    {
      digitalWrite(pin_step, HIGH);
      delayMicroseconds(10000);
  
      digitalWrite(pin_step, LOW);
      delayMicroseconds(10000);
    }
}

void setup() {
  
  pinMode(pin_baseStep, OUTPUT);
  pinMode(pin_baseDir, OUTPUT);

  pinMode(pin_mainStep, OUTPUT);
  pinMode(pin_mainDir, OUTPUT);

  pinMode(pin_secStep, OUTPUT);
  pinMode(pin_secDir, OUTPUT);
   
  Serial.begin(9600); 
  Serial.println("Hello From arduino");
}
 
void loop() {
  if(Serial.available()){
      input = Serial.read();
      Serial.println(input);
      
      if(input == '0'){
        digitalWrite(pin_mainDir, 0);
        rotate(pin_mainStep, 42);
        
      }
      else if(input == '1'){
        digitalWrite(pin_secDir, 1);
        rotate(pin_secStep, 40);
        
      }
  }
}
