/*
  Titre      : Servo moteur
  Auteur     : Duvalier Tsagmo
  Date       : 01/02/2022
  Description: faire fonctionner un servo moteur avec de capteur
  Version    : 0.0.1
*/

#include <Arduino.h>
#include <Servo.h>

//Declaration des constantes
const int touche = 2;
const int bouton = 3;
const int hautParleur = 5;
int angle = 0;

Servo moteur1;

void setup()
{
    pinMode(touche, INPUT);
    pinMode(bouton, INPUT);
    pinMode(hautParleur, INPUT);
    moteur1.attach(9);
}

void loop()
{

    if (digitalRead(touche) == 1 && angle < 180)
    {
        angle += 1;
        moteur1.write(angle);
        delay(10);
    }
    else if (angle >= 180 && digitalRead(touche) == 1)
    {
        tone(5, 500, 2000);
        delay(500);
        noTone(5);
    }

    if (digitalRead(bouton) == 1 && angle >= 0)
    {
        angle -= 1;
        moteur1.write(angle);
        delay(10);
    }
    else if (angle <= 1 && digitalRead(bouton) == 1)
    {
        tone(5, 500, 2000);
        delay(500);
        noTone(5);
    }
}