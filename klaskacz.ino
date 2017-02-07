#include "relay.h"
#include "Button.h"

#define relPin 10
#define lockBPin 11

Button lockButton(lockBPin,PULLUP);
bool deviceLocked = false;

Relay relay;

void setup() {
	relay.begin(relPin);
}

void loop() {
	if(lockButton.uniquePress()) deviceLocked = !deviceLocked;
	
	switch(deviceLocked) {
		case true:
			relay.openNormal();
			break;
		case false:
			relay.closeNormal();
			break;
	}
	delay(35);
}





