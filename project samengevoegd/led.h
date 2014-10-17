#ifndef LED_H
#define LED_H

#include "light.h"

#include <string>

using namespace std;

class LED : public Light
{
	public:
		LED(int);
		void on();
		void off();

	private:
		
};

#endif
