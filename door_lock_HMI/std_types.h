 /******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: std_types.h
 *
 * Description: types for AVR with 16 bits data bus
 *
 * Author: Ziad Ahmed
 *
 *******************************************************************************/
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*creating boolean data type*/

typedef unsigned char bool;

/*boolean values*/

#ifndef FALSE
#define FALSE   	(0u)
#endif

#ifndef TRUE
#define TRUE		(1u)
#endif

#ifndef HIGH
#define HIGH		(1u)
#endif

#ifndef LOW
#define LOW			(0u)
#endif

#ifndef in
#define in			(0u)
#define out			(1u)
#endif

typedef unsigned char		uint8;		/*		      0..255				*/
typedef signed char			sint8;		/*	 	   -128..127				*/
typedef unsigned short		uint16;		/*		      0..65535				*/
typedef signed short		sint16;		/*      -32768 .. +32767        	*/
typedef unsigned long 		uint32;		/*           0 .. 4294967295      	*/
typedef signed long			sint32;		/* -2147483648 .. +2147483647     	*/
typedef unsigned long long	uint64;		/*       	 0..18446744073709551615*/
typedef	signed long long	sint64;
typedef float				float32;
typedef double				double32;


#endif /* STD_TYPES_H_ */

