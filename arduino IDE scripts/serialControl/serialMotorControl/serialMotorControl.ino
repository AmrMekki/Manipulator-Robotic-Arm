const int pin_mainStep = 3;
const int pin_mainDir = 4;

const int pin_baseStep = 6;
const int pin_baseDir = 7;

const int pin_secStep = 9;
const int pin_secDir = 8;

char input;

void rotate(int pin_step, int steps){
  for(float x = 0; x < steps; x++)
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
  delay(2000);  
 
  Serial.println("Hello From arduino");
}
 
void loop() {
  if(Serial.available()){
      input = Serial.read();
      Serial.println(input);
      
      if(input == 'r')
      {
        
        digitalWrite(pin_baseDir, 0);
        rotate(pin_baseStep, 50);
        
      }
      else if(input == 'l'){
        digitalWrite(pin_baseDir, 1);
        rotate(pin_baseStep, 50);
        
      }
      else if(input == 'u'){
        digitalWrite(pin_mainDir, 1);
        rotate(pin_mainStep, 50);
        
      }
      else if(input == 'd'){
        digitalWrite(pin_mainDir, 0);
        rotate(pin_mainStep, 50);
        
      }
      else if(input == 'f'){
        digitalWrite(pin_secDir, 0);
        rotate(pin_secStep, 50);
        
      }
      else if(input == 'b'){
        digitalWrite(pin_secDir, 1);
        rotate(pin_secStep, 50);
        
      }
  }
}
