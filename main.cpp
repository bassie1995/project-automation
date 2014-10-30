#include "rgblight.h"
#include "led.h"
#include "switch.h"
#include "Sensor.h"
#include "motionsensor.h"
#include "temperaturesensor.h"
#include "windowdecoration.h"
#include "buzzer.h"
#include "ipcamera.h"
#include <thread>
#include <iostream>

using namespace std;

int main()
{/*
    Sensor *msKitchen = new MotionSensor();
    Sensor *msBathroom = new MotionSensor();
    Sensor *msLivingRoom = new MotionSensor();
    Sensor *buttonBed = new Sensor();
    Sensor *buttonSmokeDetector = new Sensor();

    Sensor  *tempRoom = new TemperatureSensor();
    Sensor  *tempBathroom  = new TemperatureSensor();

    Light *lightLivingroom = new RGBLight();
    Light *lightBathroom = new LED();
    Light *lightKitchen = new LED();

    Buzzer *buzzerSmoke = new Buzzer();

    IPCamera *camera = new IPCamera();

    Switch *switchSystem = new Switch();

    WindowDecoration *windowDeco = new WindowDecoration();
*/
    /*MOTION CONTROL*/
   //  MotionSensor msKitchen;
   //  MotionSensor msLivingroom;
    // MotionSensor msBathroom;

   // thread t1(&MotionSensor::detectMotion,msKitchen);
    //thread t2(&MotionSensor::detectMotion,msLivingroom);
   // thread t3(&MotionSensor::detectMotion,msBathroom);





    /*BUTTONS + BUZZER*/
      Buzzer buzzerSmoke;
    //  Sensor buttonBed;
    //  Sensor buttonSmokeDetector(buzzerSmoke);

    //  thread t4(&Sensor::IsActive,buttonBed);
    // thread t5(&Sensor::IsActive,buttonSmokeDetector);
    /*TEMP SENSOREN*/

     // TemperatureSensor tempBathroom;
     // TemperatureSensor tempLiving;
     // thread t6(&TemperatureSensor::readTemperature,tempLiving);
      //  t1.detach();

      int a;
      puts ("Press a for buzzer. Press 'exit'.");
      do{
        a=getchar();
        buzzerSmoke.buzzOn(a);
      } while (a != '.');

  //  while(1){}
    return 0;
}


