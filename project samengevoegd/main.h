#ifndef MAIN_H
#define MAIN_H

#include "rgblight.h"
#include "led.h"
#include "switch.h"
#include "sensor.h"
#include "motionsensor.h"
#include "temperaturesensor.h"
#include "windowdecoration.h"
#include "buzzer.h"

#define ANALOG_0 220
#define ANALOG_1 156
#define ANALOG_2 204
#define ANALOG_3 140
#define ANALOG_4 172
#define ANALOG_5 236
#define ANALOG_6 188
#define ANALOG_7 252

LED* kitchen = new LED(12);	// Eigenlijk een gloeilamp	
LED* bathroom = new LED(16);
RGBLight* livingroom = new RGBLight(696);	// placeholder

MotionSensor* msKitchen = new MotionSensor(ANALOG_1, kitchen);	// Vul hier ook de juiste adressen in
MotionSensor* msBathroom = new MotionSensor(ANALOG_2, bathroom);
MotionSensor* msLivingroom = new MotionSensor(ANALOG_3, livingroom);

Buzzer* buzzerSmoke = new Buzzer();

Sensor* buttonSmokeDetector = new Sensor();
Sensor* frontDoorSensor = new Sensor();

Switch* nightDaySwitch = new Switch();

WindowDecoration* winDec = new WindowDecoration();

TemperatureSensor* tempBathroom = new TemperatureSensor("0/0/51");
TemperatureSensor* tempLivingRoom = new TemperatureSensor("0/0/50");

#endif // MAIN_H
