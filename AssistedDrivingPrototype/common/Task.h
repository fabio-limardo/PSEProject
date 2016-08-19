/*
 * Task.h
 *
 *  Created on: 19 ago 2016
 *      Author: Fabio Limardo
 */

#ifndef TASKDECLARATION_TASK_H_
#define TASKDECLARATION_TASK_H_

class Task{
public:
	virtual void init() = 0;
	virtual void tick() = 0;
};



#endif /* TASKDECLARATION_TASK_H_ */
