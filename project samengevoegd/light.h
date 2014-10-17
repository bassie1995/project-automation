#ifndef LIGHT_H
#define LIGHT_H

#include <string>

using namespace std;

class Light
{
	public:
		Light(int);
		virtual ~Light();
		bool getStatus() const;
		virtual void on();
		virtual void off();
		int getAddress() const;
	private:
		bool status;
		const int address;
};

#endif
