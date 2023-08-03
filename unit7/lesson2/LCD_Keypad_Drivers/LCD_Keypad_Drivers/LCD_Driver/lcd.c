/*
 * lcd.c
 *
 * Created: 8/2/2023 5:50:37 PM
 *  Author: Abdelrahman Raafat Mohamed
 */ 

#include "lcd.h"

void LCD_clear_screen(){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_KICK(){
	LCD_CTRL |= (1 << ENABLE_SWITCH);
	_delay_ms(50);
	LCD_CTRL &= ~(1 << ENABLE_SWITCH);
}

void LCD_GOTO_XY(unsigned char line, unsigned char position){
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+position);
		}
	}
}

void LCD_INT(){
	_delay_ms(20);
	DataDir_LCD_CTRL |= (1<<ENABLE_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);
	LCD_CTRL &= ~ (1<<ENABLE_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);
	DataDir_LCD_PORT = 0xFF;
	_delay_ms(15);
	LCD_clear_screen();
	#ifdef EIGHT_BIT_MODE
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	#endif
	#ifdef FOUR_BIT_MODE
	//LCD_WRITE_COMMAND(0x02);		/* send for 4 bit initialization of LCD  */
	//LCD_WRITE_COMMAND(0x28);              /* 2 line, 5*7 matrix in 4-bit mode */
	//LCD_WRITE_COMMAND(0x0c);              /* Display on cursor off*/
	//LCD_WRITE_COMMAND(0x06);              /* Increment cursor (shift cursor to right)*/
	//LCD_WRITE_COMMAND(0x01);
	LCD_WRITE_COMMAND(0x02);
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
	#endif
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_is_busy(){
	DataDir_LCD_PORT &= ~(0xFF<<DATA_shift);
	LCD_CTRL |= (1 << RW_SWITCH);
	LCD_CTRL &= ~(1 << RS_SWITCH);
	LCD_KICK();
	DataDir_LCD_PORT |= (0xFF<<DATA_shift);
	LCD_CTRL &= ~(1 << RW_SWITCH);
	
}


void LCD_WRITE_COMMAND(unsigned char command){
	#ifdef EIGHT_BIT_MODE
	LCD_is_busy();
	LCD_PORT = command;
	LCD_CTRL &= ~((1 << RS_SWITCH) | (1<<RW_SWITCH));
	_delay_ms(1);
	LCD_KICK();
	#endif
	#ifdef FOUR_BIT_MODE
	LCD_is_busy();
	LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
	LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	LCD_KICK ();
	LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);
	LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	LCD_KICK();
	#endif
}

void LCD_WRITE_CHAR(unsigned char Data){
	#ifdef EIGHT_BIT_MODE
	LCD_is_busy();
	LCD_PORT = Data;
	LCD_CTRL &= ~(1 << RW_SWITCH);
	LCD_CTRL |= (1 << RS_SWITCH);
	_delay_ms(1);
	LCD_KICK();
	#endif
	#ifdef FOUR_BIT_MODE
	//LCD_check_lcd_isbusy();
	LCD_PORT = (LCD_PORT & 0x0F) | (Data & 0xF0);
	LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	LCD_KICK();
	LCD_PORT = (LCD_PORT & 0x0F) | (Data << 4);
	LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	LCD_KICK ();
	#endif
}

void LCD_WRITE_STRING(char* string){
	int count = 0;
	while (*string > 0){
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16)
		{
			LCD_GOTO_XY(2,0);
		}
		else if (count == 32)
		{
			LCD_clear_screen();
			LCD_GOTO_XY(1,0);
			count = 0;
		}
	}
}

