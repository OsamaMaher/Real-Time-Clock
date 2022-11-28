/*
 * Real_Time_Clock.c
 *
 * Created: 11/27/2022 10:14:10 PM
 * Author : osama
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "7segments.h"
#include "PushButton.h"
#include "Timer_Drive.h"
#include "MACROS.h"


volatile unsigned char Sec=0;
unsigned char min=0,hour=0;

int main(void)
{
	Timer2_OVF_init_interrupt();
	segments_dir_init('D');
	BUTTON_INIT('B',0);
	BUTTON_INIT('B',1);
	SET_BIT(DDRC,6);
	SET_BIT(DDRC,7);
	SET_BIT(DDRA,0);
	SET_BIT(DDRA,1);
	SET_BIT(DDRA,2);
	SET_BIT(DDRA,3);
	SET_BIT(DDRA,4);
	SET_BIT(DDRA,5);
	
    while (1) 
    {
		if (BUTTON_READ('B',0)==1)
		{
			_delay_ms(250);
			hour=0; min=0; Sec=0;
			do 
			{
				if (BUTTON_READ('B',1)==1)
				{
					hour++;
					if (hour==24)
					{
						hour=0;
					}
					_delay_ms(250);
				}
				SET_BIT(PORTA,0);
				SET_BIT(PORTA,1);
				SET_BIT(PORTA,2);
				SET_BIT(PORTA,3);
				CLR_BIT(PORTA,4);
				SET_BIT(PORTA,5);
				segments_write('D', hour%10);
				_delay_ms(5);
				SET_BIT(PORTA,0);
				SET_BIT(PORTA,1);
				SET_BIT(PORTA,2);
				SET_BIT(PORTA,3);
				SET_BIT(PORTA,4);
				CLR_BIT(PORTA,5);
				segments_write('D', hour/10);
				_delay_ms(5);
			} while (BUTTON_READ('B',0)==0);
			_delay_ms(250);
			do
			{
				if (BUTTON_READ('B',1)==1)
				{
					min++;
					if (min==60)
					{
						min=0;
					}
					_delay_ms(250);
				}
				SET_BIT(PORTA,0);
				SET_BIT(PORTA,1);
				CLR_BIT(PORTA,2);
				SET_BIT(PORTA,3);
				SET_BIT(PORTA,4);
				SET_BIT(PORTA,5);
				segments_write('D', min%10);
				_delay_ms(5);
				SET_BIT(PORTA,0);
				SET_BIT(PORTA,1);
				SET_BIT(PORTA,2);
				CLR_BIT(PORTA,3);
				SET_BIT(PORTA,4);
				SET_BIT(PORTA,5);
				segments_write('D', min/10);
				_delay_ms(5);
			} while (BUTTON_READ('B',0)==0);
			_delay_ms(250);
			do
			{
				if (BUTTON_READ('B',1)==1)
				{
					Sec=0;
					_delay_ms(250);
				}
				CLR_BIT(PORTA,0);
				SET_BIT(PORTA,1);
				SET_BIT(PORTA,2);
				SET_BIT(PORTA,3);
				SET_BIT(PORTA,4);
				SET_BIT(PORTA,5);
				segments_write('D', Sec%10);
				_delay_ms(5);
				SET_BIT(PORTA,0);
				CLR_BIT(PORTA,1);
				SET_BIT(PORTA,2);
				SET_BIT(PORTA,3);
				SET_BIT(PORTA,4);
				SET_BIT(PORTA,5);
				segments_write('D', Sec/10);
				_delay_ms(5);
			} while (BUTTON_READ('B',0)==0);
			_delay_ms(250);
		}
		CLR_BIT(PORTA,0);
		SET_BIT(PORTA,1);
		SET_BIT(PORTA,2);
		SET_BIT(PORTA,3);
		SET_BIT(PORTA,4);
		SET_BIT(PORTA,5);
		segments_write('D', Sec%10);
		_delay_ms(5);
		SET_BIT(PORTA,0);
		CLR_BIT(PORTA,1);
		SET_BIT(PORTA,2);
		SET_BIT(PORTA,3);
		SET_BIT(PORTA,4);
		SET_BIT(PORTA,5);
		segments_write('D', Sec/10);
		_delay_ms(5);
		SET_BIT(PORTA,0);
		SET_BIT(PORTA,1);
		CLR_BIT(PORTA,2);
		SET_BIT(PORTA,3);
		SET_BIT(PORTA,4);
		SET_BIT(PORTA,5);
		segments_write('D', min%10);
		_delay_ms(5);
		SET_BIT(PORTA,0);
		SET_BIT(PORTA,1);
		SET_BIT(PORTA,2);
		CLR_BIT(PORTA,3);
		SET_BIT(PORTA,4);
		SET_BIT(PORTA,5);
		segments_write('D', min/10);
		_delay_ms(5);
		SET_BIT(PORTA,0);
		SET_BIT(PORTA,1);
		SET_BIT(PORTA,2);
		SET_BIT(PORTA,3);
		CLR_BIT(PORTA,4);
		SET_BIT(PORTA,5);
		segments_write('D', hour%10);
		_delay_ms(5);
		SET_BIT(PORTA,0);
		SET_BIT(PORTA,1);
		SET_BIT(PORTA,2);
		SET_BIT(PORTA,3);
		SET_BIT(PORTA,4);
		CLR_BIT(PORTA,5);
		segments_write('D', hour/10);
		_delay_ms(5);
		if (Sec==60)
		{
			Sec=0;
			min++;
			if (min==60)
			{
				min=0;
				hour++;
				if (hour==24)
				{
					hour=0;
				}
			}
		}
    }
}

ISR(TIMER2_OVF_vect)
{
	Sec++;
}
