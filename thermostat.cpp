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

#define HUNKRESISTOR 100000
#define BETA 4500
#define THERMISTOR 100000
#define ROOMTEMPK 294.15
#define READINGS 7
#define SETPOINT 23.0

/*********************************************************
 *  IF YOUR ARDUINO CODE HAS OTHER FUNCTIONS APART FROM  *
 *  setup() AND loop() YOU MUST DECLARE THEM HERE        *
 * *******************************************************/

/**************************
 * YOUR ARDUINO CODE HERE *
 * ************************/

bool running = false;

int main (){
	setup();
	while(1){
		loop();
	}
	return (0);
}


void setup()
{
	printf("starting up thermostat\n");
	Wire.begin();
}

void loop()
{
	float avResistance;
	float resistance;
	int combinedReadings[READINGS];
	byte val0;
	byte val1;
	
	float kelvin;
	float celsius;
	int channelReading;
	float analogReadingArduino;
	
	CURL* curlInst;
	CURLcode result;
	
	Wire.beginTransmission(8);
	Wire.write(byte(0xCC)); // 0xDC = analog pin 0 8C(A3) of (A2)
	Wire.endTransmission();
	for(int r=0; r<READINGS; r++)
	{
		Wire.requestFrom(8,2);
		val0 = Wire.read();
		val1 = Wire.read();
		channelReading = int(val0)*16 + int (val1>>4);
		analogReadingArduino = channelReading * 1023 / 4095;
		combinedReadings[r] = analogReadingArduino;
		delay(100);
	}
	avResistance = 0;
	for(int r=0; r<READINGS; r++)
	{
		avResistance += combinedReadings[r];
	}
	avResistance /= READINGS;
	avResistance = (1023 / avResistance) - 1;
	avResistance = HUNKRESISTOR / avResistance;
	resistance = avResistance / THERMISTOR;
	kelvin = log(resistance);
	kelvin /= BETA;
	kelvin += 1.0 / ROOMTEMPK;
	kelvin = 1.0 / kelvin;
	printf("Temperature in K: %f \n", kelvin);
	celsius = kelvin -= 273.15;
	printf("Temperature in C: %f \n", celsius);
	if(celsius > SETPOINT && !running)
	{
		printf("Switching fan on\n");
		running = true;
	}
	else if(celsius < SETPOINT && running)
	{
		printf("Switching fan off\n");
		running = false;
	}
	
	curlInst = curl_easy_init();
	if(curlInst)
	{
		char url[40];
		sprintf(url, "http://145.52.126.185/addtemperature?temperature=%f&room=1", celsius);
		curl_easy_setopt(curlInst, CURLOPT_URL, url);
		result = curl_easy_perform(curlInst);
		if(result != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(result));
		curl_easy_cleanup(curlInst);
		printf("\n");
	}
	
	delay(3000);
}

