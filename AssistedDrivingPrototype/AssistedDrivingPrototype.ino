#include "Arduino.h"
#include "Wire.h"
#include "componentDeclaration/I2CTemperatureSensor.h"
#include "componentDeclaration/Led.h"
#include "componentDeclaration/Photoresistor.h"
#include "componentDeclaration/UltrasonicSensor.h"

#include "scheduler/Scheduler.h"
#include "messagingService/MsgService.h"
#include "taskDeclaration/AutonomousHeadlight.h"
#include "taskDeclaration/CheckDistance.h"
#include "taskDeclaration/Test.h"
#include "taskDeclaration/UpdateTemperature.h"


#define TEMPSENSOR_ADDRESS 72
#define LED_PIN 13
#define LIGHTSENSOR_PIN A0
#define DIST_TRIG_RIGHT 12
#define DIST_ECHO_RIGHT 11
#define DIST_TRIG_FRONT 10
#define DIST_ECHO_FRONT 9
#define DIST_TRIG_LEFT 8
#define DIST_ECHO_LEFT 7
#define LED_ON_THRESOLD 120

Scheduler scheduler;
Task* updateTemperature;
unsigned long lastReading;

void setup(){
	Serial.begin(9600);
	Wire.begin();
	MsgService.init();
	scheduler.init(50);

	Task* checkDistanceFront = new CheckDistance(DIST_TRIG_FRONT,DIST_ECHO_FRONT,'f',100);
	checkDistanceFront->init(100);
	scheduler.addTask(checkDistanceFront);

	Task* checkDistanceRight = new CheckDistance(DIST_TRIG_RIGHT,DIST_ECHO_RIGHT,'r',100);
	checkDistanceRight->init(100);
	scheduler.addTask(checkDistanceRight);

	Task* checkDistanceLeft = new CheckDistance(DIST_TRIG_LEFT,DIST_ECHO_LEFT,'l',100);
	checkDistanceLeft->init(100);
	scheduler.addTask(checkDistanceLeft);

	Task* autonomousHeadlight = new AutonomousHeadlight(LED_PIN,LIGHTSENSOR_PIN,LED_ON_THRESOLD);
	autonomousHeadlight->init(250);
	scheduler.addTask(autonomousHeadlight);


//	Task* test = new Test();
//	test->init(1000);
//	scheduler.addTask(test);

	updateTemperature = new UpdateTemperature(TEMPSENSOR_ADDRESS);
	updateTemperature->init(150);
	//scheduler.addTask(updateTemperature);
}

void loop(){

	scheduler.sleep();
	  if (millis () - lastReading >= 500 )   // 200 Hz
	    {
		  lastReading = millis ();
		  updateTemperature->tick();

	    // Update x, y, and z with new values 2.5ms
	    }

}

