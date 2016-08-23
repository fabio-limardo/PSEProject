/*
 * SafetyDistance.cpp
 *
 *  Created on: 20 ago 2016
 *      Author: Fabio Limardo
 */

#include "Arduino.h"
#include "../Services/SafetyDistance.h"
#include "../componentDeclaration/UltrasonicSensor.h"
#include "../Services/Thermometer.h"

SafetyDistance::SafetyDistance(int trigPin, int echoPin){
	this->trigPin = trigPin;
	this->echoPin = echoPin;
	this->minDistance = minDistance;
	sensor = new UltrasonicSensor(trigPin,echoPin);
}

bool SafetyDistance::isSafety(float minDistance, float temperature){
	//Serial.println(sensor->getDistance(temperature));
	if(sensor->getDistance(temperature)<=minDistance)
		return false;
	else
		return true;
}



