#ifndef RGBLIGHT_H
#define RGBLIGHT_H

#include "Light.h"

class RGBLight : public Light
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
