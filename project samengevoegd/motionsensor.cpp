#include "motionsensor.h"

using namespace std;

MotionSensor::MotionSensor(string msaddress, Light* pL): pLight(pL), address(msaddress)
{}

void MotionSensor::detectMotion(WirePi *Wire)
{
	const char* temp;
	temp = address.c_str();
	
	Wire->beginTransmission(8);
	Wire->write(temp);
	Wire->endTransmission();

	Wire->requestFrom(8,2);
	val0 = Wire->read();
	val1 = Wire->read();
	channelReading = int(val0)*16 + int(val1>>4);
	analogReadingArduino = channelReading * 1023 / 4095;
	
	if(analogReadingArduino > 6)
	{
		activate();
	}
	else{
		deactivate();
	}
}
void MotionSensor::lightOn(){
    pLight->on();
}
void MotionSensor::lightOff()
{
    pLight->off();
}
