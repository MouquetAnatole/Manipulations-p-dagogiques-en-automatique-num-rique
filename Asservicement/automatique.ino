#include <cstdlib>
#include <cmath>
#include "Ultrasonic.h"
Ultrasonic ultrasonic(6, 5); // Trig et Echo

// Parameters
const int directionA = 12; // droite
const int directionB = 13; // gauche
const int brakeA = 9;
const int brakeB = 8;
const int pwmPinA = 3;
const int pwmPinB = 11;
const int dt = 50;        // en ms soit 0.05 s
const int robotSize = 11; // en cm // ecart des roues

// boolean to switch direction
bool directionState = true;

// boolean to stop
bool stopBool = false;

// variable a initializé avant loop.
float omegaErreur;
float omegaErreurAccu = 0;
float distanceErreur;
float vitesse = 0;
float distanceCommande = 10;

void setup()
{
    // Init Motor Shield
    pinMode(directionA, OUTPUT); // Initiates Motor Channel A pin
    pinMode(brakeA, OUTPUT);     // Initiates Brake Channel A pin
    pinMode(directionB, OUTPUT); // Initiates Motor Channel B pin
    pinMode(brakeB, OUTPUT);     // Initiates Brake Channel B pin

    // Init ultrason port
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
}

void loop()
{
    delay(dt);

    distancErreur = distanceCommande - ultrasonic.Ranging(CM);
    omegaErreur = ( analogRead(A0) - 512.0 )/1024*2*3.14; // lit la valeur de la tension en pont diviseur (entre 0 et 1023) puis converti en rad

    float omega = asservicementOmega(omegaErreur);
    vitesse = asservicementVitesse(distanceErreur);

    pilote_deux_roue(vitesse, omega);
}

void pilote_roue_droite(int pwm)
{

    digitalWrite(directionA, (1 + abs(pwm) / pwm) / 2);

    // release breaks
    digitalWrite(brakeA, LOW);

    // set work duty for the motor
    analogWrite(pwmPinA, abs(pwm));
}

void pilote_roue_gauche(int pwm)
{

    digitalWrite(directionB, (1 + abs(pwm) / pwm) / 2);

    // release breaks
    digitalWrite(brakeB, LOW);

    // set work duty for the motor
    analogWrite(pwmPinB, abs(pwm));
}

void pilote_deux_roue(float vitesse, float omega)
{
    // omega en rad/s
    omega = omega * 2 * robotSize;

    pilote_roue_gauche(vitesseToPWM(vitesse + omega));
    pilote_roue_droite(vitesseToPWM(vitesse - omega));
}

void stopMooving()
{
    digitalWrite(brakeA, HIGH);
    digitalWrite(brakeB, HIGH);
    analogWrite(pwmPinA, 0);
    analogWrite(pwmPinB, 0);
}

integer vitesseToPWM(float vitesse)
{
    a = 0.4106617826617826;
    b = -9.138363858363853;
    return ceil((abs(pwm) / pwm) * min(((abs(vitesse) - b) / a), 255));
}

float asservicementOmega(float erreur)
{
    omegaErreurAccu += erreur * dt ; // integral control

    return omegaErreurAccu;
}

float asservicementVitesse(float erreur)
{
    return - erreur * ;
}