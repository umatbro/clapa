#include <Arduino.h>

class Relay {
private:
	int 	pin;
	bool 	normalState;
public:
			Relay(int = 10);
	void 	begin(int); // sets Arduino pin to output
	void 	set(bool); // sets true/false
	void 	update();
	void	changeState();
	void 	openNormal(); // sets relay in normally opened position
	void 	closeNormal(); // sets relay on normally closed position
};





