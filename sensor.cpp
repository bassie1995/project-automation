#include "sensor.h"
#include <iostream>

using namespace std;

Sensor::Sensor(): status(0), pBuzzer(0), pWinDec(0)
{
}

Sensor::Sensor(Buzzer &b): status(0), pBuzzer(&b), pWinDec(0){

}

Sensor::~Sensor()
{}

bool Sensor::getStatus() const
{
    return status;
}
void setStatus(bool s)
{
    status = s;
}

void Sensor::activate()
{
	status=true;
}

void Sensor::deactivate()
{
	status=false;
}
void Sensor::IsActive()
{
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
