#include "LM393.h"

LM393::LM393(int pin, int timeout, int timeWindow) {
	outPin = pin;
	deviceOn = false;
	setTimeout(timeout);
	setTimeWindow(timeWindow);
	fadeTime = 30;
}

//begin with only pin, use default timeout and timeWindow values
void LM393::begin(int pin) {
	outPin = pin;
	pinMode(outPin,INPUT_PULLUP);
	pinMode(communicationLedPin, OUTPUT);
}

//begin with setting timeout and timeWindow values
void LM393::begin(int pin, int timeout, int timeWindow){
	begin(pin);
	setTimeout(timeout);
	setTimeWindow(timeWindow);
}

bool LM393::readSignal() {
	return !digitalRead(outPin);
}

void LM393::setTimeout(int milliseconds) {
	this -> timeout = milliseconds;
}

void LM393::setTimeWindow(int milliseconds) {
	this -> timeWindow = milliseconds;
}

void LM393::setFadeTime (int milliseconds) {
	fadeTime = milliseconds;
}

bool LM393::getSwitchState() {
	return deviceOn;
}

void LM393::setLedPin(int pin){
	communicationLedPin = pin;
}

bool LM393::correctClap(){
	bool result = false;
	long startTime = millis();
	
	//czeka na dźwięk przez czas timeWindow
	while ( millis() - startTime < timeWindow ) {
		if ( readSignal() ) {
			result = true; break; }
	}
	
	//jeśli nie było sygnału to funkcja zwraca false
	if (!result) return false;
	
	//odpalenie diodki sygnalizującej 
	digitalWrite(communicationLedPin, HIGH);

	//wyczekanie baunsowania
	delay(fadeTime);
	
	//sprawdzenie czy nie ma hałasu
	startTime = millis();
	while ( millis() - startTime < timeout ) {
		if ( readSignal() ) { //jeśli pojawi się sygnał to kasuj
			digitalWrite(communicationLedPin,HIGH);
			delay(200);
			digitalWrite(communicationLedPin,LOW);
			delay(200);
			digitalWrite(communicationLedPin,HIGH);
			delay(200);
			digitalWrite(communicationLedPin,LOW);
			delay(200);
			digitalWrite(communicationLedPin,HIGH);
			delay(200);
			digitalWrite(communicationLedPin,LOW);
			result = false;
			
		}
	}
	
	//zgaszenie diodki sygnalizującej 
	digitalWrite(communicationLedPin, LOW);
	
	return result;
}

int LM393::countClaps(){
	int result=0;
	while (correctClap()){
		result++;
	}
	return result;
}

void LM393::listen() { 
	//~ 1. check if signal on pinOut is high
	//~ 2. if yes dont accept any signal during timeout
	//~ 3. wait for signal in timeWindow
	//~ 4. change deviceOn state.
	if ( readSignal() ) {
		digitalWrite(communicationLedPin, HIGH);
		delay(fadeTime);
		
		bool bad = false;
		long millisStart = millis();
		while ( millis() - millisStart < timeout) {
			if (readSignal()) bad = true;
		}
		
		millisStart = millis();
		
		digitalWrite(communicationLedPin,LOW);
		deviceOn = !deviceOn;
	}

}
