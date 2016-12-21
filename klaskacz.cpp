#include "klaskacz.h"


// ---------------------------- DIODA ----------------------------------

Dioda::Dioda(int p){
	this -> pin = p;
	this -> isOn = false;
}

void Dioda::start(){
	pinMode(this -> pin, OUTPUT);
	digitalWrite(this -> pin, this -> isOn);
}