#include <Arduino.h>

class Timer
{
	private:
		unsigned long 	millisecNow;
		unsigned long 	millisecStart;
	public: 
						Timer();
		long int		threshold;
		boolean 		stepTimer(unsigned long); //zwraca true cyklicznie co ile� milisekund, pozwala na wykonanie jakiej� akcji co pewien czas
};