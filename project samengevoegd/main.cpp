#include "arduPi.h"
#include "ipcamera.h"
#include "main.h"

#include <time.h>
#include <thread>
#include <iostream>
#include <string>
#include <chrono>

using namespace std;



void setup() {
	// Activate PWM for the 2 LED lights
	
	system("/usr/local/bin/eibd -D -S -T -i --eibaddr=0.0.1 --daemon=/var/log/eibd.log --no-tunnel-client-queuing ipt:145.52.126.174");
	system("sudo /home/pi/PiBits/ServoBlaster/user/servod --min=0 --max=100% --p1pins=\"15\"");
    system("sudo /home/pi/PiBits/ServoBlaster/user/servod --min=0 --max=100% --p1pins=\"16\"");
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
    bool manualMode;
    
    float tempBath;
    float tempLiving;
    
    while(1)
    {

        if (statusDay)
			nightDaySwitch->deactivate();
        else
			nightDaySwitch->activate();

		
		// cout<<"aapje logiccontroller"<<endl;
        statusKitchen = msKitchen->isActive();
        statusBathroom = msBathroom->isActive();
        statusLivingRoom = msLivingroom->isActive();
        
        statusDay = nightDaySwitch->isActive();
        
        statusDetector = buttonSmokeDetector->isActive();
 
        statusDoorSensor = frontDoorSensor->IsActive();

        if(statusDay && !manualMode)
        {
            if(statusKitchen)
            {
                msKitchen->lightOn();
                msBathroom->lightOff();
                msLivingroom->lightOff();
            }

            if(statusBathroom)
            {
                msBathroom->lightOn();
                msKitchen->lightOff();
                msLivingroom->lightOff();
            }
            if(statusLivingRoom)
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
                
        this_thread::sleep_for(chrono::seconds(30)); // Moet lagere waarde krijgen, of light control een andere plek geven.
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


