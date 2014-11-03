#include "windowdecoration.h"

WindowDecoration::WindowDecoration(/*int adresje place holder*/): adres(0/*adresje place holder*/), status(false)
{}
//min = 0.5ms and max = 2.5ms
//120 is in units of 10us by default, so that is 1200us, or 1.2ms.
void WindowDecoration::up()
{
	if (!status) {
		for(int i = 5; i<25; i++){
			string str = "sudo echo P1-" + to_string(adres) + "=" + to_string(i*10) + " > /dev/servoblaster";
			//system(str.c_str());
		}
		// move servo up, no testing possible so far
		delay(10);
		status = true;
	}
}

void WindowDecoration::down()
{
	if (status) {
		for(int i=24; i>4; i--){
			string str = "sudo echo P1-" + to_string(adres) + "=" + to_string(i*10) + " > /dev/servoblaster";
			//system(str.c_str());
		}
		// move servo down, no testing possible so far
		delay(10);
		status = false;
	}
}

bool WindowDecoration::isUp() const {
	return status;
}

// aapje
