#include "LM393.h"

LM393::LM393(int pin){
	outPin = pin;
}

LM393::begin(int pin){
	outPin = pin;
	pinMode(outPin,INPUT_PULLUP);
}

LM393::signalOut(){
	return !digitalRead(pin);
}
