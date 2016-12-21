#include "klaskacz.h"

Dioda listwa(9);
Klaskacz klaskacz(A5);

void setup(){
	pinMode(A5,INPUT_PULLUP);
	listwa.begin();
	klaskacz.begin();
	Serial.begin(9600);
}


void loop(){
	// for (int i=0;i<256; i++){
		// listwa.set(i);
		// delay(10);
	// }
	// for(int i = 255; i>=0; i--){
		// listwa.set(i);
		// delay(10);
	// }
	
	Serial.println(klaskacz.read());
}