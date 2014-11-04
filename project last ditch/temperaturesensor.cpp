#include "temperaturesensor.h"

using namespace std;

TemperatureSensor::TemperatureSensor(string identity) : ident(identity)
{}

double TemperatureSensor::getTemperature()
{
	return temperature;
}

void TemperatureSensor::readTemperature()
{
	aapje:
	FILE *fp;
	char res[50];
	
	fp = popen(("/usr/local/bin/groupreadresponse ip:127.0.0.1 " + ident).c_str(), "r");
	if (fp == NULL) {
		cout << "No commando" << endl;
	}
	
	while(fgets(res, sizeof(res), fp) != NULL) {
		
		string str(res);
		
		int positie = str.find(":");
		if(positie == 19){
			str = str.substr(positie + 2, 5).replace(2, 1, "");
					
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
	}
	
	pclose(fp);
	
	cout<<"Temperature = "<<temperature<<endl;
}

