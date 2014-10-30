#ifndef LED_H
#define LED_H

#include "light.h"

class LED : public Light
{
	public:
		LED(int);
		void on();
		void off();

	private:
		
};

#endif
