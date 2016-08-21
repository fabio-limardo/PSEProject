/*
 * Task.h
 *
 *  Created on: 19 ago 2016
 *      Author: Fabio Limardo
 */

#ifndef TASKDECLARATION_TASK_H_
#define TASKDECLARATION_TASK_H_

class Task{
	int myPeriod;
	int timeElapsed;
public:
	virtual void init(int period) {
		myPeriod = period;
		timeElapsed = 0;
	}
	virtual void tick() = 0;

	bool updateAndCheckTime(int basePeriod){
		timeElapsed += basePeriod;
		if(timeElapsed >= myPeriod){
			timeElapsed = 0;
			return true;
		}
		else{
			return false;
		}
	}
};



#endif /* TASKDECLARATION_TASK_H_ */
