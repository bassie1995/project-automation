#include "light.h"
#include "sensor.h"

#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H

class MotionSensor : public Sensor
{
	public:
		MotionSensor();
		void detectMotion();
	private:
		Light* pLight;
};

#endif
