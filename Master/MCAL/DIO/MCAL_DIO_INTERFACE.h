/*
 * MCAL_INTERFACE.h
 *
 *  Created on: ??�/??�/????
 *      Author: m
 */

#ifndef MCAL_DIO_MCAL_DIO_INTERFACE_H_
#define MCAL_DIO_MCAL_DIO_INTERFACE_H_


/************include section************/
#include"../std_types.h"
/************Macro section************/
#define PORTA_   0
#define PORTB_   1
#define PORTC_   2
#define PORTD_   3

#define  pin0    0
#define  pin1    1
#define  pin2    2
#define  pin3    3
#define  pin4    4
#define  pin5    5
#define  pin6    6
#define  pin7    7

#define PIN_HIGH 1
#define PIN_LOW  0

#define DIRECTION_OUTPUT 1
#define DIRECTION_INPUT  0

/************Macro Function section************/


/************Data type section************/


/************Function Declaration section************/


/**************************DIO Port API's***************************/


void PORT_LOGICLEVEL_INIT(void);
void PORT_DIRECTION_INIT(void);
void DIO_PIN_WRITE_LOGIC_M(u8 port ,u8 pin,u8 Pin_Logic);
void DIO_PIN_DIRECTION_INIT_M(u8 port ,u8 pin,u8 Direction);
void DIO_PIN_TOGGLE_LOGIC_M(u8 port ,u8 pin);
u8 DIO_PIN_READ_LOGIC_LEVEL_M(u8 port ,u8 pin);
void DIO_PORT_WRITE_LOGIC_M(u8 port ,u8 Port_val);
void DIO_PORT_SET_DIRECTION_M(u8 port ,u8 DIRECTION_VALUE);



#endif /* MCAL_DIO_MCAL_DIO_INTERFACE_H_ */
