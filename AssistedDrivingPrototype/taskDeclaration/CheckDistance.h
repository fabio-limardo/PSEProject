/*
 * CheckDistance.h
 *
 *  Created on: 21 ago 2016
 *      Author: Fabio Limardo
 */

#ifndef TASKDECLARATION_CHECKDISTANCE_H_
#define TASKDECLARATION_CHECKDISTANCE_H_

#include "../common/Task.h"
#include "../Services/SafetyDistance.h"

class CheckDistance: public Task {
	int trigPin,echoPin;
	char type;
	enum {SAFETY,ALARM} state;
	float minDistance, temperature = 20;
	SafetyDistance* checker;

public:
	CheckDistance(int trigPin,int echoPin,char type,float minDistance);
	void init(int period);
	void tick();
};



#endif /* TASKDECLARATION_CHECKDISTANCE_H_ */
