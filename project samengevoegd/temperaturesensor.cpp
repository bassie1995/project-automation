#include "temperaturesensor.h"

using namespace std;

TemperatureSensor::TemperatureSensor(int identity) : ident(identity)
{}

int TemperatureSensor::getTemperature()
{
	return temperature;
}

void TemperatureSensor::readTemperature()
{
	// This has to be manually polled, is now influenced by the auto-poller.
	
	FILE *fp;
	char res[50];
	
	fp = popen("/usr/local/bin/groupsocketlisten ip:127.0.0.1", "r");
	if (fp == NULL) {
		cout << "No commando" << endl;
	}
	
	while(fgets(res, sizeof(res), fp) != NULL) {
		// Compare with ident to get the right sensor
		
		string str(res);
		
		str = str.substr(28, 5).replace(2, 1, "");
		
		stringstream ss;
		ss<<hex<<str;
		unsigned n;
		ss>>n;
		bitset<16> b(n);
		
		string bin = b.to_string();
		
		unsigned long int exponent = strtoul(bin.substr(1, 4).c_str(), NULL, 2);
		unsigned long int mantissa = strtoul(bin.substr(5, 11).c_str(), NULL, 2);
		
		double res = ((pow(2,exponent)*mantissa)/100);
		
		temperature = res;
	}
	
	pclose(fp);
}

