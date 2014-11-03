#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include "sensor.h"
#include <string>
#include <sstream>
#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;
class TemperatureSensor : public Sensor
{
	public:
		TemperatureSensor(string);
		double  getTemperature();
        void readTemperature();
	private:
		string ident;
		double temperature;
};

#endif
