#include "arduPi.h"
#include "ipcamera.h"
#include "main.h"

#include <time.h>
#include <thread>
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

// SLUIT LEDS AAN OP Dig PIN 2 & Dig PIN 3

void setup() {
	// Activate PWM for the 2 LED lights
	system("sudo /home/pi/Desktop/test.sh");
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
        // Digital Read for frontDoorSensor->activate();
	}
}

void logicController() {
    bool statusKitchen;
    bool statusBathroom;
    bool statusLivingRoom;
    bool statusDay;
    bool statusDetector;
    bool manualMode=false;
    
    bool statusDoorSensor=false;
    
    float tempBath;
    float tempLiving;
    
    while(1)
    {
		
		
		// cout<<"aapje logiccontroller"<<endl;
        statusKitchen = msKitchen->isActive();
        statusBathroom = msBathroom->isActive();
        statusLivingRoom = msLivingroom->isActive();
        
        statusDay = nightDaySwitch->isActive();
        
        statusDetector = buttonSmokeDetector->isActive();
 
        statusDoorSensor = frontDoorSensor->isActive();
        
        if (statusDay)
			nightDaySwitch->deactivate();
        else
			nightDaySwitch->activate();

        if(statusDay && !manualMode)
        {
            if(statusKitchen && !kitchen->getStatus())
            {
                msKitchen->lightOn();
                msBathroom->lightOff();
                msLivingroom->lightOff();
            }

            if(statusBathroom && !bathroom->getStatus())
            {
                msBathroom->lightOn();
                msKitchen->lightOff();
                msLivingroom->lightOff();
            }
            if(statusLivingRoom && !livingroom->getStatus())
            {
                if (!winDec->isUp())
                {
                    msLivingroom->lightOn();
				}
                msKitchen->lightOff();
                msBathroom->lightOff();
            }
            if(statusDoorSensor)
            {
                msKitchen->lightOff();
                msBathroom->lightOff();
                msLivingroom->lightOff();
            }
        }
        else
            if(!manualMode)
            {
                if(statusKitchen)
                    msKitchen->lightOn();
                else
                    msKitchen->lightOff();
                if(statusLivingRoom)
                {
                    msLivingroom->lightOn();
                    msBathroom->lightOff();
                }
                else
                    msLivingroom->lightOff();

                if(statusBathroom)
                    msBathroom->lightOn();
            }
        
        if(tempBath > 25.0) {
			cout<<"Kill water heater"<<endl;
			//digitalWrite(222, LOW);	// Placeholders
		} else if (tempBath < 25.0) {
			cout<<"Enable water heater"<<endl;
			//digitalWrite(222, HIGH);
		}
		
		if (tempLiving > 23.0) {
			winDec->down();
		} else {
			winDec->up();
		}
                
        this_thread::sleep_for(chrono::seconds(30)); // Moet lagere waarde krijgen, of light control een andere plek geven.
    }
	

}
void pollingTempSensor()
{
	while(1) {
		tempBathroom->readTemperature();
		tempLivingRoom->readTemperature();
		this_thread::sleep_for(chrono::seconds(5));
	}
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


