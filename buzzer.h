#ifndef BUZZER_H
#define BUZZER_H

class Buzzer
{
	public:
		Buzzer();
		void buzzOn();
		void buzzOff();
	private:
		bool status;
};

#endif
