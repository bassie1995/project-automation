#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include "sensor.h"

class TemperatureSensor : public Sensor
{
	public:
		TemperatureSensor();
		int  getTemperature();
	private:
		int temperature;
};

#endif
