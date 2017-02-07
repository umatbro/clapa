#include "relay.h"
#include "Button.h"

#define relPin 10
#define lockBPin 11

Button lockButton(lockBPin,PULLUP);
Relay relay;

void setup() {
	relay.begin(relPin);
}

void loop() {
	if(lockButton.uniquePress()){
		relay.changeState();
	}
	delay(35);
}





