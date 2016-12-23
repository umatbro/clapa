#include "klaskacz.h"

Dioda listwa(9);
Klaskacz klaskacz(A5,10);
Button lock(3);
boolean locked = false;

void setup(){
	pinMode(A5,INPUT_PULLUP);
	listwa.begin();
	klaskacz.begin();
	Serial.begin(9600);
	digitalWrite(10,HIGH);
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	pinMode(4,OUTPUT);
	listwa.set(false);
}


void loop(){
	if (lock.uniquePress()) locked = !locked;

	
	if(!locked){
		klaskacz.listen();
		
		listwa.set(klaskacz.getSwitch());
		listwa.update();
	}
	
	else {
		listwa.set(true);
		listwa.update();
	}
}

