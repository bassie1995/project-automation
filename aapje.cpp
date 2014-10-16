#include "arduPi.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <bitset>
#include <math.h>

using namespace std;

int main()
{
	FILE *fp;
	char res[50];
	
	fp = popen("/usr/local/bin/groupsocketlisten ip:127.0.0.1", "r");
	if (fp == NULL) {
		cout << "No commando" << endl;
	}
	
	while(fgets(res, sizeof(res), fp) != NULL) {
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
		
		cout << res << endl;
	}
	
	pclose(fp);		
	
	return 0;
}
