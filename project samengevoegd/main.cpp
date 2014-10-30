#include "main.h"

using namespace std;

void setup(){
	// Activate PWM for the 2 LED lights
	string start = "sudo ./home/pi/PiBits/ServoBlaster/user/servod --min=0 --max=100% --p1pins=\"" + to_string(/* VUL ADRES IN L1 */) + "\"";
	system(start.c_str());
	start = "sudo ./home/pi/PiBits/ServoBlaster/user/servod --min=0 --max=100% --p1pins=\"" + to_string(/* VUL ADRES IN L2 */) + "\"";
	system(start.c_str());
}

void pollingMSandButtons(){

	SerialPi Serial;
	WirePi Wire;
	SPIPi SPI;

	Wire.begin();

	while(1){
		msKitchen.detectMotion(&Wire);
        msBathroom.detectMotion(&Wire);
        msLivingroom.detectMotion(&Wire);

        buttonSmokeDetector.IsActive();
		buttonBed.IsActive();
	}
}
void Logic_Controller(){
    bool statusKitchen;
    bool statusBathroom;
    bool statusLivingRoom;
    bool statusDay;
    bool statusDetector;
    while(1)
    {
        statusKitchen = msKitchen.getStatus();
        statusBathroom = msbathroom.getStatus();
        statusLivingRoom =  mslivingroom.getStatus();
        nightDaySwitch.getStatus();
        statusDetector = buttonSmokeDetector.getStatus();

        if(statusDay) //true als het dag is
        {
            if(statusKitchen)
            {
                msKitchen.lightOn();
            }
            else{
// hier komt de uit fuctie
            }
            if(statusBathroom)
            {
                msBathroom.lightOn();
            }
            else
            {
 // hier komt de uit fuctie
            }
            if(statusLivingRoom)
            {
                msLivingroom.lightOn();
            }
            else{
// hier komt de uit fuctie
            }
        }
        else // hier als het nacht is
        {

        }
        if(statusDetector)
        {
            buttonSmokeDetector.pBuzzer->buzzOn();
        }
        else{
            buttonSmokeDetector.pBuzzer->buzzOff();
        }
    }


}
void pollingTempSensor()
{
    sleep_for(std::chrono::seconds(3));


}

int main()
{
	void setup();


	
	threads pollingQuick(pollingMSandButtons);
    threads pollingSlow(pollingTempSensor);

	/*Threads*/
/*	thread ms1(&MotionSensor::detectMotion,msKitchen);
	thread ms2(&MotionSensor::detectMotion,msLivingroom);
	thread ms3(&MotionSensor::detectMotion,msBathroom);
	

	thread bb(&Sensor::IsActive,buttonBed);
	thread sd(&Sensor::IsActive,buttonSmokeDetector);
		  
	thread rt(&TemperatureSensor::readTemperature,tempLiving);
	
	//thread timer(&);
*/
	while(1){}
	return 0;
}


