#include "rgblight.h"

using namespace std;

RGBLight::RGBLight(): red("00"), green("00"), blue("00"), white("00") {
	
}

void RGBlight::on(){
	system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/3 " + red);
	system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/6 " + green);
	system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/9 " + blue);
	system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/27 " + white);
}

void RGBLight::off(){
	system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/3 " + 00);
	system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/6 " + 00);
	system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/9 " + 00);
	system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/27 " + 00);
}

void RGBLight::changeColor(int r, int g, int b, int w) {
	convertPerToHex(r, g, b, w);
	
	if (r != red) {
		system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/3 " + red);
		red = r;
	}
	if (g != green) {
		system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/6 " + green);
		green = g;
	}
	if (b != blue) {
		system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/9 " + blue);
		blue = b;
	}
	if (w != white) {
		system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/27 " + white);
		white = w;
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
