/*
 * UpdateTemperature.cpp

 *
 *  Created on: 20 ago 2016
 *      Author: Fabio Limardo
 */

#include "Arduino.h"
#include "../messagingService/MsgService.h"
#include "../taskDeclaration/UpdateTemperature.h"
#include "../Services/Thermometer.h"

long startTimeB, endTimeB, deltaTimeB;
float temp;

UpdateTemperature::UpdateTemperature(int sensorPin){
	this->sensorPin = sensorPin;
}

void UpdateTemperature::init(int period){
	Task::init(period);
	sensor = new Thermometer(sensorPin);

}

void UpdateTemperature::tick(){
	//startTimeB = micros();
	sensor->updateValue();
	temp = sensor->getValue();
	MsgService.sendMsg(String(temp));
	//endTimeB = micros();
	//deltaTimeB = endTimeB - startTimeB;
	//Serial.println(deltaTimeB);
}




