#include "light.h"
#include "sensor.h"

#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H

class MotionSensor : public Sensor
{
	public:
		MotionSensor(byte);
		void detectMotion();
	private:
		Light* pLight;
		byte address;
		byte val0;
		byte val1;
		int channelReading;
		float analogReadingArduino;
};

#endif
