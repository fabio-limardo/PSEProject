/*
 * CheckDistance.cpp
 *
 *  Created on: 21 ago 2016
 *      Author: Fabio Limardo
 */

#include "Arduino.h"
#include "string.h"
#include "../messagingService/MsgService.h"
#include "../taskDeclaration/CheckDistance.h"
#include "../Services/SafetyDistance.h"

long startTimeA,endTimeA, deltaTimeA;

CheckDistance::CheckDistance(int trigPin, int echoPin, char type,float minDistance){
	this->trigPin = trigPin;
	this->echoPin = echoPin;
	this->type = type;
	this->minDistance = minDistance; //Dipende dalla velocità, ocio dunque
}

void CheckDistance::init(int period){
	Task::init(period);
	state = SAFETY;
	checker = new SafetyDistance(trigPin, echoPin);
}


void CheckDistance::tick(){
	//startTimeA = micros();
	if (MsgService.isMsgAvailable()) {
	    Msg* msg = MsgService.receiveMsg();
		temperature= atoi(msg->getContent().c_str());
	    delete msg;
	    Serial.println(temperature);
	}
	switch(state){
		case SAFETY:
			if(checker->isSafety(minDistance,temperature)){
				break;
			}
			else{
				state = ALARM;
			}
			break;
		case ALARM:
			switch (type){
				case 'r':
					//Turn Left
					break;
				case 'f':
					//Break
					break;
				case 'l':
					//turn right
					break;
				}
			if(checker->isSafety(minDistance,temperature)){
				state = SAFETY;
			}
			break;
			}
//	endTimeA = micros();
//	deltaTimeA = endTimeA - startTimeA;
//	Serial.print("distance task time ");
//	Serial.println(deltaTimeA);



}



