 /******************************************************************************
 *
 * Module: dc_motor
 *
 * File Name: dc_motor.c
 *
 * Description: 
 *
 * Author: Ziad Ahmed
 *
 *******************************************************************************/
#include "DIO.h"
#include "dc_motor.h"

void MOTOR_init(void)
{
	DIO_setPINDir(MOTOR_PORT,MOTOR_IN1,out);
	DIO_setPINDir(MOTOR_PORT,MOTOR_IN2,out);
}
void MOTOR_start_clockwise(void)
{
	DIO_write_PIN(MOTOR_PORT,MOTOR_IN1,0);
	DIO_write_PIN(MOTOR_PORT,MOTOR_IN2,1);
}


void MOTOR_start_anticlock(void)
{
	DIO_write_PIN(MOTOR_PORT,MOTOR_IN1,1);
	DIO_write_PIN(MOTOR_PORT,MOTOR_IN2,0);
}
void MOTOR_stop(void)
{
	DIO_write_PIN(MOTOR_PORT,MOTOR_IN1,0);
	DIO_write_PIN(MOTOR_PORT,MOTOR_IN2,0);}
