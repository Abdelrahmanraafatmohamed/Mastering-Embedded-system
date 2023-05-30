/*
 * main.c
 *
 *  Created on: May 27, 2023
 *      Author: DELL
 */
#include "fifo.h"
void main()
{
   FIFO_Buf_t FIFO_UART ;
   element_type i ,temp=0 ;
   if (FIFO_init(&FIFO_UART , uart_buffer ,5) == FIFO_no_error)
	   printf("fifo init -------Done \n");

   for (i=0 ; i<7  ; i++)
   {
	   printf("FIFO Enqueue (%x) \n ",i);
	   if(FIFO_enqueue(&FIFO_UART  , i) == FIFO_no_error)
		   printf("\t fifo enqueue ------ Done \n");
	   else
		   printf("\t fifo enqueue ------ failed \n");
   }
   FIFO_print(&FIFO_UART);
   if(FIFO_dequeue(&FIFO_UART  , &temp) == FIFO_no_error)
	   printf(" fifo dequeue %x ------ Done \n", temp);
   if(FIFO_dequeue(&FIFO_UART  , &temp) == FIFO_no_error)
   	   printf(" fifo dequeue %x ------ Done \n", temp);
   FIFO_print(&FIFO_UART);
}

