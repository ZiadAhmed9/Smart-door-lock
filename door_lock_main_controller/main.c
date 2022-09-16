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

#include "uart.h"
#include "DIO.h"
#include "dc_motor.h"
#include "external_eeprom.h"
#include "led_buzzer.h"


#define pass_digits 5
#define PASS_CHANGE 0
#define DOOR_UNLOCK 1
#define ALERT 2

volatile uint8 password[6];
volatile uint8 operation;
volatile uint8 trial=0;

void save_password(void);
void pass_change(void);


int main(void)
{

	UART_init();
	MOTOR_init();
	alarm_init();
	EEPROM_init();
	UART_receiveString(password);
	save_password();

	while(1)
	{
		operation=0;
		operation=UART_receiveByte();
		if(operation==DOOR_UNLOCK)
		{
			UART_receiveString(password);
			check_password();
		}
		else if(operation==PASS_CHANGE)
		{
			UART_receiveString(password);
			pass_change();
		}
	}
}




void save_password(void)
{
	for(int i=0;i<pass_digits+1;i++){
		EEPROM_writeByte(0x0040+i,password[i]);
		_delay_ms(10);
	}
}

void check_password(void)
{
	volatile uint8 check;
	for(int i=0;i<pass_digits+1;i++){
		EEPROM_readByte(0x0040+i,&check);
		if(check==password[i])
		{
			continue;
		}
		else
		{
			UART_sendByte(FALSE);
			trial++;
			if(trial==3)
				{
					alarm_trigger();
				}
			return;

			}
	}
	trial=0;
	UART_sendByte(TRUE);
	correct_pass_ledON();
	MOTOR_start_clockwise();
	_delay_ms(2000);
	MOTOR_stop();
	_delay_ms(3000);
	UART_sendByte(1);
	MOTOR_start_anticlock();
	_delay_ms(2000);
	correct_pass_ledOFF();
	MOTOR_stop();
}

void pass_change(void)
{
	volatile uint8 check;
	for(int i=0;i<pass_digits+1;i++){
		EEPROM_readByte(0x0040+i,&check);
		if(check==password[i])
		{
			continue;
		}
		else
		{
			UART_sendByte(FALSE);
			trial++;
			if(trial==3)
				{
					alarm_trigger();
				}
			return;

			}
	}
	trial=0;
	UART_sendByte(TRUE);
	volatile uint8 check_new=UART_receiveByte();
	if(check_new==1)
	{
	UART_receiveString(password);
	save_password();
	}
	else
		return;
}
