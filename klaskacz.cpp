#include "klaskacz.h"


// ---------------------------- DIODA ----------------------------------

Dioda::Dioda(int p){
	this -> pin = p;
	this -> isOn = false;
}

void Dioda::begin(){
	pinMode(this -> pin, OUTPUT);
	digitalWrite(this -> pin, this -> isOn);
}

void Dioda::set(boolean isOn){ //ustawia zmienn¹ isOn i wyœwietla j¹ na diodzie
	this -> isOn = isOn;
	digitalWrite(this -> pin, this -> isOn);
}

int Dioda::set(int pwmValue){ //ustawia wartoœæ PWM na diodzie
	if (pwmValue >= 0 && pwmValue < 256 ) ;
	else if (pwmValue > 255 ) {
		pwmValue = 255;
	}
	else pwmValue = 0;
	
	analogWrite( this -> pin, pwmValue );
	
	return pwmValue;
}

boolean Dioda::getState(){
	return isOn;
}



// ----------------------------------	KLASKACZ ------------------------------------
Klaskacz::Klaskacz(int pin) {
	this -> outPin = pin;
}

void Klaskacz::begin(){
	pinMode(this -> outPin, INPUT_PULLUP);
}

boolean Klaskacz::read() {
	return !digitalRead(outPin);
}