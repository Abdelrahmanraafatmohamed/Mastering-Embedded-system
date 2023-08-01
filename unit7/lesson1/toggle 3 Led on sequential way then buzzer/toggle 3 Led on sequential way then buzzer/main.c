/*
 * toggle 3 Led on sequential way then buzzer.c
 *
 * Created: 8/1/2023 5:46:12 PM
 * Author : abdelrahman raafat
 */ 

#include "memory_map.h"
#define F_CPU 8000000UL
#include "utlits.h"
#include "util/delay.h"

void wait (int x)
{
	unsigned int i , j;
	for (i=0;i<x;i++)
	 for(j=0;j<255;j++);
}

int main(void)
{
	/* DDRD = 0b11110000; */
	setbit(DDRD,4);
    setbit(DDRD,5);
	setbit(DDRD,6);
	setbit(DDRD,7);
    while (1) 
    {
		togglebit(PORTD,5);
		_delay_ms(500);
		togglebit(PORTD,5);
		togglebit(PORTD,6);
		_delay_ms(500);
		togglebit(PORTD,6);
		togglebit(PORTD,7);
	    _delay_ms(500);
		togglebit(PORTD,7);
		togglebit(PORTD,4);
		_delay_ms(500);
		togglebit(PORTD,4);
    }
}

