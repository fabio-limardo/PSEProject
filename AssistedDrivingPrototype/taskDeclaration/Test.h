/*
 * autonomousHeadlight.h
 *
 *  Created on: 19 ago 2016
 *      Author: Fabio Limardo
 */

#ifndef TASKDECLARATION_TEST_H_
#define TASKDECLARATION_TEST_H_

#include "../common/Task.h"

class Test: public Task{

public:
	Test();
	void init(int period);
	void tick();

};

#endif /* TASKDECLARATION_AUTONOMOUSHEADLIGHT_H_ */
