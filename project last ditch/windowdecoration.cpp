#include "windowdecoration.h"

WindowDecoration::WindowDecoration(int i): address(i), status(false)
{}
//min = 0.5ms and max = 2.5ms
//120 is in units of 10us by default, so that is 1200us, or 1.2ms.
void WindowDecoration::up()
{
	if (!status) {
		for(int i = 5; i<24; i++){
			string str = "sudo echo P1-" + to_string(address) + "=" + to_string(i*10) + " > /dev/servoblaster";
			system(str.c_str());
		}
		
		delay(10);
		status = true;
	}
}

void WindowDecoration::down()
{
	if (status) {
		for(int i=23; i>4; i--){
			string str = "sudo echo P1-" + to_string(address) + "=" + to_string(i*10) + " > /dev/servoblaster";
			system(str.c_str());
		}
		
		delay(10);
		status = false;
	}
}

bool WindowDecoration::isUp() const {
	return status;
}

// aapje
