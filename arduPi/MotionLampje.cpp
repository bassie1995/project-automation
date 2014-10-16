#include "arduPi.h"
#include <iostream>
#include <string>

/*
 * 0 = DC
 * 1 = 9C
 * 2 = CC
 * 3 = 8C
 * 4 = AC
 * 5 = EC
 * 6 = BC
 * 7 = FC
 */
SerialPi Serial;
WirePi Wire;
SPIPi SPI;

using namespace std;

int main()
{
	setup();
/*
	while(1)
	{
		loop();
	}*/
	for(int i=0; i<10; i++)
	{
		string str = "sudo echo 0=" + to_string(i*10) + "% > /dev/servoblaster";
		system(str.c_str());
		delay(30);
	}
	for(int i=0; i<10; i++)
	{
		string str = "sudo echo 0=" + to_string(100-i*10) + "% > /dev/servoblaster";
		system(str.c_str());
		delay(30);
	}
	//system("sudo killall servod");
	
	return 0;
}

void setup()
{
	//system("sudo ./servod --min=0 --max=100% --p1pins=\"16\"");
}

void loop()
{
	
}
