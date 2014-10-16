#include "rgblight.h"

using namespace std;

RGBLight::RGBLight(): red("00"), green("00"), blue("00"), white("00") {
	
}

void RGBLight::changeColor(int r, int g, int b, int w) {
	convertPerToHex(r, g, b, w);
	
	if (r != red) {
		system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/3 " + red);
	}
	if (g != green) {
		system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/6 " + green);
	}
	if (b != blue) {
		system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/9 " + blue);
	}
	if (w != white) {
		system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/27 " + white);
	}
}

void RGBLight::convertPerToHex(int r, int g, int b, int w) {
	stringstream stream;
	char buffer[3];
	
	r = (r * 2.55) + 0.5;
	g = (g * 2.55) + 0.5;
	b = (b * 2.55) + 0.5;
	w = (w * 2.55) + 0.5;
	
	itoa(r, red, 16);
	itoa(g, green, 16);
	itoa(b, blue, 16);
	itoa(w, white, 16);
}
