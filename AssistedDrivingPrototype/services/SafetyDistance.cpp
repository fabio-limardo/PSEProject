/*
 * SafetyDistance.cpp
 *
 *  Created on: 20 ago 2016
 *      Author: Fabio Limardo
 */

#include "SafetyDistance.h"

#include "Arduino.h"
#include "../componentDeclaration/UltrasonicSensor.h"
#include "Thermometer.h"

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



