#include "buzzer.h"

Buzzer::Buzzer(): status(0)
{}

void Buzzer::buzzOn()
{
	status=true;
}

void Buzzer::buzzOff()
{
	status=false;
}
