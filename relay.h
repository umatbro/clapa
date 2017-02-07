#include <Arduino.h>

class Relay {
private:
	int 	pin;
	bool 	normalState;
public:
			Relay();
	void 	begin(int); // sets Arduino pin to output
	void 	set(bool); // sets true/false
	void 	update();
	void	changeState();
};





