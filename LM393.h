#include <Arduino.h>

class LM393 {
private:
	int 	outPin;
	int 	communicationLedPin;
	bool 	deviceOn; // switch to turn controlled device ON/OFF
	int 	timeWindow; //for how long time do you wait for second clap
	int 	timeout; //you have to be quiet during timeout - otherwise second clap is blocked
	int 	fadeTime;
	
public:
	LM393(int = 0, int = 200, int = 100);
	void begin(int);
	void begin(int, int, int);
	bool readSignal();
	void setTimeout(int);
	void setTimeWindow(int);
	void setFadeTime(int);
	bool getSwitchState();
	void setLedPin(int);
	bool correctClap();
	int countClaps();
	void listen(); //desc in function body
	
};
