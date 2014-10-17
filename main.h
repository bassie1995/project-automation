#ifndef MAIN_H
#define MAIN_H
#include <time.h>
#include <thread>
#include <iostream>
#include <string>
#include <chrono>
#include "rgblight.h"
#include "led.h"
#include "switch.h"
#include "sensor.h"
#include "motionsensor.h"
#include "temperaturesensor.h"
#include "windowdecoration.h"
#include "buzzer.h"
#include "ipcamera.h"

/*Light*/
Light kitchen(/*address on Rasberry*/);
Led bathroom(/*address on Rasberry*/);
RGBLight livingroom();

/*MOTION CONTROL*/
MotionSensor msKitchen(0x9C, &kitchen); // Vul hier ook de juiste adressen in
MotionSensor msBathroom(0x8C, &bathroom);
MotionSensor msLivingroom(0xCC ,&livingRoom);

/*BUTTONS + BUZZER*/
Buzzer buzzerSmoke();
Sensor buttonBed();
Sensor buttonSmokeDetector(&buzzerSmoke);
Switch nightDaySwitch();

/*TEMP SENSOREN*/
TemperatureSensor tempBathroom();
TemperatureSensor tempLiving();

#endif // MAIN_H
