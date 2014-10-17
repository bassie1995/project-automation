#include "arduPi.h"
#include "rgblight.h"
#include "led.h"
#include "switch.h"
#include "sensor.h"
#include "motionsensor.h"
#include "temperaturesensor.h"
#include "windowdecoration.h"
#include "buzzer.h"
#include "ipcamera.h"
#include <time.h>
#include <thread>
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

	/*Light*/
	Light *kitchen;
	LED *bathroom;
	RGBLight *livingroom;

	//~ /*MOTION CONTROL*/
	MotionSensor *msKitchen; // Vul hier ook de juiste adressen in
	MotionSensor *msBathroom;
	MotionSensor *msLivingroom;

	Buzzer *buzzerSmoke;
	Sensor *buttonBed;
	Sensor *buttonSmokeDetector;
	Switch *nightDaySwitch;

	/*TEMP SENSOREN*/
	TemperatureSensor *tempBathroom;
	TemperatureSensor *tempLiving;

void setup() {
	// Activate PWM for the 2 LED lights
	system("sudo ./home/pi/PiBits/ServoBlaster/user/servod --min=0 --max=100% --p1pins=\"CC\"");
	system("sudo ./home/pi/PiBits/ServoBlaster/user/servod --min=0 --max=100% --p1pins=\"8C\"");
	
	kitchen = new Light("CC");
	bathroom = new LED("8C");
	livingroom = new RGBLight();
	
	msKitchen = new MotionSensor(string("9C"), kitchen);
	msBathroom = new MotionSensor(string("8C"), bathroom);
	msLivingroom = new MotionSensor(string("CC"), livingroom);
}

void pollingMSandButtons() {

	SerialPi Serial;
	WirePi Wire;
	SPIPi SPI;

	Wire.begin();

	while(1){
		msKitchen->detectMotion(&Wire);
        msBathroom->detectMotion(&Wire);
        msLivingroom->detectMotion(&Wire);

        buttonSmokeDetector->isActive();
		buttonBed->isActive();
	}
}
void logicController(){
    bool statusKitchen;
    bool statusBathroom;
    bool statusLivingRoom;
    bool statusDay;
    bool statusDetector;
    
    while(1) {
        statusKitchen = msKitchen->isActive();
        statusBathroom = msBathroom->isActive();
        statusLivingRoom = msLivingroom->isActive();
        statusDay = nightDaySwitch->isActive();
        statusDetector = buttonSmokeDetector->isActive();

        if(statusDay) //true als het dag is
        {
            if(statusKitchen)
            {
                msKitchen->lightOn();
            }
            else{
// hier komt de uit fuctie
            }
            if(statusBathroom)
            {
                msBathroom->lightOn();
            }
            else
            {
 // hier komt de uit fuctie
            }
            if(statusLivingRoom)
            {
                msLivingroom->lightOn();
            }
            else{
// hier komt de uit fuctie
            }
        }
        else // hier als het nacht is
        {

        }
        if(statusDetector)
        {
            buttonSmokeDetector->buzzOn();
        }
        else{
            buttonSmokeDetector->buzzOff();
        }
    }


}
void pollingTempSensor()
{
    this_thread::sleep_for(chrono::seconds(3));
}

int main()
{
	void setup();


	
	thread pollingQuick (pollingMSandButtons);
    thread pollingSlow (pollingTempSensor);
    pollingQuick.join();

	/*Threads*/
/*	thread ms1(&MotionSensor::detectMotion,msKitchen);
	thread ms2(&MotionSensor::detectMotion,msLivingroom);
	thread ms3(&MotionSensor::detectMotion,msBathroom);
	

	thread bb(&Sensor::IsActive,buttonBed);
	thread sd(&Sensor::IsActive,buttonSmokeDetector);
		  
	thread rt(&TemperatureSensor::readTemperature,tempLiving);
	
	//thread timer(&);
*/
	while(1){}
	return 0;
}


