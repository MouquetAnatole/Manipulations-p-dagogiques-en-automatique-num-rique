/*
 Contrôler une position d'asservissement à l'aide d'un potentiomètre (résistance variable) 
pour contrôler des SERVOMOTEURS pas des moteurs bêtes
 <http://people.interaction-ivrea.it/m.rinott>
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo1;  // créer une commande pour contrôler le servo1
Servo myservo2;  // pour le servo2

int potpin = 0;  // broche analogique utilisée pour connecter le 1er pont diviseur
int potpin2 = 1;  // broche analogique utilisée pour connecter le 2nd pont diviseur
int val;    // variable pour lire la valeur de la broche analogique
int val2;    // 

void setup() {
     myservo1.attach(9);  // Branchement du servo1 à la broche 9
     myservo2.attach(10);  // Branchement du servo2 à la broche 10
     Serial.begin(9600);
}

int val;    // variable pour lire la valeur de la broche analogique
int val2;    // 
void setup() {
    myservo1.attach(9);  // Branchement du servo1 à la broche 9
    myservo2.attach(10);  // Branchement du servo2 à la broche 10
    Serial.begin(9600);
}


void loop() {
    val = analogRead(potpin);            // lit la valeur de la tension en pont diviseur (entre 0 et 1023)
    val = map(val, 0, 1023, 0, 180);     // le convertir en consigne pour le servo (entre 0 and 180)
    myservo1.write(val);// règle la position du servo en fonction de la valeur de consigne
    Serial.println(val);
    val2 = analogRead(potpin2);
    val2 = map(val2, 0, 1023, 0, 180);
    myservo2.write(val2);
    Serial.println(val);
    delay(15);                           // attendre que le servo atteigne sa position
}

