#include "relay.h"
#include "Button.h"
#include "LM393.h"

#define relPin 10
#define lockBPin 11
#define lockLED 12
#define LM393Pin A0

#define CLAPS_ON 3
#define CLAPS_OFF 2

Button lockButton(lockBPin,PULLUP);
bool deviceLocked = false;

LM393 mikro;

Relay relay;

void setup() {
	delay(300);
	mikro.setFadeTime(50);
	mikro.setLedPin(lockLED);
	mikro.begin(LM393Pin);
	
	//na początku normaly closed.
	relay.set(LOW);
	
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
			relay.update();
			digitalWrite(lockLED,LOW);
			int claps = mikro.countClaps();
			if (claps == CLAPS_ON )
				relay.set(HIGH);
			if ( claps == CLAPS_OFF ) {
				relay.set(LOW);
			}	
			break;
	}
}
