#include "ipcamera.h"

IPCamera::IPCamera()
{}

void IPCamera::turnOn()
{
	status=true;
}

void IPCamera::turnOff()
{
	status=false;
}
