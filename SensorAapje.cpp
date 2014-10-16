#include "arduPi.h"
#include <iostream>
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

	while(1)
	{
		loop();
	}
	
	return 0;
}

void setup()
{
	Wire.begin();
}

void loop()
{	
	byte val0;
	byte val1;
	int channelReading;
	float analogReadingArduino;
	
// Sensor #1	
	Wire.beginTransmission(8);
	Wire.write(byte(0x9C));
	Wire.endTransmission();

	Wire.requestFrom(8,2);
	val0 = Wire.read();
	val1 = Wire.read();
	channelReading = int(val0)*16 + int(val1>>4);
	analogReadingArduino = channelReading * 1023 / 4095;
	
	if(analogReadingArduino > 5)
		cout<<"Aapje #1 gedetecteerd"<<endl;
		
	delay(100);
	
// Sensor #2		
	Wire.beginTransmission(8);
	Wire.write(byte(0xCC));
	Wire.endTransmission();

	Wire.requestFrom(8,2);
	val0 = Wire.read();
	val1 = Wire.read();
	channelReading = int(val0)*16 + int(val1>>4);
	analogReadingArduino = channelReading * 1023 / 4095;
	
	if(analogReadingArduino > 5)
		cout<<"Aapje #2 gedetecteerd"<<endl;
		
	delay(100);
	
// Sensor #3
	Wire.beginTransmission(8);
	Wire.write(byte(0x8C));
	Wire.endTransmission();

	Wire.requestFrom(8,2);
	val0 = Wire.read();
	val1 = Wire.read();
	channelReading = int(val0)*16 + int(val1>>4);
	analogReadingArduino = channelReading * 1023 / 4095;
	
	if(analogReadingArduino > 5)
		cout<<"Aapje #3 gedetecteerd"<<endl;
		
	delay(300);
}
