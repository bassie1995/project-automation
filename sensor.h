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
        bool getStatus() const;
        void setStatus(bool);
		void activate();
		void deactivate();
        void IsActive();
	private:
		bool status;
		WindowDecoration* pWinDec;
		Buzzer* pBuzzer;
};

#endif
