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

#define ANALOG_0 220
#define ANALOG_1 156
#define ANALOG_2 204
#define ANALOG_3 140
#define ANALOG_4 172
#define ANALOG_5 236
#define ANALOG_6 188
#define ANALOG_7 252

using namespace std;

	/*Light*/
	Light *kitchen;
	LED *bathroom;
	RGBLight *livingroom;

	/*MOTION CONTROL*/
	MotionSensor *msKitchen; 
	MotionSensor *msBathroom;
	MotionSensor *msLivingroom;

	Buzzer *buzzerSmoke;
	Sensor *buttonSmokeDetector;
	Switch *nightDaySwitch;

	/*TEMP SENSOREN*/
	TemperatureSensor *tempBathroom;
	TemperatureSensor *tempLivingRoom;
	
	WindowDecoration *winDec;

void setup() {
	// Activate PWM for the 2 LED lights
	
	system("/usr/local/bin/eibd -D -S -T -i --eibaddr=0.0.1 --daemon=/var/log/eibd.log --no-tunnel-client-queuing ipt:145.52.126.174");
	system("sudo /home/pi/PiBits/ServoBlaster/user/servod --min=0 --max=100% --p1pins=\"15\"");
	system("sudo /home/pi/PiBits/ServoBlaster/user/servod --min=0 --max=100% --p1pins=\"16\"");
	
	kitchen = new Light(212);		// placeholder
	bathroom = new LED(969);		// placeholder
	livingroom = new RGBLight(696);	// placeholder
	
	msKitchen = new MotionSensor(ANALOG_1, kitchen);	// Vul hier ook de juiste adressen in
	msBathroom = new MotionSensor(ANALOG_2, bathroom);
	msLivingroom = new MotionSensor(ANALOG_3, livingroom);
	
	buzzerSmoke = new Buzzer();
	buttonSmokeDetector = new Sensor();
	nightDaySwitch = new Switch();
	
	tempBathroom = new TemperatureSensor(51);
	tempLivingRoom = new TemperatureSensor(50);
	
	winDec = new WindowDecoration();
}

void pollingMSandButtons() {

	SerialPi Serial;
	WirePi Wire;
	SPIPi SPI;

	Wire.begin();
	while(1) {			
		msKitchen->detectMotion(&Wire);
        msBathroom->detectMotion(&Wire);
        msLivingroom->detectMotion(&Wire);
	}
}

void logicController() {
    bool statusKitchen;
    bool statusBathroom;
    bool statusLivingRoom;
    bool statusDay;
    bool statusDetector;
    
    float tempBath;
    float tempLiving;
    
    while(1) {
		if (statusDay) {
			nightDaySwitch->deactivate();
		} else {
			nightDaySwitch->activate();
		}
		
		// cout<<"aapje logiccontroller"<<endl;
        statusKitchen = msKitchen->isActive();
        statusBathroom = msBathroom->isActive();
        statusLivingRoom = msLivingroom->isActive();
        
        statusDay = nightDaySwitch->isActive();
        
        statusDetector = buttonSmokeDetector->isActive();
 
        if(statusDay) {
            if(statusKitchen) {
                msKitchen->lightOn();
            } else {
				msKitchen->lightOff();
            }
            
            if(statusBathroom) {
                msBathroom->lightOn();
            } else {
				msBathroom->lightOff(); 
            } 
            
            if(statusLivingRoom) {
				if (!winDec->isUp()) {
					msLivingroom->lightOn();
				}
            } else {
				msLivingroom->lightOff();
            }
        } else {
			if(statusKitchen) {
                msKitchen->lightOn();
            }
            else {
				msKitchen->lightOff(); 
            }
            
            if(statusBathroom) {
                msBathroom->lightOn();
            } else {
				msBathroom->lightOff();
            }
            
			if(statusLivingRoom) {
                msLivingroom->lightOn();
            } else {
				msLivingroom->lightOff();
            }
        }
        
        if(statusDetector) {
            buttonSmokeDetector->buzzOn();
        } else {
            buttonSmokeDetector->buzzOff();
        }
        
        if(tempBath > 42.0) {
			digitalWrite(222, LOW);	// Placeholders
		} else if (tempBath < 30.0) {
			digitalWrite(222, HIGH);
		}
		
		if (tempLiving > 25.0) {
			winDec->down();
		} else {
			winDec->up();
		}
                
		this_thread::sleep_for(chrono::seconds(30));
    }
	

}
void pollingTempSensor()
{
	while(1) {
		tempBathroom->readTemperature();
		tempLivingRoom->readTemperature();
	}
	this_thread::sleep_for(chrono::seconds(10));
}

int main()
{
	setup();
	thread pollingQuick (pollingMSandButtons);
    thread pollingSlow (pollingTempSensor);
    logicController();
	
	system("sudo killall servod");
	
	return 0;
}


