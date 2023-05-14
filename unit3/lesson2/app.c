#include "uart.h"
unsigned char string_buffer[100]= "learn-in-depth:Abdelrahman Raafat Mohamed";
unsigned char const string_buffer2[100]= "learn-in-depth:Abdelrahman Raafat Mohamed";
void main (void)
{
  uart_send_string (string_buffer);
 }