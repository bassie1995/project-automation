#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include "sensor.h"
#include <string>
#include <sstream>
#include <iostream>
#include <bitset>
#include <math.h>

class TemperatureSensor : public Sensor
{
	public:
		TemperatureSensor(int);
		int  getTemperature();
        void readTemperature();
	private:
		int ident;
		int temperature;
};

#endif
