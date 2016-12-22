#include "timer.h"
Timer::Timer() {
	millisecNow = millis();
	millisecStart = millis();
	threshold = 20;
}

boolean Timer::stepTimer(unsigned long milliseconds) {
	millisecNow = millis();
	if( (millisecNow - millisecStart > milliseconds) && (millisecNow - millisecStart)%milliseconds < threshold )
	{
		millisecStart = millis();
		return true;
	}
	else return false;
}