#ifndef WINDOWDECORATION_H
#define WINDOWDECORATION_H

#include "arduPi.h"

using namespace std;

class WindowDecoration
{
	public:
		WindowDecoration(int);
		void up();
		void down();
		bool isUp() const;
	private:
		bool status;
		const int address;
};

#endif
