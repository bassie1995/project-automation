#include "windowdecoration.h"
#include "buzzer.h"

#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
	public:
		Sensor();
        Sensor(Buzzer &);
        virtual ~Sensor();
		void activate();
		void deactivate();
        bool isActive() const;
	private:
		bool status;
		WindowDecoration* pWinDec;
		Buzzer* pBuzzer;
};

#endif
