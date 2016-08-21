/*
 * AutonomousHeadlight.cpp
 *
 *  Created on: 19 ago 2016
 *      Author: Fabio Limardo
 */

#include "../taskDeclaration/AutonomousHeadlight.h"
#include "../componentDeclaration/Led.h"
#include "../utils/ThresholdLightDetector.h"

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
}

