/*
 * state.h
 *
 *  Created on: Jun 1, 2023
 *      Author: DELL
 */

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"
/* automatic state function generated */
#define STATE_define(_statFUN_)  void ST_##_statFUN_()

#define STATE(_statFUN_)  ST_##_statFUN_

// state connection

void US_Set_speed(int d);
void DC_Motor_Set(int s);

#endif /* STATE_H_ */
