/*
 * US.c
 *
 *  Created on: Jun 1, 2023
 *      Author: DELL
 */

/* variables */
#include "US.h"
int US_distance = 0 ;


/* STATE pointer to function */
void (*US_state)();
int US_Get_distance_random(int l , int r , int count);

void US_init()
{
	/* init US Driver */
	printf("US_init \n");
}
STATE_define (US_busy)
{
	/* state_name */
	US_state_id = US_busy ;

	/* state_action */
	US_distance = US_Get_distance_random (45 , 55 , 1);
	printf("US_waiting state : distance = %d  \n",US_distance);
	US_Set_speed(US_distance);
	US_state = STATE(US_busy);
}


int US_Get_distance_random(int l , int r , int count)
{
	/* this will generate random number in range l and r */
	int i;
	for (i= 0 ; i< count ; i++)
	{
		int rand_num = (rand() % (r - l + 1)) + l ;
		return rand_num ;
	}
}
