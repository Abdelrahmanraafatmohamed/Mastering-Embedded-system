/*
 * lifo.c
 *
 *  Created on: May 27, 2023
 *      Author: abdelrahman raafat mohamed
 */
#include "lifo.h"

/* APIS */

LIFO_status LIFO_Add_item (LIFO_Buf_t* lifo_buf , unsigned int item)
{
	/* check lifo is valid */
	if (!lifo_buf->base || !lifo_buf->head )
		return LIFO_Null ;

	/* check lifo is fill ? */
	if (lifo_buf->count == lifo_buf->lenght)
		return LIFO_full ;

	/* add value  */
	*(lifo_buf->head) = item ;
	lifo_buf->head++ ;
	lifo_buf->count++ ;

	return LIFO_no_error ;
	}



LIFO_status LIFO_get_item (LIFO_Buf_t* lifo_buf , unsigned int* item)
{
    /* check lifo is valid  */
	    if (!lifo_buf->base || !lifo_buf->head )
		return LIFO_Null ;
   /* check lifo is empty?   */
	    if (lifo_buf->count == 0 )
	    	return LIFO_empty ;
	lifo_buf->head-- ;
	*item = *(lifo_buf->head) ;
	lifo_buf->count-- ;
	return LIFO_no_error ;

}


LIFO_status LIFO_init (LIFO_Buf_t* lifo_buf , unsigned int* buf , unsigned int lenght)
{
	if (buf == NULL)
		return LIFO_Null ;
	lifo_buf->base = buf ;
	lifo_buf->head = buf ;
	lifo_buf->lenght = lenght ;
	lifo_buf->count = 0 ;
	return LIFO_no_error ;
	}

