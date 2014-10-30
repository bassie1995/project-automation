#include <vector>
#include "light.h"

using namespace std;

#ifndef SWITCH_H
#define SWITCH_H

class Switch
{
	public:
		Switch();
		bool getStatus() const;
		void setStatus(bool);
	private:
		bool status;
		vector<Light*> vLight;
};

#endif
