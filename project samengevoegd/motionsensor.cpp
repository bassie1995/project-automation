#include "motionsensor.h"

using namespace std;

MotionSensor::MotionSensor(int msaddress, Light* pL): pLight(pL), address(msaddress)
{}

void MotionSensor::detectMotion(WirePi *Wire) {

    Wire->beginTransmission(8);
    Wire->write(address);
    Wire->endTransmission();
    
    Wire->requestFrom(8,2);
    val0 = Wire->read();
    val1 = Wire->read();
    
    channelReading = int(val0)*16 + int(val1>>4);
    analogReadingArduino = channelReading * 1023 / 4095;
    
    if(analogReadingArduino > 6)
    {
        activate();
        cout<<"detectMotion Activated"<<endl;
        lightOn();
    }
    else{
        deactivate();
        cout<<"detectMotion Deactivated"<<endl;
        lightOff();
    }
	
	
}

void MotionSensor::lightOn() { // logic for turning on the lights /w timing
    //if(/*nightDaySwitch->isActive()*/) // DAY
    //{
        pLight->on();
    //}
    //else //NIGHT
    
}

void MotionSensor::lightOff() { // logic for turning off the lights /w timing
    pLight->off();
}
