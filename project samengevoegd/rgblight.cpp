#include "rgblight.h"

using namespace std;

RGBLight::RGBLight(int i): red("00"), green("00"), blue("00"), white("00")
	, pred("00"), pgreen("00"), pblue("00"), pwhite("00")
	, Light(i) {
	
}

RGBLight::~RGBLight()
{}

void RGBLight::on() {
	system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/3 0F");
	system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/6 0F");
	system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/9 0F");
	system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/27 0F");
}

void RGBLight::off() {
	system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/3 00");
	system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/6 00");
	system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/9 00");
	system("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/27 00");
}

void RGBLight::changeColor(int r, int g, int b, int w) {
	convertPerToHex(r, g, b, w);
	
	if (pred != red) {
		system(("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/3 " + red).c_str());
	}
	if (pgreen != green) {
		system(("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/6 " + green).c_str());
		
	}
	if (pblue != blue) {
		system(("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/9 " + blue).c_str());
	}
	if (pwhite != white) {
		system(("/usr/local/bin/groupsocketwrite ip:127.0.0.1 0/0/27 " + white).c_str());
	}
	
	pred = red;
	pgreen = green;
	pblue = blue;
	pwhite = white;
}

void RGBLight::convertPerToHex(int r, int g, int b, int w) {
	stringstream stream;
	
	stream << setfill('0') << setw(2) << hex << r;
	red = stream.str();
	
	stream << setfill('0') << setw(2) << hex << g;
	green = stream.str();
	
	stream << setfill('0') << setw(2) << hex << b;
	blue = stream.str();
	
	stream << setfill('0') << setw(2) << hex << w;
	white = stream.str();
}
