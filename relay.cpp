#include "relay.h"

Relay::Relay(int pin){
	normalState = false;
	this->pin = pin;
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

void Relay::openNormal(){
	//normalState = true;
	digitalWrite(pin,HIGH);
	//update();
}

void Relay::closeNormal(){
	digitalWrite(pin,LOW);
	//~ normalState = false;
	//~ update();
}





