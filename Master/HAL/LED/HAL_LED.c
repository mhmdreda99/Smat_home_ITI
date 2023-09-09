/*
 * HAL_LED.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */
/**************include section****************/
#include "../../MCAL/DIO/MCAL_DIO_INTERFACE.h"
#include"../../MCAL/std_types.h"
#include"HAL_LED_CNFG.h"
#include"HAL_LED_INTERFACE.h"
/**************macro section****************/

void HAL_LED_ON(u8 port_ , u8 pin);
void HAL_LED_OFF(u8 port_ , u8 pin);
void HAL_LED_TOGGLE(u8 port_ , u8 pin);
/**************macro function  section****************/




/**************data type section****************/


/**
 * @describe -> this function is used to set led high
 */
void HAL_LED_ON(u8 port_ , u8 pin)
{
	DIO_PIN_WRITE_LOGIC_M(port_,pin,PIN_HIGH);
}
/**************************************************/
/**
 * @describe -> this function is used to set led low
 */
void HAL_LED_OFF(u8 port_ , u8 pin)
{
	DIO_PIN_WRITE_LOGIC_M(port_,pin,PIN_LOW);
}
/**************************************************/
/**
 * @describe -> this function is used to set led low
 */
void HAL_LED_TOGGLE(u8 port_ , u8 pin)
{
	DIO_PIN_TOGGLE_LOGIC_M(port_,pin);
}
/**************************************************/
