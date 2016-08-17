/*
 * Photoresistor.cpp
 *
 *  Created on: 17 ago 2016
 *      Author: Fabio Limardo
 */

#include "Arduino.h"
#include "Photodetector.h"

Photoresistor::Photoresistor(int pin){
	this->pin = pin;
}

int Photoresistor::getLightIntensity(){
	 int lightIntensity = analogRead(pin);
	 return lightIntensity;
}
