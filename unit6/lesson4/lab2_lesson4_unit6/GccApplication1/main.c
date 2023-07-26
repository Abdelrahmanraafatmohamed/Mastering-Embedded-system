/*
 * GccApplication1.c
 *
 * Created: 7/25/2023 5:28:58 PM
 * Author : DELL
 */ 

#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define IO_BASE   0x20
#define PORTD    *(volatile unsigned int *) (IO_BASE + 0x12)
#define DDRD     *(volatile unsigned int *) (IO_BASE + 0x11)
#define MCUCR    *(volatile unsigned int *) (IO_BASE + 0x35)
#define MCUCSR   *(volatile unsigned int *) (IO_BASE + 0x34)
#define GICR     *(volatile unsigned int *) (IO_BASE + 0x3B)


int main(void)
{   
	/* ALLOW pin(5,6,7) as output in portD */
	DDRD |= (1<<5);
	DDRD |= (1<<6);
	DDRD |= (1<<7);
	
	/* enable int0 as logical */
	MCUCR |= (1<<0);
	MCUCR &= ~(1<<1);
	
	/* enable int1 as rising */
	MCUCR |= (1<<2);
	MCUCR |= (1<<3);
	
	/* enable int2 as falling */
	MCUCSR &= ~(1<<6);
	
	/* enable all IR==>0,1,2 */
	GICR |= (1<<5);
	GICR |= (1<<6);
	GICR |= (1<<7);

	sei(); // enable SREG [global interrupt enable]
    while(1)
    {
        PORTD &= ~(1<<5);
		PORTD &= ~(1<<6);
		PORTD &= ~(1<<7);
		_delay_ms(1000);
    }
}

ISR(INT0_vect)
{
	
	PORTD |= 1<<5;
	_delay_ms(1000);
}

ISR(INT1_vect)
{
	
	PORTD |= 1<<6;
	_delay_ms(1000);
}

ISR(INT2_vect)
{
	
	PORTD |= 1<<7 ;
	_delay_ms(1000);
}