#ifndef LIGHT_H
#define LIGHT_H

#include <string>

using namespace std;

class Light
{
	public:
		Light(string);
		virtual ~Light();
		bool getStatus() const;
		void setStatus(bool);
		virtual void on();
		virtual void off();
		string getAddress() const;
	private:
		bool status;
		const string address;
};

#endif
