/*
 * US.h
 *
 *  Created on: Jun 1, 2023
 *      Author: DELL
 */

#ifndef US_H_
#define US_H_
#include "state.h"
/* Define states */

enum {
	US_busy,

}US_state_id;

/* declare states functions US */
STATE_define(US_busy);

void US_init();

/* state pointer to function  */
extern void (*US_state)();
#endif /* US_H_ */
