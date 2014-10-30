#include "light.h"

Light::Light(int i): status(0), address(i)
{}

Light::~Light()
{}

bool Light::getStatus() const
{
	return status;
}

int Light::getAddress()
{
	return address;
}

void Light::setAddress(int i)
{
	address=i;
}

void Light::setStatus(bool s)
{
	status=s;
}
