 /******************************************************************************
 *
 * Module: led_buzzer
 *
 * File Name: led_buzzer.c
 *
 * Description: 
 *
 * Author: Ziad Ahmed
 *
 *******************************************************************************/

#include "led_buzzer.h"
#include "DIO.h"

void alarm_init(void)
{
	DIO_setPINDir(ALARM_PORT,ALARM_BUZZ,out);
	DIO_setPINDir(ALARM_PORT,ALARM_LED,out);
	DIO_setPINDir(ALARM_PORT,PASS_LED,out);

}

void alarm_trigger(void)
{
	while(1)
	{
		DIO_BIT_TOGGLE(ALARM_PORT,ALARM_BUZZ);
		DIO_BIT_TOGGLE(ALARM_PORT,ALARM_LED);
		_delay_ms(1000);
	}
}


void correct_pass_ledON(void)
{
	DIO_write_PIN(ALARM_PORT,PASS_LED,1);
}

void correct_pass_ledOFF(void)
{
	DIO_write_PIN(ALARM_PORT,PASS_LED,0);

}
