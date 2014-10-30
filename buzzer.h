#ifndef BUZZER_H
#define BUZZER_H

class Buzzer
{
	public:
		Buzzer();
        void buzzOn(int a);
		void buzzOff();
        void getStatusDetector();
	private:
		bool status;
};

#endif
