 /******************************************************************************
 *
 * Module: led_buzzer
 *
 * File Name: led_buzzer.h
 *
 * Description: 
 *
 * Author: Ziad Ahmed
 *
 *******************************************************************************/

#include "DIO.h"

#define ALARM_PORT 'A'
#define ALARM_BUZZ 0
#define ALARM_LED 1
#define PASS_LED 2



void alarm_init(void);


void alarm_trigger(void);
void correct_pass_ledOFF(void);
void correct_pass_ledON(void);
