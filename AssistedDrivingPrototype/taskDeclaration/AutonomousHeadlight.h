/*
 * autonomousHeadlight.h
 *
 *  Created on: 19 ago 2016
 *      Author: Fabio Limardo
 */

#ifndef TASKDECLARATION_AUTONOMOUSHEADLIGHT_H_
#define TASKDECLARATION_AUTONOMOUSHEADLIGHT_H_

#include "../componentDeclaration/Led.h"
#include "../taskDeclaration/ThresholdLightDetector.h"
#include "../common/Task.h"

class AutonomousHeadlight: public Task{

	int ledPin, lightSensorPin, threshold;
	Light* led;
	ThresoldLightDetector* lightDetector;
	enum {ON,OFF} state;

public:
	AutonomousHeadlight(int ledPin, int lightSensorPin, int thresold);
	void init();
	void tick();

};

#endif /* TASKDECLARATION_AUTONOMOUSHEADLIGHT_H_ */
