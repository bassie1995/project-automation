//Include ArduPi library
#include "arduPi.h"
#include <math.h>
#include <stdio.h>
#include <curl/curl.h>
//Needed for Serial communication
SerialPi Serial;

//Needed for accessing GPIO (pinMode, digitalWrite, digitalRead, I2C functions)
WirePi Wire;

//Needed for SPI
SPIPi SPI;

#define TH 20

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
	
	Wire.beginTransmission(8);
	Wire.write(byte(0x8C));
	Wire.endTransmission();

	Wire.requestFrom(8,2);
	val0 = Wire.read();
	val1 = Wire.read();
	channelReading = int(val0)*16 + int(val1>>4);
	analogReadingArduino = channelReading * 1023 / 4095;
	
	if(analogReadingArduino < TH)
		printf("Getting lighter\n");
	else
		printf("Getting darker\n");
	
	//printf("%f\n",analogReadingArduino);
	delay(3000);
}
