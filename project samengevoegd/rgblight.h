#ifndef RGBLIGHT_H
#define RGBLIGHT_H

#include "Light.h"

class RGBLight : public Light
{
	public:
		RGBLight();
		void on();
		void off();
		void changeColor(int, int, int);
		void RGBLight::convertPerToHex(int, int, int, int);
	private:
		char red[3], green[3], blue[3], white[3];
};

#endif
