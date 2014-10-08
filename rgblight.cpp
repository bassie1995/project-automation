#include "rgblight.h"

RGBLight::RGBLight(): red(0), green(0), blue(0)
{}

void RGBLight::changeColor(int r, int g, int b)
{
	if(r >= 0 && r <= 255)
		red=r;
	if(g >= 0 && g <= 255)
		green=g;
	if(b >= 0 && b <= 255)
		blue=b;
}
