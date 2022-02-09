/*
  Titre      : Servo moteur
  Auteur     : Duvalier Tsagmo
  Date       : 01/02/2022
  Description: faire fonctionner un servo moteur avec de capteur
  Version    : 0.0.1
*/

#include <Arduino.h>
#include <Servo.h>

int potpin = A1;
int servoPin = 9;

int angle = 0;
int lire = 0;
Servo moteur1;
void setup()
{
    moteur1.attach(servoPin);
}
void loop()
{
    lire = analogRead(potpin);
    angle = map(lire, 0, 1023, 0, 90);
    moteur1.write(angle);
    delay(15);
    appendPayload("Temperature", angle); // Ajout de la donnée température au message MQTT
    sendPayload();                       // Envoie du message via le protocole MQTT
}