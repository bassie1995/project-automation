//Include ArduPi library
#include "arduPi.h"

//Needed for Serial communication
SerialPi Serial;

//Needed for accesing GPIO (pinMode, digitalWrite, digitalRead, I2C functions)
WirePi Wire;

//Needed for SPI
SPIPi SPI;

/*********************************************************
 *  IF YOUR ARDUINO CODE HAS OTHER FUNCTIONS APART FROM  *
 *  setup() AND loop() YOU MUST DECLARE THEM HERE        *
 * *******************************************************/

/**************************
 * YOUR ARDUINO CODE HERE *
 * ************************/

int main (){
	setup();
	while(1){
		loop();
	}
	return (0);
}

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(2, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}