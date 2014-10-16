#ifndef LIGHT_H
#define LIGHT_H

class Light
{
	public:
		Light(int);
		virtual ~Light();
		bool getStatus() const;
		void setStatus(bool);
		virtual void on() =0;
		virtual void off() =0;
		int getAddress();
		void setAddress(int);		
	private:
		bool status;
		int address;
};

#endif
