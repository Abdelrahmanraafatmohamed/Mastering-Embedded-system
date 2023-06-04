/*
 * DC.c
 *
 *  Created on: Jun 1, 2023
 *      Author: DELL
 */

/* variables */
#include "DC.h"
int DC_speed = 0;


/* STATE pointer to function */
void (*DC_state)();


void DC_init()
{
	/* init pwm */
	printf("DC_init \n");
}
void DC_Motor_Set (int s)
{
	DC_speed = s;
	DC_state = STATE(DC_busy);
	printf("CA --------speed=%d----->DC \n",DC_speed);
}
STATE_define (DC_idle)
{
	/* state_name */
	DC_state_id = DC_idle ;
	/* state action */
	/* call pwm to make speed = DC_speed */
	printf("DC_idle state :  speed=%d \n",DC_speed);
}

STATE_define (DC_busy)
{
	/* state_name */
		DC_state_id = DC_busy ;

		/* state action */
		/* call pwm to make speed = DC_speed */

		DC_state = STATE(DC_idle);

		printf("DC_busy state :  speed=%d \n",DC_speed);
}
