#include "led.h"
#include <string>
#include <iostream>

using namespace std;

LED::LED(int tempAddress) : Light(tempAddress)
{}

void LED::on()
{
	Light::on();

    if(true)
        for(int i=10; i<=100; i=i+10)
        {
            string str = "sudo echo P1-" + to_string(getAddress()) + "=" + to_string(i) + "% > /dev/servoblaster";
            system(str.c_str());
        }
    else
        for(int i=10; i<=50; i=i+10)
        {
            string str = "sudo echo P1-" + to_string(getAddress()) + "=" + to_string(i) + "% > /dev/servoblaster";
            system(str.c_str());
        }
}

void LED::off()
{
    Light::off();

    if(true)
        for(int i=10; i<=100; i=i+10)
        {
            string str = "sudo echo P1-" + to_string(getAddress()) + "=" + to_string(100-i) + "% > /dev/servoblaster";
            system(str.c_str());
        }
    else
        for(int i=10; i<=50; i=i+10)
        {
            string str = "sudo echo P1-" + to_string(getAddress()) + "=" + to_string(50-i) + "% > /dev/servoblaster";
            system(str.c_str());
        }
    string temp="sudo echo P1-"  + to_string(getAddress()) + "=0% > /dev/servoblaster";
    system(temp.c_str()); // Temporarily hard write a 0 to turn off lights in case day/night status switches halfway through.
}
