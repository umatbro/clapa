#include "relay.h"
#include "Button.h"
#include "LM393.h"

#define relPin 10
#define lockBPin 11
#define lockLED 12
#define LM393Pin A0

Button lockButton(lockBPin,PULLUP);
bool deviceLocked = false;

LM393 mikro;

Relay relay;

void setup() {
	mikro.setLedPin(lockLED);
	mikro.begin(LM393Pin);
	mikro.setTimeout(500);
	
	relay.begin(relPin);
	relay.update();
	
	pinMode(lockLED,OUTPUT);
}

void loop() {
	if(lockButton.uniquePress()) {
		deviceLocked = !deviceLocked;
		delay(30);
	}
	switch(deviceLocked) {
		case true:
			digitalWrite(lockLED,HIGH);
			relay.openNormal();
			break;
		case false:
			digitalWrite(lockLED,LOW);
			mikro.listen();
			delay(5);
			relay.set(mikro.getSwitchState());
			break;
	}
	
}





