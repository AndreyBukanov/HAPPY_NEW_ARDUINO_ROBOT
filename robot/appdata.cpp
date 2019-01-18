#include "appdata.h"

void SetInterrupt(uint8_t pin, void(*callback)(void))
{
	int8_t interrupt_number = digitalPinToInterrupt(pin);

	if (interrupt_number == NOT_AN_INTERRUPT)
		return;

	pinMode(pin, INPUT);

	attachInterrupt(interrupt_number, callback, CHANGE);
}