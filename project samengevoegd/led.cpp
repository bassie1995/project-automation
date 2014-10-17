#include "led.h"
#include <string>

using namespace std;

LED::LED(int tempAddress) : Light(tempAddress)
{}

void LED::on()
{
	Light::on();
	for(int i=0; i<10; i++)
	{
		string str = "sudo echo P1-" + to_string(getAddress()) + "=" + to_string(i*10) + "% > /dev/servoblaster";
	}
}

void LED::off()
{
	Light::off();
	for(int i=0; i<10; i++)
	{
		string str = "sudo echo P1-" + to_string(getAddress()) + "=" + to_string(100-i*10) + "% > /dev/servoblaster";
	}
}
