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

boolean Dioda::set(boolean isOn){ //ustawia zmienn¹ isOn i wyœwietla j¹ na diodzie
	this -> isOn = isOn;
	//digitalWrite(this -> pin, this -> isOn);
	return this -> isOn;
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

boolean Dioda::changeState(){
	this -> isOn = !(this -> isOn);
	return this -> isOn;
}

void Dioda::update(){
	digitalWrite(this -> pin, this -> isOn);
}

// ----------------------------------	KLASKACZ ------------------------------------
Klaskacz::Klaskacz(int pin, int vccpin) {
	this -> outPin = pin;
	this -> vccPin = vccpin;
	this -> state = 0;
	this -> switchOn = false;
	//this -> state = bitWrite(state, CURRENT, this->read())
}

void Klaskacz::begin(){
	pinMode(this -> outPin, INPUT_PULLUP);
	pinMode(this -> vccPin,OUTPUT);
	digitalWrite(this->vccPin, LOW);
}

boolean Klaskacz::read() {
	bitWrite(state,PREVIOUS,bitRead(state,CURRENT));
    if (digitalRead(outPin) == true){
        bitWrite(state,CURRENT,false);
    } else {
        bitWrite(state,CURRENT,true);
    }
    if (bitRead(state,CURRENT) != bitRead(state,PREVIOUS)){
        bitWrite(state,CHANGED,true);
    }else{
        bitWrite(state,CHANGED,false);
    }
	return bitRead(state,CURRENT);
	
	//return !digitalRead(outPin);
}

boolean Klaskacz::stateChanged(){
	return bitRead(state,CHANGED);
}

boolean Klaskacz::uniqueKlask() {
	return ( this->read() && this -> stateChanged() );
}

boolean Klaskacz::doNotListen(int time){
	static int millisStart = millis();
	if( millis() - millisStart < time ) {
		bitWrite(state,CURRENT,0);
		bitWrite(state,PREVIOUS,0);
		bitWrite(state,CHANGED,0);
	}
	else millisStart = millis();
	
	return false;
}


boolean Klaskacz::listen() {
	//if(digitalRead(outPin) == LOW){
	if(this -> read()) {
		// switchOn = !switchOn;
		// return true;
		// } else {
		// return false;
		int timeWindow1 = 100, 
		timeWindow2 = 500,
		timeWindow3 = 500; // w oknie czasowym mog¹ byæ ready, w oknie czasowym 2 nie mo¿e byæ ¿adnych a w 3 je¿eli siê coœ znajdzie to przestawiæ switcha
		boolean condition = true;
		int start;
		while(condition){
			digitalWrite(2,HIGH);
			delay(timeWindow1);
			digitalWrite(2,LOW);
			unsigned long start = millis();
			digitalWrite(3,HIGH);
			while(millis() - start < timeWindow2){
				if(this->read()){
					condition = false;
					break;
				}
			}
			digitalWrite(3,LOW);
			if(!condition) break;
			digitalWrite(4,HIGH);
			start = millis();
			while(millis() - start < timeWindow3) {
				if(this -> uniqueKlask()){
					condition = true;
					switchOn = !switchOn;
					break; 
				}
			}
			digitalWrite(4,LOW);
			condition = false;
			break;
		}
	}
	this -> read();
	return switchOn;
	
}

boolean Klaskacz::getSwitch(){
	return this -> switchOn;
}