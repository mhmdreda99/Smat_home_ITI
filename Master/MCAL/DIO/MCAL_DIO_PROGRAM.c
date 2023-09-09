/*
 * mcal_dio_.c
 *
 *  Created on: 1/8/2023
 *      Author: karim.zidan
 */
/****include section*****/
#include"../Std_Library.h"
#include"../std_types.h"
#include"../macros.h"
#include"MCAL_DIO_CONFIG.h"
#include "MCAL_DIO_INTERFACE.h"
#include"MCAL_DIO_PRIVATE.h"
#include"MCAL_DIO_REGISTERS.h"




/**********using macros ***********/


void DIO_PIN_WRITE_LOGIC_M(u8 port ,u8 pin,u8 Pin_Logic)
{
	if(PIN_HIGH==Pin_Logic)
	{
		switch(port)
		{

		case PORTA_:  SET_BIT(PORTA,pin); break;
		case PORTB_ : SET_BIT(PORTB,pin); break;
		case PORTC_ : SET_BIT(PORTC,pin); break;
		case PORTD_ : SET_BIT(PORTD,pin); break;
		default  	: break;
		}
	}
	else if(PIN_LOW==Pin_Logic)
	{
		switch(port)
				{

				case PORTA_:  CLEAR_BIT(PORTA,pin); break;
				case PORTB_ : CLEAR_BIT(PORTB,pin); break;
				case PORTC_ : CLEAR_BIT(PORTC,pin); break;
				case PORTD_ : CLEAR_BIT(PORTD,pin); break;
				default  	: break;
				}
	}
	else{}

}

/***********************/

void DIO_PIN_DIRECTION_INIT_M(u8 port ,u8 pin,u8 Direction)
{
	if(DIRECTION_OUTPUT==Direction)
	{
		switch(port)
		{

		case PORTA_:  SET_BIT(DDRA,pin); break;
		case PORTB_ : SET_BIT(DDRB,pin); break;
		case PORTC_ : SET_BIT(DDRC,pin); break;
		case PORTD_ : SET_BIT(DDRD,pin); break;
		default  	: break;
		}
	}
	else if(PIN_LOW==DIRECTION_INPUT)
	{
		switch(port)
				{

				case PORTA_:  CLEAR_BIT(DDRA,pin); break;
				case PORTB_ : CLEAR_BIT(DDRB,pin); break;
				case PORTC_ : CLEAR_BIT(DDRC,pin); break;
				case PORTD_ : CLEAR_BIT(DDRD,pin); break;
				default  	: break;
				}
	}
	else{}

}

/***********************/

void DIO_PIN_TOGGLE_LOGIC_M(u8 port ,u8 pin)
{
	switch(port)
	{
	case PORTA_:  TOGGLE_BIT(PORTA,pin); break;
	case PORTB_ : TOGGLE_BIT(PORTB,pin); break;
	case PORTC_ : TOGGLE_BIT(PORTC,pin); break;
	case PORTD_ : TOGGLE_BIT(PORTD,pin); break;
	default : break;
	}
}

/***********************************/
u8 DIO_PIN_READ_LOGIC_LEVEL_M(u8 port ,u8 pin)
{
u8 x;
	switch(port)
	{
	case PORTA_ : x= (GET_BIT(PINA,pin)); break;
	case PORTB_ : x= (GET_BIT(PINB,pin));break;
	case PORTC_ : x= (GET_BIT(PINC,pin));break;
	case PORTD_ :x= (GET_BIT(PIND,pin));	break;
	default : break;
	}
return x;
}
/***********************************/

/******************************/
void DIO_PORT_WRITE_LOGIC_M(u8 port ,u8 Port_val)
{
	  switch(port)
	  {
	  case PORTA_: PORTA = Port_val;break;
	  case PORTB_: PORTB = Port_val;break;
	  case PORTC_: PORTC = Port_val;break;
	  case PORTD_: PORTD = Port_val;break;
	  default : break;
	  }
}
void DIO_PORT_SET_DIRECTION_M(u8 port ,u8 DIRECTION_VALUE)
{
	  switch(port)
	  {
		  case PORTA_: DDRA = DIRECTION_VALUE;break;
		  case PORTB_: DDRB = DIRECTION_VALUE;break;
		  case PORTC_: DDRC = DIRECTION_VALUE;break;
		  case PORTD_: DDRD = DIRECTION_VALUE;break;
		  default : break;
	  }
}


/***********************/

void PORT_DIRECTION_INIT(void)
{
	DDRA=PORTA_DIR;
	DDRB=PORTB_DIR;
	DDRC=PORTC_DIR;
	DDRD=PORTD_DIR;
}
void PORT_LOGICLEVEL_INIT(void)
{
	PORTA=PORTA_LOGIC;
	PORTB=PORTB_LOGIC;
	PORTC=PORTC_LOGIC;
	PORTD=PORTD_LOGIC;
}


