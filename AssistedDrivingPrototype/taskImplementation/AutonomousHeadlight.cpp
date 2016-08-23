/*
 * AutonomousHeadlight.cpp
 *
 *  Created on: 19 ago 2016
 *      Author: Fabio Limardo
 */

#include "Arduino.h"
#include "../taskDeclaration/AutonomousHeadlight.h"
#include "../componentDeclaration/Led.h"
#include "../Services/ThresholdLightDetector.h"

long startTime = 0, endTime=0 , deltaTime = 0;

AutonomousHeadlight::AutonomousHeadlight(int ledPin, int lightSensorPin, int threshold){
	this->ledPin = ledPin;
	this->lightSensorPin = lightSensorPin;
	this->threshold = threshold;
}

void AutonomousHeadlight::init(int period){
	Task::init(period);
	led = new Led(ledPin);
	lightDetector = new ThresoldLightDetector(lightSensorPin, threshold);
	state = OFF;
}

void AutonomousHeadlight::tick(){
	startTime = micros();
	switch(state){
	case OFF:
		if(lightDetector->detected()){
			led->switchOn();
			state = ON;
		}
		break;
	case ON:
		if(!lightDetector->detected()){
			led->switchOff();
			state = OFF;
		}
		break;

	}
	endTime = micros();
	deltaTime = endTime - startTime;
	Serial.println (deltaTime);
}

