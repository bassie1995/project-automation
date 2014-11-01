#ifndef WINDOWDECORATION_H
#define WINDOWDECORATION_H

#include "arduPi.h"

using namespace std;

class WindowDecoration
{
	public:
		WindowDecoration(/*int adresje place holder*/);
		void up();
		void down();
		bool isUp() const;
	private:
		bool status;
		int adres;
};

#endif
