#ifndef LIGHT_H
#define LIGHT_H

class Light
{
	public:
		Light(int);
		virtual ~Light();
		bool getStatus() const;
		void setStatus(bool);
		virtual void on();
		virtual void off();
		int getAddress() const;
	private:
		bool status;
		const int address;
};

#endif
