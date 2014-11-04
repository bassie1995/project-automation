//#include "windowdecoration.h"
#include "buzzer.h"

#ifndef SENSOR_H
#define SENSOR_H

using namespace std;

class Sensor
{
	public:
		Sensor();
        Sensor(Buzzer &);
		virtual ~Sensor();
		void activate();
		void deactivate();
        bool isActive() const;
        void buzzOn();
        void buzzOff();
	private:
		bool status;
		//WindowDecoration* pWinDec;
		Buzzer* pBuzzer;
};

#endif
