#include <cstdlib>
#include <cmath>

//Parameters
const int directionA  = 12; //droite
const int directionB  = 13; //gauche
const int brakeA  = 9;
const int brakeB  = 8;
const int pwmPinA  = 3;
const int pwmPinB  = 11;
const int dt = 500;         // en ms soit 0.5 s
const int robotSize = 11;   // en cm // ecart des roues

//boolean to switch direction
bool directionState = true;

//boolean to stop
bool stopBool = false;


void setup() {
  //Init Motor Shield
  pinMode(directionA, OUTPUT); //Initiates Motor Channel A pin
  pinMode(brakeA, OUTPUT); //Initiates Brake Channel A pin
  pinMode(directionB, OUTPUT); //Initiates Motor Channel B pin
  pinMode(brakeB, OUTPUT); //Initiates Brake Channel B pin
}



void loop() {
    delay(dt);
}








void pilote_roue_droite(int pwm){
    
    digitalWrite(directionA, (1+abs(pwm)/pwm)/2);

    //release breaks
    digitalWrite(brakeA, LOW);

    //set work duty for the motor
    analogWrite(pwmPinA, abs(pwm));
}

void pilote_roue_gauche(int pwm){
    
    digitalWrite(directionB, (1+abs(pwm)/pwm)/2);

    //release breaks
    digitalWrite(brakeB, LOW);

    //set work duty for the motor
    analogWrite(pwmPinB, abs(pwm));
}

void pilote_deux_roue(float vitesse, float omega){
    pilote_roue_gauche(ceil(2*3.14*robotSize/dt)  + vitesse);
    pilote_roue_droite(ceil(-2*3.14*robotSize/dt) + vitesse);
}


void stopMooving(){
    digitalWrite(brakeA, HIGH);
    digitalWrite(brakeB, HIGH);
    analogWrite(pwmPinA, 0);
    analogWrite(pwmPinB, 0);
}