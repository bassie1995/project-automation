#include "windowdecoration.h"
#include "buzzer.h"

#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
	public:
		Sensor();
		virtual ~Sensor();
		bool getStatus() const;
		void activate();
		void deactivate();
	private:
		bool status;
		WindowDecoration* pWinDec;
		Buzzer* pBuzzer;
};

#endif
