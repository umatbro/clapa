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
	Serial.begin(9600);
	mikro.begin(LM393Pin);
	
	relay.begin(relPin);
	relay.update();
	
	pinMode(lockLED,OUTPUT);
}

void loop() {
	if(lockButton.uniquePress()) 
		deviceLocked = !deviceLocked;
		
	switch(deviceLocked) {
		case true:
			digitalWrite(lockLED,HIGH);
			relay.openNormal();
			break;
		case false:
			relay.update();
			Serial.println(mikro.signalOut());
			digitalWrite(lockLED,LOW);
			break;
	}
	
	//~ delay(35);
}





