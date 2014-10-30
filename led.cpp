#include "led.h"
#include <string>

using namespace std;

LED(int tempAddress):Light(tempAddress)
{}

void LED::on()
{
	setStatus(true);
	for(int i=0; i<10; i++)
	{
		string str = "sudo echo P1-" + to_string(getAddress()) + "=" + to_string(i*10) + "% > /dev/servoblaster";
	}
}

void LED::off()
{
	setStatus(false);
	for(int i=0; i<10; i++)
	{
		string str = "sudo echo P1-" + to_string(getAddress()) + "=" + to_string(100-i*10) + "% > /dev/servoblaster";
	}
}
