#include <Arduino.h>

class LM393 {
private:
	int outPin;
	bool deviceOn;
	
public:
	LM393(int = 0);
	void begin(int);
	bool signalOut();
};
