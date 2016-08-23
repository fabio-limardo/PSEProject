/*
 * AutonomousHeadlight.cpp
 *
 *  Created on: 19 ago 2016
 *      Author: Fabio Limardo
 */

#include "Arduino.h"

#include "../taskDeclaration/Test.h"



Test::Test(){
	int z=0;
}

void Test::init(int period){
	Task::init(period);
}

void Test::tick(){
	Serial.println("Task Test");
}

