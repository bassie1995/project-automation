#include "windowdecoration.h"

WindowDecoration::WindowDecoration(): status(false)
{}

void WindowDecoration::up()
{
	if (!status) {
		// move servo up, no testing possible so far
		delay(10);
		status = true;
	}
}

void WindowDecoration::down()
{
	if (status) {
		// move servo down, no testing possible so far
		delay(10);
		status = false;
	}
}

bool WindowDecoration::isUp() {
	return status;
}

// aapje
