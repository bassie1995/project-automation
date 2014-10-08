#include "temperaturesensor.h"

TemperatureSensor::TemperatureSensor()
{}

void TemperatureSensor::setTemperature(int t)
{
	temperature=t;
}

int TemperatureSensor::getTemperature()
{
	return temperature;
}
