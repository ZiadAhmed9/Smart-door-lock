 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: LCD.c
 *
 * Description: LCD functions definitions
 *
 * Author: Ziad Ahmed
 *
 *******************************************************************************/
#include "LCD.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void LCD_refresh(void)
{
	_delay_ms(1);
	DIO_write_PIN(LCD_ctrl_port,EN,0);
	_delay_ms(1);
	DIO_write_PIN(LCD_ctrl_port,EN,1);
	_delay_ms(1);
}
void LCD_Command(uint8 cmd)
{
	DIO_write_PIN(LCD_ctrl_port,RS,0);
	_delay_ms(1);
	DIO_write_PIN(LCD_ctrl_port,EN,1);
	_delay_ms(1);
	DIO_write_high_nibble(LCD_data_port,cmd>>4);
	LCD_refresh();
	DIO_write_high_nibble(LCD_data_port,cmd);
	_delay_ms(1);
	DIO_write_PIN(LCD_ctrl_port,EN,0);
	_delay_ms(1);
}
void LCD_init(void)
{
	_delay_ms(200);
	DIO_setPINDir(LCD_ctrl_port,RS,out);
	DIO_setPINDir(LCD_ctrl_port,RW,out);
	DIO_setPINDir(LCD_ctrl_port,EN,out);
	DIO_write_high_nibbleDir(LCD_data_port,out);
	LCD_Command(LCD_Cursor_reset);
	LCD_Command(LCD_4bit_2line);
	LCD_Command(LCD_displayOn_cursorOff);
	LCD_Command(LCD_clear_cmd);
}

void LCD_displayChar(uint8 data)
{
	DIO_write_PIN(LCD_ctrl_port,RS,1);
	_delay_ms(1);
	DIO_write_PIN(LCD_ctrl_port,EN,1);
	_delay_ms(1);
	DIO_write_high_nibble(LCD_data_port,HIGH_NIBBLE_OF(data));
	LCD_refresh();
	DIO_write_high_nibble(LCD_data_port,data);
	_delay_ms(1);
	DIO_write_PIN(LCD_ctrl_port,EN,0);
	_delay_ms(1);
}


void LCD_displayString(const char *str)
{
	uint8 i=0;
	while(str[i]!='\0')
	{
		LCD_displayChar(str[i]);
		i++;
	}

}


void LCD_MoveTo_Row_Column(uint8 row, uint8 col)
{
	// The position is COL+ROW
	uint8 position;

	switch(row)
	{
		case 0:
			position=col;
			break;
		case 1:
			position=col+0x40;
			break;
	}
	LCD_Command(position|LCD_Cursor_move_to);
}


void LCD_display_String_Row_Column(uint8 row,uint8 col, const char *str)
{
	LCD_MoveTo_Row_Column(row,col);
	LCD_displayString(str);

}



void LCD_Clear(void)
{
	LCD_Command(LCD_clear_cmd);
}



void LCD_integerToString(sint8 data)
{

	char buff[16];
	itoa(data,buff,10);
	LCD_displayString( buff );
}


void LCD_display_int(uint8 data)
{
	/* if any switch pressed for more than 500 ms it counts more than one press */
	if((data <= 9) && (data >= 0))
	{
		LCD_integerToString(data); /* display the pressed keypad switch */
	}
	else
	{
		LCD_displayChar(data); /* display the pressed keypad switch */
	}
	_delay_ms(350); /* Press time */

}

void LCD_display_int_nodelay(sint8 data)
{
	/* if any switch pressed for more than 500 ms it counts more than one press */
	if((data <= 9) && (data >= 0))
	{
		LCD_integerToString(data); /* display the pressed keypad switch */
	}
	else
	{
		LCD_displayChar(data); /* display the pressed keypad switch */
	}

}
