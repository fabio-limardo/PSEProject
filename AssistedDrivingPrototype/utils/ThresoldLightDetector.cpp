/*
 * LightLevelDetector.cpp
 *
 *  Created on: 19 ago 2016
 *      Author: Fabio Limardo
 */

#include "../utils/ThresholdLightDetector.h"
#include "../componentDeclaration/Photoresistor.h"

ThresoldLightDetector::ThresoldLightDetector(int lightSensorPin, int thresold){
	this->lightSensorPin = lightSensorPin;
	this->threshold = thresold;
	lightSensor = new Photoresistor(lightSensorPin);
}

bool ThresoldLightDetector::detected(){
	if(lightSensor->getLightIntensity() >= threshold)
		return true;
	else
		return false;
}

