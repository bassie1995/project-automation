#include "buzzer.h"
#include <iostream>

using namespace std;

Buzzer::Buzzer(): status(0), address(29383) // Placeholderino
{}

void Buzzer::buzzOn()
{
	status=true;
	// aan waarde sturen naar buzzer poort
}

void Buzzer::buzzOff()
{
	status=false;
}
void Buzzer::getStatusDetector()
{

}
