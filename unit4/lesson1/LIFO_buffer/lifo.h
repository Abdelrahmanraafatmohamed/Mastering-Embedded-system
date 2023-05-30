/*
 * lifo.h
 *
 *  Created on: May 27, 2023
 *      Author: abdelrahman raafat mohamed
 */
#include "stdio.h"
#include "stdlib.h"

#ifndef LIFO_H_
#define LIFO_H_

/* type definitions */

typedef struct {
	unsigned int  lenght ;
	unsigned int  count ;
	unsigned int* base ;
	unsigned int* head ;
}LIFO_Buf_t;

typedef enum {
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_Null
}LIFO_status;

/* APIS */

LIFO_status LIFO_Add_item (LIFO_Buf_t* lifo_buf , unsigned int item);
LIFO_status LIFO_get_item (LIFO_Buf_t* lifo_buf , unsigned int* item);
LIFO_status LIFO_init (LIFO_Buf_t* lifo_buf , unsigned int* buf , unsigned int lenght);

#endif /* LIFO_H_ */
