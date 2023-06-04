/*
 * main.c
 *
 *  Created on: Jun 1, 2023
 *      Author: DELL
 */

#include "CA.h"
#include "DC.h"
#include "US.h"
void setup ()
{
	/* init all drivers */
	/* init IRQ */
	/* init HAL US_Driver DC_Driver */
	/* init Block */
	US_init();
	DC_init();
	/* set states pointers for each Block */
	CA_state = STATE (CA_waiting);
	US_state = STATE (US_busy);
	DC_state = STATE (DC_idle);

}

void main()
{
	volatile int d;
	setup();
	while(1)
	{
		/* call state for each Block */
		US_state();
		CA_state();
		DC_state();
		/* delay */
	for (d=0 ; d<=1000 ; d++);
}
}
