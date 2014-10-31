#ifndef WINDOWDECORATION_H
#define WINDOWDECORATION_H

#include "arduPi.h"

using namespace std;

class WindowDecoration
{
	public:
		WindowDecoration();
		void up();
		void down();
		bool isUp();
	private:
		bool status;
};

#endif
