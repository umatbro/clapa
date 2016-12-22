#include <Arduino.h>

class Timer
{
	private:
		unsigned long 	millisecNow;
		unsigned long 	millisecStart;
	public: 
						Timer();
		long int		threshold;
		boolean 		stepTimer(unsigned long); //zwraca true cyklicznie co ileœ milisekund, pozwala na wykonanie jakiejœ akcji co pewien czas
};