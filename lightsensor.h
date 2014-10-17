#include "sensor.h"

#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

class LightSensor : public Sensor
{
	public:
		LightSensor();
		int getLightIntensity();
	private:
		int LightIntensity;
};

#endif