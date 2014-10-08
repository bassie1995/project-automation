#include "switch.h"

Switch::Switch(): status(0)
{}

bool Switch::getStatus() const
{
	return status;
}

void Switch::setStatus(bool s)
{
	status=s;
}
