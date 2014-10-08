#ifndef LIGHT_H
#define LIGHT_H

class Light
{
	public:
		Light();
		virtual ~Light();
		bool getStatus() const;
		virtual void on();
		virtual void off();
	private:
		bool status;
};

#endif
