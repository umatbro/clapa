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
	mikro.setFadeTime(40);
	mikro.setTimeout(250);
	mikro.setTimeWindow(300);
	
	relay.begin(relPin);
	relay.update();
	
	pinMode(lockLED,OUTPUT);
  Serial.begin(9600);
}

void loop() {
	Serial.println( mikro.countClaps() );
	
}





