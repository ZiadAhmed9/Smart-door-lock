 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: KEYPAD.c
 *
 * Description: Keypad Driver file
 *
 * Author: Ziad Ahmed
 *
 *******************************************************************************/
#include "KEYPAD.h"
#include "DIO.h"
#include "std_types.h"
#include "Micro_Config.h"
/*******************************************************************************
 *                      Functions Prototypes(Private)                          *
 *******************************************************************************/
#if (N_col==3)
static uint8 KeyPad_4x3_adjustKeyNumber(uint8 button_number);

#elif (N_col==4)
static sint8 KeyPad_4x4_adjustKeyNumber(uint8 button_number);

#endif
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void KEYPAD_init(void)
{
	DIO_setPINDir( KEYPAD_PORT_OUT,0,in);
	DIO_setPINDir( KEYPAD_PORT_OUT,1,in);
	DIO_setPINDir( KEYPAD_PORT_OUT,2,in);
	DIO_setPINDir( KEYPAD_PORT_OUT,3,in);
	DIO_setPINDir( KEYPAD_PORT_IN,4,in);
	DIO_setPINDir( KEYPAD_PORT_IN,5,in);
	DIO_setPINDir( KEYPAD_PORT_IN,6,in);
	DIO_enablePullup_pin(KEYPAD_PORT_IN,0,1);
	DIO_enablePullup_pin(KEYPAD_PORT_IN,1,1);
	DIO_enablePullup_pin(KEYPAD_PORT_IN,2,1);
}

uint8 KEYPAD_getPressedKey(void)
{
	uint8 col,row;
	while(1)
	{
		KEYPAD_init();
		for(row=3;row<N_row+3;row++)
		{
			if(row>3)
			{
				DIO_setPINDir( KEYPAD_PORT_OUT,row-1,in);
			}
			DIO_setPINDir( KEYPAD_PORT_OUT,row,out);
			DIO_write_PIN(KEYPAD_PORT_OUT,row,0);
			for(col=0;col<N_col;col++)
			{
				if(DIO_read_PIN(KEYPAD_PORT_IN,col)==0)
				{
					#if (N_col==3)
					return KeyPad_4x3_adjustKeyNumber(((row-3)*N_col)+col+1);
					#elif (N_col==4)
					return KeyPad_4x4_adjustKeyNumber((col*N_col)+row+1);
					#endif
				}
			}
		}
	}

}


static uint8 KeyPad_4x3_adjustKeyNumber(uint8 button_number)
{
	switch(button_number)
	{
		case 10: return '*'; // ASCII Code of =
				 break;
		case 11: return 0;
				 break;
		case 12: return '#'; // ASCII Code of +
				 break;
		default: return button_number;
	}
}

sint8 KeyPad_4x4_adjustKeyNumber(uint8 button_number)
{
	switch(button_number)
	{
	case 1:
		return 7;
		break;
	case 2:
		return 8;
		break;
	case 3:
		return 9;
		break;
	case 4:
		return '/';
		break;
	case 5:
		return 4;
		break;
	case 6:
		return 5;
		break;
	case 7:
		return 6;
		break;
	case 8:
		return '*';
		break;
	case 9:
		return 1;
		break;
	case 10:
		return 2;
		break;
	case 11:
		return 3;
		break;
	case 12:
		return '-';
		break;
	case 13:
		return 'A';
		break;
	case 14:
		return 0;
		break;
	case 15:
		return '=';
		break;
	case 16:
		return '+';
		break;

	default:
		return 0 ;
		break;


	}

}
