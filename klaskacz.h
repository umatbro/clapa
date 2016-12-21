#include <Arduino.h>

class Klaskacz{
	
};


class Dioda{
	private:
		int pin;
		boolean isOn;
		
	public:
		Dioda(int); //
		void start();
		// void setState(boolean); //ustawia stan niski/wysoki
		// void setState(int); // ustawia analog write - warto�ci od 0 do 255
		// boolean getState();
};
