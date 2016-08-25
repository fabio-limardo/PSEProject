/*
 * UpdateTemperature.cpp
 *
 *  Created on: 20 ago 2016
 *      Author: Fabio Limardo
 */

#include "Arduino.h"
#include "../taskDeclaration/UpdateTemperature.h"
#include "../Services/Thermometer.h"

long startTimeB, endTimeB, deltaTimeB;

UpdateTemperature::UpdateTemperature(int sensorPin){
	this->sensorPin = sensorPin;
}

void UpdateTemperature::init(int period){
	Task::init(period);
	sensor = new Thermometer(sensorPin);

}

void UpdateTemperature::tick(){
	Serial.println("tick");
	startTimeB = micros();
	sensor->updateValue();
	endTimeB = micros();
	deltaTimeB = endTimeB - startTimeB;
	Serial.print("temp task time: ");
	Serial.println(deltaTimeB);
}




