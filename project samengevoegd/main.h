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
#include "ipcamera.h"
#include <time.h>
#include <thread>
#include <iostream>
#include <string>
#include <chrono>


/*Light*/
Light kitchen(/*address on Rasberry*/);
LED bathroom(/*address on Rasberry*/);
RGBLight livingroom;

/*MOTION CONTROL*/
MotionSensor msKitchen("9C", &kitchen); // Vul hier ook de juiste adressen in
MotionSensor msBathroom("8C", &bathroom);
MotionSensor msLivingroom("CC" ,&livingRoom);

/*BUTTONS + BUZZER*/
Buzzer buzzerSmoke;
Sensor buttonBed;
Sensor buttonSmokeDetector(buzzerSmoke);
Switch nightDaySwitch;

/*TEMP SENSOREN*/
TemperatureSensor tempBathroom;
TemperatureSensor tempLiving;

#endif // MAIN_H
