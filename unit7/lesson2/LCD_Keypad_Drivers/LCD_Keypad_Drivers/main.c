/*
 * LCD_Keypad_Drivers.c
 *
 * Created: 8/2/2023 5:48:49 PM
 * Author : Abdelrahman Raafat Mohamed
 */ 

#include <avr/io.h>
#include "LCD_Driver/lcd.h"

#include "Keypad_Driver/keypad.h"


int main()
{
	
	LCD_INT();
	Keypad_init();
	_delay_ms(50);
	unsigned char key_pressed;
	while(1){
		key_pressed = Keypad_getkey();
		switch(key_pressed){
			case 'A':
			break;
			case '?':
			LCD_clear_screen();
			break;
			default:
			LCD_WRITE_CHAR(key_pressed);
			break;
		}
	}
}

