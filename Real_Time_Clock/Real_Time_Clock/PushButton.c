/*
 * PushButton.c
 *
 * Created: 11/16/2022 9:30:43 PM
 *  Author: osama
 */ 
#include "DIO.h"

void BUTTON_INIT(unsigned char port, unsigned char pin)
{
	DIO_SETPINDIR(port, pin, 0);
}

unsigned char BUTTON_READ(unsigned char port, unsigned char pin)
{
	unsigned char x;
	x = DIO_READ(port, pin);
	return x;
}