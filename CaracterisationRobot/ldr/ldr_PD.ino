void setup() {
     //myservo1.attach(9);//Branchement du servo1 à la broche 9
     //myservo2.attach(10); // Branchement du servo2 à la broche 10
     Serial.begin(9600);
}

void loop() {
    int val = analogRead(A1);  // lit la valeur de la tension en pont diviseur (entre 0 et 1023)
    //val = map(val, 0, 171, 0, 180);  // le convertir en consigne pour le servo (entre 0 and 180)

    Serial.println(val);
    
    delay(150);  // attendre
}
