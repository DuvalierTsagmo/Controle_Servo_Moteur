/*
  Titre      : Servo moteur
  Auteur     : Duvalier Tsagmo
  Date       : 01/02/2022
  Description: faire fonctionner un servo moteur avec de capteur
  Version    : 0.0.1
*/

#include <Arduino.h>
#include <Servo.h>
#include <"WIFIConnector_MKR1000.h">
#include "MQTTConnector.h"


Servo Moteur;  


// Declaration des variables pour le servo moteur
int Pause = 15; 		
int ValeurAngle = 0;        
int ValeurRotation = 0;        
int DerniereValeurAngle = 0; 

const int PIN_MOTEUR = 9; 
const int PIN_CAPTEUR = A5;  		

void setup() {
	wifiConnect();                 
	MQTTConnect();                 
	Serial.begin(9600);
	ServoMoteur.attach(PIN_MOTEUR);  
}

void loop() {
	ValeurRotation = analogRead(PIN_CAPTEUR);
	ValeurAngle = map(ValeurRotation, 0, 1023, 0, 90);
	ServoMoteur.write(ValeurAngle);  
	delay(Pause);
	if (ValeurAngle != DerniereValeurAngle){
		
		appendPayload("ValeurAngle", ValeurAngle);
		appendPayload("ValeurRotation", ValeurRotation);
		sendPayload();
		DerniereValeurAngle = ValeurAngle;
	}
}