#include "LM393.h"

LM393::LM393(int pin) {
	outPin = pin;
	deviceOn = false;
}

void LM393::begin(int pin) {
	outPin = pin;
	pinMode(outPin,INPUT_PULLUP);
}

bool LM393::signalOut() {
	return !digitalRead(outPin);
}
