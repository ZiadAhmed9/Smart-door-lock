 /******************************************************************************
 *
 * Module: DIO
 *
 * File Name: DIO.h
 *
 * Description: Contains declarations of DIO functions
 *
 * Author: Ziad Ahmed
 *
 *******************************************************************************/
#ifndef DIO_H_
#define DIO_H_
#include "common_macros.h"
#include "std_types.h"
#include "Micro_Config.h"

/*
	Function Name        : DIO_setPINDir
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber,unsigned char direction
	Function Description : Set the direction of the given pin in the given port (direction 0 = input : 1 = output)
*/
void DIO_setPINDir(uint8 portname,uint8 pin,uint8 direction);



/*
	Function Name        : DIO_write
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber,unsigned char outputvalue
	Function Description : Set the value of the given pin in the given port (outputvalue 0 = low : 1 = high) !!output only !!
*/
void DIO_write_PIN(uint8 portname,uint8 pin,uint8 pinvalue);



/*
	Function Name        : DIO_u8read
	Function Returns     : unsigned char
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Returns 1 if the value of the given pin is high and zero if the value is low
*/
uint8 DIO_read_PIN(uint8 portname,uint8 pin);



/*
	Function Name        : DIO_toggle
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Reverse the value of the given pin in the given port.
*/
void DIO_BIT_TOGGLE(uint8 portname, uint8 pin);



/*
	Function Name        : DIO_set_port_direction
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char direction
	Function Description : set the direction of whole port .
*/
void DIO_set_port_Dir(uint8 portname, uint8 direction);



/*
	Function Name        : DIO_write_port
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char portvalue
	Function Description : Write the value to all port pins.
*/
void DIO_write_port(uint8 portname, uint8 portvalue);



/*
	Function Name        : DIO_read_port
	Function Returns     : unsigned char
	Function Arguments   : unsigned char portname
	Function Description : read the value of the port .
*/
uint8 DIO_read_port(uint8 portname);



/*
	Function Name        : DIO_enablepullup_pin
	Function Returns     : void
	Function Arguments   : char portname ,char pinnumber, char connect_pullup
	Function Description : enable or disable pull up resistor to the given pin at the given port
*/
void DIO_enablePullup_pin(uint8 portname, uint8 pin, uint8 status);



/*
	Function Name        : write_low_nibble
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char value
	Function Description : write a value to the low nibble of the port
*/
void DIO_write_low_nibble(uint8 portname,uint8 value);



/*
	Function Name        : write_high_nibble
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char value
	Function Description : write a value to the high nibble of the port
*/
void DIO_write_high_nibble(uint8 portname,uint8 value);

/*
	Function Name        : high_nibble_Dir
	Function Returns     : void
	Function Arguments   : unsigned char Port,unsigned char direction
	Function Description : set the directionto the high nibble of the port
*/
void DIO_write_high_nibbleDir(uint8 portname,uint8 direction);

/*
	Function Name        : low_nibble_Dir
	Function Returns     : void
	Function Arguments   : unsigned char Port,unsigned char direction
	Function Description : set the directionto the high nibble of the port
*/
void DIO_write_low_nibbleDir(uint8 portname,uint8 direction);

void DIO_set_low_nibble(uint8 portname);

void DIO_clear_low_nibble(uint8 portname);

void DIO_set_high_nibble(uint8 portname);

void DIO_clear_high_nibble(uint8 portname);



#endif /* DIO_H_ */
