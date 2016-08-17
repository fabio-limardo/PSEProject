#include "Arduino.h"
#include "Wire.h"
#include "I2CTemperatureSensor.h"
#include "Led.h"
#include "Photoresistor.h"
#include "UltrasonicSensor.h"

#define TEMPSENSOR_ADDRESS 72
#define LED_PIN 13
#define LIGHTSENSOR_PIN A0
#define DIST_TRIG_RIGHT 12
#define DIST_ECHO_RIGHT 11
#define DIST_TRIG_FRONT 10
#define DIST_ECHO_FRONT 9
#define DIST_TRIG_LEFT 8
#define DIST_ECHO_LEFT 7

DistanceSensor* distanceSensorRight;
DistanceSensor* distanceSensorFront;
DistanceSensor* distanceSensorLeft;
Light* light;
Photodetector* lightSensor;
TemperatureSensor* temperatureSensor;



//The setup function is called once at startup of the sketch
void setup()
{
	Serial.begin(9600);
	Wire.begin();
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
}
