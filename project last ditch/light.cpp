#include "light.h"

Light::Light(int i): status(false), address(i)
{}

Light::~Light()
{}

bool Light::getStatus() const
{
	return status;
}

int Light::getAddress() const
{
	return address;
}

void Light::on()
{
	status=true;
}

void Light::off()
{
	status=false;
}	
