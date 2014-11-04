#ifndef RGBLIGHT_H
#define RGBLIGHT_H

#include "light.h"
#include <iostream>
#include <string>
#include <sstream>																																																																																																																																																																										
#include <iomanip>
#include <stdlib.h>

using namespace std;

class RGBLight : public Light
{
	public:
		RGBLight(int);
		~RGBLight();
		void on();
		void off();
		void changeColor(int, int, int, int);
		void convertPerToHex(int, int, int, int);
	private:
		string red, green, blue, white, pred, pgreen, pblue, pwhite;
};

#endif
