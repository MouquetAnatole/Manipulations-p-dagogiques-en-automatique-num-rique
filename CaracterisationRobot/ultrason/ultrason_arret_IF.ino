#include "Ultrasonic.h"
Ultrasonic ultrasonic(6, 5); // Trig et Echo
 
//Parameters
const int directionA  = 12;
const int directionB  = 13;
const int brakeA  = 9;
const int brakeB  = 8;
const int pwmPinA  = 3;
const int pwmPinB  = 11;

//boolean to switch direction
bool directionState = true;

//boolean to stop
bool stopBool = false;

void setup() {
  //Init Motor Shield
  Serial.begin(9600);
  pinMode(directionA, OUTPUT); //Initiates Motor Channel A pin
  pinMode(brakeA, OUTPUT); //Initiates Brake Channel A pin
  pinMode(directionB, OUTPUT); //Initiates Motor Channel B pin
  pinMode(brakeB, OUTPUT); //Initiates Brake Channel B pin

  //Init ultrason port
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  
}
void loop() {
  int dist = ultrasonic.Ranging(CM);
  Serial.print(dist);
  Serial.println(" cm");
  
  if(dist>20){
    forward(80);
    //delay(5000);
    //stopBool=true;
  }
  else{
    stopMooving();
  }
}


// to move forward
void forward(int pwm){
  if(directionState == false){
    digitalWrite(directionA, HIGH);
    digitalWrite(directionB, LOW);
  }
  else{
    digitalWrite(directionA, LOW);
    digitalWrite(directionB, HIGH);
  }
  
  //release breaks
  digitalWrite(brakeA, LOW);
  digitalWrite(brakeB, LOW);
  
  //set work duty for the motor
  analogWrite(pwmPinA, pwm);
  analogWrite(pwmPinB, pwm);
}

void stopMooving(){
  digitalWrite(brakeA, HIGH);
  digitalWrite(brakeB, HIGH);
  analogWrite(pwmPinA, 0);
  analogWrite(pwmPinB, 0);
}
