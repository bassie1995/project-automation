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
#define DIRECTION 5
#define PWMPIN 3

pthread_t pwmthread;
pthread_mutex_t pwmmutex = PTHREAD_MUTEX_INITIALIZER;

bool off_on;
bool open_state;

void* pwm(void *args){
	while(1){
		if(off_on){
			digitalWrite(3, HIGH);
			delayMicroseconds(300);
			digitalWrite(3, LOW);
			delayMicroseconds(1000-100);
		} else {
			digitalWrite(3,LOW);
		}
	}
	return NULL;
}

void controlMotor(bool state){
	pthread_mutex_lock(&pwmmutex);
	off_on = state;
	pthread_mutex_unlock(&pwmmutex);
}

int main(void){
	setup();
	while(1){
		loop();
		delay(100);
	}
	return 0;
}

void setup(){
	pthread_create(&(pwmthread), NULL, &pwm, NULL);
	pinMode(DIRECTION, OUTPUT);
	Wire.begin();
}

void loop(){
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
	
	if (analogReadingArduino > TH && !open_state){
		controlMotor(true);
		digitalWrite(DIRECTION, HIGH);
		delay(5000);
		open_state = true;
		controlMotor(false);
	} else {
		if(analogReadingArduino < TH && open_state){
			controlMotor(true);
			digitalWrite(DIRECTION, LOW);
			delay(5000);
			open_state = false;
			controlMotor(false);
		}
	}
}
