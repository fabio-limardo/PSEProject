#include "Arduino.h"
#include "Wire.h"
#include "componentDeclaration/I2CTemperatureSensor.h"
#include "componentDeclaration/Led.h"
#include "componentDeclaration/Photoresistor.h"
#include "componentDeclaration/UltrasonicSensor.h"

#include "common/Scheduler.h"
#include "taskDeclaration/AutonomousHeadlight.h"
#include "taskDeclaration/CheckDistance.h"
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

void setup(){
	Serial.begin(9600);
	Wire.begin();
	scheduler.init(50);

	Task* checkDistanceFront = new CheckDistance(DIST_TRIG_FRONT,DIST_ECHO_FRONT,'f',100);
	checkDistanceFront->init(50);
	scheduler.addTask(checkDistanceFront);

	Task* checkDistanceRight = new CheckDistance(DIST_TRIG_RIGHT,DIST_ECHO_RIGHT,'r',100);
	checkDistanceRight->init(50);
	scheduler.addTask(checkDistanceRight);

	Task* checkDistanceLeft = new CheckDistance(DIST_TRIG_LEFT,DIST_ECHO_LEFT,'l',100);
	checkDistanceLeft->init(50);
	scheduler.addTask(checkDistanceLeft);

	Task* autonomousHeadlight = new AutonomousHeadlight(LED_PIN,LIGHTSENSOR_PIN,LED_ON_THRESOLD);
	autonomousHeadlight->init(500);
	scheduler.addTask(autonomousHeadlight);

	Task* updateTemperature = new UpdateTemperature(TEMPSENSOR_ADDRESS);
	updateTemperature->init(1000);
	scheduler.addTask(autonomousHeadlight);
}

void loop(){
	scheduler.schedule();
}

//v. Plain Old C++ Object
//DistanceSensor* distanceSensorRight;
//DistanceSensor* distanceSensorFront;
//DistanceSensor* distanceSensorLeft;
//Light* light;
//Photodetector* lightSensor;
//TemperatureSensor* temperatureSensor;
//
//float temperature = 0;
//float front = 0;
//float right = 0;
//float left = 0 ;
//int lighIntensitity = 0;
//bool lightOn = false;
//
//
//
//
//
//
////The setup function is called once at startup of the sketch
//void setup()
//{
//	Serial.begin(9600);
//	Wire.begin();
//	distanceSensorRight = new UltrasonicSensor(DIST_TRIG_RIGHT,DIST_ECHO_RIGHT);
//	distanceSensorFront = new UltrasonicSensor(DIST_TRIG_FRONT,DIST_ECHO_FRONT);
//	distanceSensorLeft = new UltrasonicSensor(DIST_TRIG_LEFT,DIST_ECHO_LEFT);
//	light = new Led(LED_PIN);
//	lightSensor = new Photoresistor(LIGHTSENSOR_PIN);
//	temperatureSensor = new I2CTemperatureSensor(TEMPSENSOR_ADDRESS);
//}
//
//// The loop function is called in an endless loop
//void loop()
//{
////Add your repeated code here
//	temperature = temperatureSensor->getTemperature();
//	front = distanceSensorFront->getDistance(temperature);
//	right = distanceSensorRight->getDistance(temperature);
//	left = distanceSensorLeft->getDistance(temperature);
//	lighIntensitity = lightSensor->getLightIntensity();
//
//	Serial.println("Distanza frontale");
//	Serial.print(front);
//	Serial.println("Distanza destra");
//	Serial.print(right);
//	Serial.println("Distanza sinistra");
//	Serial.print(left);
//	Serial.println("Luminosità");
//	Serial.print(lighIntensitity);
//	Serial.println("Temperatura");
//	Serial.print(temperature);
//
//
//	if(!lightOn && lighIntensitity<=100){
//		light->switchOn();
//		lightOn = true;
//	}else if (lightOn && lighIntensitity>100){
//		light->switchOff();
//		lightOn = false;
//	}
//
//}
