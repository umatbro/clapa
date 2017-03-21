#include <Arduino.h>

class LM393 {
private:
	int 	outPin;
	int 	communicationLedPin;
	bool 	deviceOn; // switch to turn controlled device ON/OFF
	int 	timeWindow; //for how long time do you wait for second clap
	int 	timeout; //you have to be quiet during timeout - otherwise second clap is blocked
	int 	fadeTime; //initiated with value 40 (corresponding to 40 ms), time when all signals are ignored to prevent noise influence
	
public:
	LM393(int = 0, int = 150, int = 250);
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
