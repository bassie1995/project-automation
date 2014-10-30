#ifndef IPCAMERA_H
#define IPCAMERA_H

class IPCamera
{
	public:
		IPCamera();
		void turnOn();
		void turnOff();
	private:
		bool status;
};

#endif
