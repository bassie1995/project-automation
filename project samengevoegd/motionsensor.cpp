#include "motionsensor.h"

using namespace std;

MotionSensor::MotionSensor(int msaddress, Light* pL): pLight(pL), address(msaddress)
{}

void MotionSensor::detectMotion(WirePi *Wire) {
	//cout<<"DMotion"<<endl;
	
	//Wire->beginTransmission(8);
	//Wire->write(address);
	//Wire->endTransmission();
	//cout<<"DMotion2"<<endl;
	//~ Wire->requestFrom(8,2);
	//~ val0 = Wire->read();
	//~ val1 = Wire->read();
	//channelReading = int(val0)*16 + int(val1>>4);
	//analogReadingArduino = channelReading * 1023 / 4095;
	//cout<<"DMotion3"<<endl;
	//~ if(analogReadingArduino > 6)
	//~ {
		//~ activate();
	//~ }
	//~ else{
		//~ deactivate();
	//~ }
	
	
}

void MotionSensor::lightOn() {
    pLight->on();
}

void MotionSensor::lightOff() {
    pLight->off();
}
