#include <iostream>
#include "arduPi.h"
#include "light.h"
#include "sensor.h"
#include <string>

using namespace std;

#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H

class MotionSensor : public Sensor
{
	public:
		MotionSensor(int, Light*);
		void detectMotion(WirePi *);
        void lightOn();
        void lightOff();
	private:
		Light* pLight;
		int address;
		byte val0;
		byte val1;
		int channelReading;
		float analogReadingArduino;
};

#endif
