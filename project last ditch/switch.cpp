#include "switch.h"

Switch::Switch(): status(0)
{}

bool Switch::isActive() const
{
	return status;
}

void Switch::activate()
{
	status=true;
}

void Switch::deactivate() {
	status = false;
}
