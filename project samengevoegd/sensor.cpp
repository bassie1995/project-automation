#include "sensor.h"
#include <iostream>

using namespace std;

Sensor::Sensor(): status(0), pBuzzer(0)//, pWinDec(0)
{
}

Sensor::Sensor(Buzzer &b): status(0), pBuzzer(&b)//, pWinDec(0)
{

}

Sensor::~Sensor()
{}

void Sensor::activate()
{
	status=true;
}

void Sensor::deactivate()
{
	status=false;
}

bool Sensor::isActive() const
{
	return status;
    //detect ingedrukt
    // activeer

//    while(1){
//    for(int i=0;i<640000000;i++)
//    {
//        // dit wordt een delay
//    }
//   cout<<"testSensor"<<endl;  // hier komt de polling code

//    }


    // deactiveer

}
