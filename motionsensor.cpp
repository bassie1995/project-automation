#include "motionsensor.h"
#include <iostream>
#include "arduPi.h"

using namespace std;

MotionSensor::MotionSensor(byte msadres, Light* pL): pLight(pL), address(msaddress)
{}

void MotionSensor::detectMotion()
{
	SerialPi Serial;
	WirePi Wire;
	SPIPi SPI;
	
	Wire.begin();
	
    while(1)
    {	
		Wire.beginTransmission(8);
		Wire.write(byte(address));
		Wire.endTransmission();

		Wire.requestFrom(8,2);
		val0 = Wire.read();
		val1 = Wire.read();
		channelReading = int(val0)*16 + int(val1>>4);
		analogReadingArduino = channelReading * 1023 / 4095;
		
		if(analogReadingArduino > 6)
		{
			pLight->on();
		}
		
		delay(100);
	}
}
