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
        this_thread::sleep_for(chrono::seconds(2));
	}
}

void logicController() {
    bool statusKitchen;
    bool statusBathroom;
    bool statusLivingRoom;
    bool statusDetector;
    bool manualMode=false;
    
    bool statusDoorSensor=false;
    
    int test=0;
    while(1)
    {
        statusKitchen = msKitchen->isActive();
        statusBathroom = msBathroom->isActive();
        statusLivingRoom = msLivingroom->isActive();
        
        if(test>=3) {
			test=0; 
			statusDay = !statusDay;
		}       
        statusDetector = buttonSmokeDetector->isActive();
		cout<<test<<endl;
        statusDoorSensor = frontDoorSensor->isActive();

        cout<<"Is it day? "<<statusDay<<endl<<endl;

        if(statusDay) {
            if(/*statusKitchen*/test==0 && !(kitchen->getStatus()))
            {
                msKitchen->lightOn();
                msBathroom->lightOff();
                msLivingroom->lightOff();
            }

            if(/*statusBathroom*/test==1 && !(bathroom->getStatus()))
            {
                msBathroom->lightOn();
                msKitchen->lightOff();
                msLivingroom->lightOff();
            }
            if(/*statusLivingRoom*/test==2 && !(livingroom->getStatus()))
            {
                //~ if (!(winDec->isUp()))
                //~ {
					RGBLight* RGB = dynamic_cast<RGBLight*> (msLivingroom->getpLight());
					if(RGB)
						RGB->changeColor(10, 100, 100, 75);
				//~ }
                msKitchen->lightOff();
                msBathroom->lightOff();
            }
            if(statusDoorSensor)
            {
                msKitchen->lightOff();
                msBathroom->lightOff();
                msLivingroom->lightOff();
            }
        } else {
            if(/*statusKitchen*/test==0)
                msKitchen->lightOn();
            else
                msKitchen->lightOff();
            if(/*statusLivingRoom*/test==1)
            {
                RGBLight* RGB = dynamic_cast<RGBLight*> (msLivingroom->getpLight());
                if(RGB)
					RGB->changeColor(5, 0, 50, 20);
                msBathroom->lightOff();
            }
            else
                msLivingroom->lightOff();

            if(/*statusBathroom*/test==2)
                msBathroom->lightOn();
        }
        
        if(tempBathroom->getTemperature() > 24.0) {               // 42.0
			cout<<"Kill water heater"<<endl;
            //digitalWrite(222, LOW);	// Useless for the demo
        } else if (tempBathroom->getTemperature() <= 24.0) {       // 38.0
            cout<<"Re-enable water heater"<<endl;
			//digitalWrite(222, HIGH);
		}
		cout<<"tempLiving: "<< tempLivingRoom->getTemperature() <<endl;
		
		if (tempLivingRoom->getTemperature() > 24.0) {
			winDec->down();
			cout<<(winDec->isUp())<<endl;
		} else {
			cout<<(winDec->isUp())<<endl;
			winDec->up();
		}
        
        test++;
        
        this_thread::sleep_for(chrono::seconds(10));
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
	
    //system("sudo killall servod");    // Unreached code
	
	
	return 0;
}


