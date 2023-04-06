//Suit la lumière mais tourne sur place
//Parameters
const int directionA  = 12;
const int directionB  = 13;
const int brakeA  = 9;
const int brakeB  = 8;
const int pwmPinA  = 3;
const int pwmPinB  = 11;

void setup() {
    //myservo1.attach(9);//Branchement du servo1 à la broche 9
    //myservo2.attach(10); // Branchement du servo2 à la broche 10
    Serial.begin(9600);

    //Init Motor Shield
    pinMode(directionA, OUTPUT); //Initiates Motor Channel A pin
    pinMode(brakeA, OUTPUT); //Initiates Brake Channel A pin
    pinMode(directionB, OUTPUT); //Initiates Motor Channel B pin
    pinMode(brakeB, OUTPUT); //Initiates Brake Channel B pin
}

void loop() {
    int pwm=80;
    int val = analogRead(A0);  // lit la valeur de la tension en pont diviseur (entre 0 et 1023)
    //val = map(val, 0, 600, 0, 180);  // le convertir en consigne pour le servo (entre 0 and 180)
    
    if(val<30){
      turn_right(pwm);
    }
    else if(val>100){
      turn_left(pwm);
    }
    else{
      stopMooving();
    }
    
    Serial.println(val);
    
    delay(150);  // attendre
}


void turn_left(int pwm){
  digitalWrite(directionA, LOW);
  digitalWrite(directionB, LOW);
  digitalWrite(brakeA, LOW);
  digitalWrite(brakeB, LOW);
  analogWrite(pwmPinA, pwm);
  analogWrite(pwmPinB, pwm);
}

void turn_right(int pwm){
  digitalWrite(directionB, HIGH);
  digitalWrite(directionA, HIGH);
  digitalWrite(brakeA, LOW);
  digitalWrite(brakeB, LOW);
  analogWrite(pwmPinB, pwm);
  analogWrite(pwmPinA, pwm);
}

void stopMooving(){
  digitalWrite(brakeA, HIGH);
  digitalWrite(brakeB, HIGH);
  analogWrite(pwmPinA, 0);
  analogWrite(pwmPinB, 0);
}