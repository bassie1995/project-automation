#include "light.h"

Light::Light(string i): status(0), address(i)
{}

Light::~Light()
{}

bool Light::getStatus() const
{
	return status;
}

string Light::getAddress() const
{
	return address;
}


void Light::setStatus(bool s)
{
	status=s;
}
