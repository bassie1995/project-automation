#ifndef BUZZER_H
#define BUZZER_H

class Buzzer
{
	public:
		Buzzer();
		void buzzOn();
		void buzzOff();
        void getStatusDetector();
	private:
		bool status;
		int address;
};

#endif
