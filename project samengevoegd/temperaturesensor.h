#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include "sensor.h"

class TemperatureSensor : public Sensor
{
	public:
		TemperatureSensor();
		int  getTemperature();
        void readTemperature();
	private:
		int temperature;
};

#endif
