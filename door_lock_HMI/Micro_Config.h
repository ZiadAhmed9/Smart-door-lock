 /******************************************************************************
 *
 * Module: Micro_Config
 *
 * File Name: Micro_Config.h
 *
 * Description: This file contains the needed libraries for AVR
 *
 * Author: Ziad Ahmed
 *
 *******************************************************************************/
#ifndef MICRO_CONFIG_H_
#define MICRO_CONFIG_H_


/*defining the frequency of the CPU*/

#ifndef F_CPU
#define F_CPU		(1600000UL)
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#endif /* MICRO_CONFIG_H_ */
