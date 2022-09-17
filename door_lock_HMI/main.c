 /******************************************************************************
 *
 * Module: main
 *
 * File Name: main.c
 *
 * Description: 
 *
 * Author: Ziad Ahmed
 *
 *******************************************************************************/
#include "LCD.h"
#include "KEYPAD.h"
#include "DIO.h"
#include "uart.h"




#define pass_digits 5
#define PASS_CHANGE 0
#define DOOR_UNLOCK 1
#define ALERT 2


volatile uint8 password[pass_digits+1];
volatile uint16 entered;
volatile uint8 current_state;
volatile uint8 trials=0;



static void read_password(void);
static uint8 password_check(void);
static void idle_state(void);
static void read_password(void);
static void correct_password(void);
static void incorrect_password(void);
static void pass_change(void);




int main(void)
{
	UART_init();
	LCD_init();
	read_password();
	if(password_check()==1)
	{
		LCD_Clear();
		LCD_displayString("WRONG PASSWORD, TRY AGAIN");
		_delay_ms(2000);
		main();
	}
	LCD_Clear();
	LCD_displayString("PASSWORD SAVED!");
	_delay_ms(500);
	password[pass_digits]='#';
	password[pass_digits+1]='\0';
	UART_sendString(password);

	for(;;)
	{
		start :idle_state();
	}

}


static void read_password(void)       //PHASE 1
{
	LCD_Clear();
	LCD_displayString("ENTER NEW PASSWORD :");
	LCD_Command(LCD_Cursor_second_line);
	for(int i=0;i<pass_digits;i++)
	{
		password[i]=KEYPAD_getPressedKey();
		LCD_displayChar('*');
		_delay_ms(300);
	}
}

static uint8 password_check(void)       //PHASE 2
{
	LCD_Clear();
	LCD_displayString("ENTER PASSWORD AGAIN :");
	LCD_Command(LCD_Cursor_second_line);
	uint8 arr[5];
	for(int i=0;i<5;i++)
	{
		arr[i]=KEYPAD_getPressedKey();
		LCD_displayChar('*');
		_delay_ms(300);
	}
	for(int i=0;i<pass_digits;i++)
	{
		if(arr[i]!=password[i])
		{
			return 1;
		}
	}
	return 0;
}


static void idle_state(void)
{
	uint8 key;
	LCD_Clear();
	LCD_displayString("PRESS '*' TO UNLOCK");
	LCD_Command(LCD_Cursor_second_line);
	LCD_displayString("PRESS '#' TO CHANGE PASSWORD");
	key=KEYPAD_getPressedKey();

	if(key=='*')
	{
		LCD_Clear();
		LCD_displayString("ENTER THE PASSWORD :");
		LCD_Command(LCD_Cursor_second_line);
		for(int i=0;i<pass_digits;i++)
		{
			password[i]=KEYPAD_getPressedKey();
			LCD_displayChar('*');
			_delay_ms(300);
		}
		UART_sendByte(DOOR_UNLOCK);
		UART_sendString(password);
		uint8 check=UART_receiveByte();
		if(check==TRUE)
		{
			correct_password();
		}
		else
		{
			incorrect_password();
		}
	}
	else if(key=='#')
	{
		pass_change();
	}
}


static void correct_password(void)
{
	uint8 check=0;
	trials=0;
	LCD_Clear();
	LCD_displayString("WELCOME...");
	check=UART_receiveByte();
	if(check==1)
	{
		LCD_Clear();
		LCD_displayString("CLOSING");
		_delay_ms(2000);
	}
	else
	{
		LCD_Clear();
		LCD_displayString("ERROR, TRY AGAIN");
		_delay_ms(1000);
	}
}


static void incorrect_password(void)
{
	trials++;
	if(trials==2)
	{
		volatile uint8 i;

			LCD_Clear();
			LCD_displayString("DOOR LOCKED!!");
			trials=0;
			while(i<10)
			{
				i++;
				_delay_ms(1000);
			}
			return;
	}
	LCD_Clear();
	LCD_displayString("INVALID PASSWORD");
	_delay_ms(1000);


}

void pass_change(void)
{
	uint8 check_old,check_new;
	LCD_Clear();
	LCD_displayString("ENTER THE OLD PASSWORD");
	UART_sendByte(PASS_CHANGE);
	LCD_Command(LCD_Cursor_second_line);
	for(int i=0;i<pass_digits;i++)
			{
				password[i]=KEYPAD_getPressedKey();
				LCD_displayChar('*');
				_delay_ms(300);
			}
	UART_sendString(password);
	check_old=UART_receiveByte();
	if(check_old==TRUE)
	{
		trials=0;
		LCD_Clear();
		LCD_displayString("CORRECT!");
		_delay_ms(1000);
	}
	else if(check_old==FALSE)
	{
		trials++;
		if(trials==2)
		{
			volatile uint8 j;
			LCD_Clear();
			LCD_displayString("DOOR LOCKED!!");
			_delay_ms(1000);
			trials=0;
		}
		else
		{
		LCD_Clear();
		LCD_displayString("WRONG PASSWORD");
		_delay_ms(1000);
		}
		return;
	}

	LCD_Clear();
	LCD_displayString("ENTER THE NEW PASSWORD");
	LCD_Command(LCD_Cursor_second_line);
	for(int i=0;i<pass_digits;i++)
			{
				password[i]=KEYPAD_getPressedKey();
				LCD_displayChar('*');
				_delay_ms(300);
			}
	check_new=password_check();
	if(check_new==0)
	{
	UART_sendByte(1);
	UART_sendString(password);
	LCD_Clear();
	LCD_displayString("SUCCESS!!");
	_delay_ms(1000);
	}
	else
	{
		UART_sendByte(0);
		LCD_Clear();
		LCD_displayString("WRONG PASSWORD, TRY AGAIN..");
	}
}
