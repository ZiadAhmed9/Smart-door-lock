 /******************************************************************************
 *
 * Module: DIO
 *
 * File Name: DIO.c
 *
 * Description: 
 *
 * Author: Ziad Ahmed
 *
 *******************************************************************************/
#include "DIO.h"


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void DIO_setPINDir(uint8 portname,uint8 pin,uint8 direction)
{

	switch(portname)
	{

	case 'A':
		if( direction==1 )
		{
			SET_BIT(DDRA,pin);
		}
		else
		{
			CLEAR_BIT(DDRA,pin);
		}
		break;
	case 'B':
		if( direction==1 )
		{
			SET_BIT(DDRB,pin);
		}
		else
		{
			CLEAR_BIT(DDRB,pin);
		}
		break;
	case 'C':
		if( direction==1 )
		{
			SET_BIT(DDRC,pin);
		}
		else
		{
			CLEAR_BIT(DDRC,pin);
		}
		break;
	case 'D':
		if( direction==1)
		{
			SET_BIT(DDRD,pin);
		}
		else
		{
			CLEAR_BIT(DDRD,pin);
		}
		break;
	default:
		break;
	}
}


void DIO_write_PIN(uint8 portname,uint8 pin,uint8 pinvalue)
{
	switch(portname)
	{

	case 'A':
		if( pinvalue==1 )
		{
			SET_BIT(PORTA,pin);
		}
		else
		{
			CLEAR_BIT(PORTA,pin);
		}
		break;
	case 'B':
		if( pinvalue==1 )
		{
			SET_BIT(PORTB,pin);
		}
		else
		{
			CLEAR_BIT(PORTB,pin);
		}
		break;
	case 'C':
		if( pinvalue==1 )
		{
			SET_BIT(PORTC,pin);
		}
		else
		{
			CLEAR_BIT(PORTC,pin);
		}
		break;
	case 'D':
		if( pinvalue==1)
		{
			SET_BIT(PORTD,pin);
		}
		else
		{
			CLEAR_BIT(PORTD,pin);
		}
		break;
	default:
		break;
	}
}

uint8 DIO_read_PIN(uint8 portname,uint8 pin)
{
	uint8 pin_val=0;
	switch(portname)
	{

	case 'A':
		pin_val=READ_BIT(PINA,pin);
		break;
	case 'B':
		pin_val=READ_BIT(PINB,pin);
		break;
	case 'C':
		pin_val=READ_BIT(PINC,pin);
		break;
	case 'D':
		pin_val=READ_BIT(PIND,pin);
		break;
	default:
		break;
	}
	return pin_val;
}

void DIO_BIT_TOGGLE(uint8 portname,uint8 pin)
{
	switch(portname)
	{

	case 'A':
		TOGGLE_BIT(PORTA,pin);
		break;
	case 'B':
		TOGGLE_BIT(PORTB,pin);
		break;
	case 'C':
		TOGGLE_BIT(PORTC,pin);
		break;
	case 'D':
		TOGGLE_BIT(PORTD,pin);
		break;
	default:
		break;
	}
}

void DIO_set_port_Dir(uint8 portname,uint8 direction)
{
	switch(portname)
	{
	case 'A':
		if(direction==1)
		{
			DDRA=0xFF;
		}
		else
		{
			DDRA=0;
		}
		break;
	case 'B':
		if(direction==1)
		{
			DDRB=0xFF;
		}
		else
		{
			DDRB=0;
		}
		break;
	case 'C':
		if(direction==1)
		{
			DDRC=0XFF;
		}
		else
		{
			DDRC=0;
		}
		break;
	case 'D':
		if(direction==1)
		{
			DDRD=0XFF;
		}
		else
		{
			DDRD=0;
		}
		break;
	default:
		break;
	}
}

void DIO_write_port(uint8 portname,uint8 portvalue)
{
	switch(portname)
	{
	case 'A':
		PORTA=portvalue;
		break;
	case 'B':
		PORTB=portvalue;
		break;
	case 'C':
		PORTC=portvalue;
		break;
	case 'D':
		PORTD=portvalue;
	}
}

uint8 DIO_read_port(uint8 portname)
{
	uint8 port_val=0;
	switch(portname)
	{

	case 'A':
		port_val=PINA;
		break;
	case 'B':
		port_val=PINB;
		break;
	case 'C':
		port_val=PINC;
		break;
	case 'D':
		port_val=PIND;
		break;
	default:
		break;
	}
	return port_val;
}

void DIO_enablePullup_pin(uint8 portname,uint8 pin,uint8 status)
{
	switch(portname)
	{
	case 'A':
		if(status==1)
		{
			SET_BIT(PORTA,pin);
		}
		else
		{
			CLEAR_BIT(PORTA,pin);
		}
		break;
	case 'B':
		if(status==1)
				{
					SET_BIT(PORTB,pin);
				}
				else
				{
					CLEAR_BIT(PORTB,pin);
				}
				break;
	case 'C':
		if(status==1)
				{
					SET_BIT(PORTC,pin);
				}
				else
				{
					CLEAR_BIT(PORTC,pin);
				}
				break;
	case 'D':
		if(status==1)
				{
					SET_BIT(PORTD,pin);
				}
				else
				{
					CLEAR_BIT(PORTD,pin);
				}
				break;
	}
}

void DIO_write_low_nibble(uint8 portname,uint8 value)
{
	value&=0x0f;
	switch(portname)
	{
	case 'A':
		PORTA&=0xf0;
		PORTA|=value;
		break;
	case 'B':
		PORTB&=0xf0;
		PORTA|=value;
		break;
	case 'C':
		PORTC&=0xf0;
		PORTA|=value;
		break;
	case 'D':
		PORTD&=0xf0;
		PORTD|=value;
		break;
	default: break;
	}
}

void DIO_set_low_nibble(uint8 portname)
{
	switch(portname)
	{
	case 'A':
		PORTA|=0x0f;
		break;
	case 'B':
		PORTB|=0x0f;
		break;
	case 'C':
		PORTC|=0x0f;
		break;
	case 'D':
		PORTD|=0x0f;
		break;
	default: break;
	}
}

void DIO_clear_low_nibble(uint8 portname)
{
	switch(portname)
	{
	case 'A':
		PORTA&=~(0x0f);
		break;
	case 'B':
		PORTB&=~(0x0f);
		break;
	case 'C':
		PORTC&=~(0x0f);
		break;
	case 'D':
		PORTD&=~(0x0f);
		break;
	default: break;
	}
}

void DIO_set_high_nibble(uint8 portname)
{
	switch(portname)
	{
	case 'A':
		PORTA|=0xf0;
		break;
	case 'B':
		PORTB|=0xf0;
		break;
	case 'C':
		PORTC|=0xf0;
		break;
	case 'D':
		PORTD|=0xf0;
		break;
	default: break;
	}
}

void DIO_clear_high_nibble(uint8 portname)
{
	switch(portname)
	{
	case 'A':
		PORTA&=~(0xf0);
		break;
	case 'B':
		PORTB&=~(0xf0);
		break;
	case 'C':
		PORTC&=~(0xf0);
		break;
	case 'D':
		PORTD&=~(0xf0);
		break;
	default: break;
	}
}

void DIO_write_high_nibble(uint8 portname,uint8 value)
{
	value<<=4;
	switch(portname)
	{
	case 'A':
		PORTA&=0x0f;
		PORTA|=value;
		break;
	case 'B':
		PORTB&=0x0f;
		PORTA|=value;
		break;
	case 'C':
		PORTC&=0x0f;
		PORTA|=value;
		break;
	case 'D':
		PORTD&=0x0f;
		PORTD|=value;
		break;
	default: break;
	}
}

void DIO_write_high_nibbleDir(uint8 portname,uint8 direction)
{
	switch(portname)
	{
	case 'A':
		if(direction==1)
			DDRA|=0xf0;
		else
			DDRA&=~(0xf0);
		break;
	case 'B':
		if(direction==1)
			DDRB|=0xf0;
		else
			DDRB&=~(0xf0);
		break;
	case 'C':
		if(direction==1)
			DDRC|=0xf0;
		else
			DDRC&=~(0xf0);
		break;
	case 'D':
		if(direction==1)
			DDRD|=0xf0;
		else
			DDRD&=~(0xf0);
		break;
	default: break;
	}
}

void DIO_write_low_nibbleDir(uint8 portname,uint8 direction)
{
	switch(portname)
	{
	case 'A':
		if(direction==1)
			DDRA|=0x0f;
		else
			DDRA&=~(0x0f);
		break;
	case 'B':
		if(direction==1)
			DDRB|=0x0f;
		else
			DDRB&=~(0x0f);
		break;
	case 'C':
		if(direction==1)
			DDRC|=0x0f;
		else
			DDRC&=~(0x0f);
		break;
	case 'D':
		if(direction==1)
			DDRD|=0x0f;
		else
			DDRD&=~(0x0f);
		break;
	default: break;
	}
}
