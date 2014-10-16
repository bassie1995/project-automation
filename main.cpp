#include "rgblight.h"
#include "led.h"
#include "switch.h"
#include "Sensor.h"
#include "motionsensor.h"
#include "temperaturesensor.h"
#include "windowdecoration.h"
#include "buzzer.h"
#include "ipcamera.h"
#include <time.h>
#include <thread>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	/*Light*/
	Led kitchen();
	
	// Activate PWM for the 3 lights in the rooms
	string start = "sudo ./home/pi/PiBits/ServoBlaster/user/servod --min=0 --max=100% --p1pins=\"" + to_string(/* VUL ADRES IN L1 */) + "\"";
	system(start.c_str());
	start = "sudo ./home/pi/PiBits/ServoBlaster/user/servod --min=0 --max=100% --p1pins=\"" + to_string(/* VUL ADRES IN L2 */) + "\"";
	system(start.c_str());
	
	/*MOTION CONTROL*/
	MotionSensor msKitchen(0x9C, &kitchen); // Vul hier ook de juiste adressen in
	MotionSensor msLivingroom(0xCC ,&livingRoom);
	MotionSensor msBathroom(0x8C, &bathroom);

	/*BUTTONS + BUZZER*/
	Buzzer buzzerSmoke;
	Sensor buttonBed;
	Sensor buttonSmokeDetector(buzzerSmoke);
	
	/*TEMP SENSOREN*/
	TemperatureSensor tempBathroom;
	TemperatureSensor tempLiving;
	
	/*Threads*/
	thread ms1(&MotionSensor::detectMotion,msKitchen);
	thread ms2(&MotionSensor::detectMotion,msLivingroom);
	thread ms3(&MotionSensor::detectMotion,msBathroom);
	

	thread bb(&Sensor::IsActive,buttonBed);
	thread sd(&Sensor::IsActive,buttonSmokeDetector);
		  
	thread rt(&TemperatureSensor::readTemperature,tempLiving);
	
	//thread timer(&);
		  
	while(1){}
	return 0;
}


