#include "buzzer.h"
#include <iostream>

using namespace std;

Buzzer::Buzzer(): status(0)
{}

void Buzzer::buzzOn()
{
	status=true;
    cout<<"testbuzz"<<endl;
}

void Buzzer::buzzOff()
{
	status=false;
}
void Buzzer::getStatusDetector()
{
//    while(1){
//    for(int i=0;i<640000000;i++)
//    {
//        // dit wordt een delay
//    }
//   cout<<"testBuzzer"<<endl;  // hier komt de motioncode
//    }
}
