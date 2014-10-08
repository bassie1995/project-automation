#include "sensor.h"

Sensor::Sensor(): status(0), pBuzzer(0), pWinDec(0)
{}

Sensor::~Sensor()
{}
	
bool Sensor::getStatus() const
{
	return status;
}

void Sensor::activate()
{
	status=true;
}

void Sensor::deactivate()
{
	status=false;
}
