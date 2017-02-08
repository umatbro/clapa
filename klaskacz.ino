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
	mikro.setTimeout(1337);
	
	relay.begin(relPin);
	relay.update();
	
	pinMode(lockLED,OUTPUT);
  Serial.begin(9600);
}

void loop() {
	Serial.println( mikro.correctClap() );
	
}





