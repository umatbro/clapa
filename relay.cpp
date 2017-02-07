#include "relay.h"

Relay::Relay(){
	normalState = true;
	pin = 10;
}

void Relay::begin(int pin){
	this -> pin = pin;
	pinMode(pin,OUTPUT);
}

void Relay::set(bool comm){
	normalState = comm;
	update();
}

void Relay::update(){
	digitalWrite(pin,normalState);
}

void Relay::changeState(){
	normalState = !normalState;
	update();
}





