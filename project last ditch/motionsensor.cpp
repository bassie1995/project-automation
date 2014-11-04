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
    
    channelReading = (int)((val0)*16) + (int)(val1>>4);
    analogReadingArduino = (channelReading * 1023) / 4095;
    
    if(analogReadingArduino > 6) {
        activate();
        cout<<"Motion = "<<analogReadingArduino<<", detectMotion Activated"<<endl;
        lightOn();
    } else {
        deactivate();
        cout<<"Motion = "<<analogReadingArduino<<", detectMotion Deactivated"<<endl;
        lightOff();
    }	
}

void MotionSensor::lightOn() { // logic for turning on the lights /w timing
    pLight->on();
}

void MotionSensor::lightOff() { // logic for turning off the lights /w timing
    pLight->off();
}

void MotionSensor::setColor(int r, int g, int b, int w) {
    pLight->changeColor(r, g, b, w);
}
