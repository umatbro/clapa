#include "klaskacz.h"

Dioda listwa(9);
Klaskacz klaskacz(A5,10);

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
	// boolean reading = klaskacz.listen();
	// Serial.println(reading);
	// if(reading) listwa.changeState();
	// listwa.update();
	Serial.println(klaskacz.listen());
	
	listwa.set(klaskacz.getSwitch());
	listwa.update();

}
