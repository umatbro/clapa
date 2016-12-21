#include <Arduino.h>

class Klaskacz {
private:
	int outPin;
	boolean lock;
	int timeWindow;
	
public:
	Klaskacz(int);
	void begin();
	boolean read();
	boolean listen();
	
};


class Dioda{
private:
	int pin;
	boolean isOn;
	
public:
	Dioda(int); //
	void begin();
	void set(boolean); //ustawia stan niski/wysoki
	int set(int); // ustawia analog write - warto�ci od 0 do 255
	boolean getState();
};
