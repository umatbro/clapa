#include <Arduino.h>
#include "timer.h"

#define CURRENT 0
#define PREVIOUS 1
#define CHANGED 2

class Klaskacz {
private:
	int outPin;
	int vccPin;
	boolean lock;
	boolean switchOn;
	int timeWindow;
	uint8_t state;
	
public:
	Klaskacz(int,int);
	void begin();
	boolean read();
	boolean stateChanged();
	boolean uniqueKlask();
	boolean listen();
	boolean doNotListen(int time);
	boolean doubleKlask();
	boolean getSwitch();
};


class Dioda{
private:
	int pin;
	boolean isOn;
	
public:
	Dioda(int); //
	void begin();
	boolean set(boolean); //ustawia stan niski/wysoki
	int set(int); // ustawia analog write - warto�ci od 0 do 255
	boolean changeState();
	boolean getState();
	void update(); //updateuje wyświetlanie
};
