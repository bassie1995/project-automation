#ifndef RGBLIGHT_H
#define RGBLIGHT_H

#include "led.h"

class RGBLight : public LED
{
	public:
		RGBLight();
		void changeColor(int, int, int);
	private:
		int red;
		int green;
		int blue;
};

#endif
