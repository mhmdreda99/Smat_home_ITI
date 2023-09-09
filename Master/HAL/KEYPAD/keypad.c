/*
 * keypad.c
 *
 *  Created on: 2023þ//
 *      Author:Karim_Zidan
 */

#include"../../MCAL/std_types.h"
#include"../../MCAL/Std_Library.h"
#include"../../MCAL/macros.h"
#include "../../MCAL/DIO/MCAL_DIO_INTERFACE.h"
#include"keypad_cnfg.h"
#include"keypad_interface.h"



u8 column_port_pins[4]={pin4,pin5,pin6,pin7};
u8 row_port_pins[4]={pin4,pin5,pin6,pin7};

char button_pos[keypad_rows][keypad_columns]={
		{'7','8','9','/'},
		{'4','5','6','X'},
		{'1','2','3','-'},
		{'#','0','=','+'}
};

//#define BUTTON_POSITION_MACRO \
//    {                          \
//        {'7', '8', '9', '/'},  \
//        {'4', '5', '6', 'X'},  \
//        {'1', '2', '3', '-'},  \
//        {'#', '0', '=', '+'}   \
//    }

/*this function is used to scan and read the pressed buttons of keypad*/
void keypad_read(char *button_pos_ )
{
	u8 l_row_counter=0;
	u8 l_column_counter=0;
	u8 counter=0;
	u8 buttonn =0;

	*button_pos_=0;

	for(l_row_counter=0 ;l_row_counter<keypad_columns;l_row_counter++)
	{
		DIO_PIN_WRITE_LOGIC_M(keypad_rows_PORT,row_port_pins[l_row_counter],PIN_HIGH);
		_delay_us(50);
		for(l_column_counter=0 ; l_column_counter<keypad_columns;l_column_counter++)
		{
			buttonn=DIO_PIN_READ_LOGIC_LEVEL_M(keypad_columns_PORT,column_port_pins[l_column_counter]);
			if(PIN_HIGH==buttonn)
			{
				_delay_ms(50);
				*button_pos_=button_pos[l_row_counter][l_row_counter];
				DIO_PIN_WRITE_LOGIC_M(keypad_rows_PORT,row_port_pins[counter],PIN_LOW);
				break;
			}
		}
	}

}
/******************/
void keypad_read_1(char *button_pos_ )
{
	u8 l_row_counter=0;
	u8 l_column_counter=0;

	u8 buttonn =0;
	*button_pos_=0;

	for(l_column_counter=0 ;l_column_counter<keypad_columns;l_column_counter++)
	{

		DIO_PIN_WRITE_LOGIC_M(keypad_columns_PORT,column_port_pins[l_column_counter],PIN_LOW);

		for(l_row_counter=0 ; l_row_counter<keypad_rows;l_row_counter++)
		{
			buttonn=DIO_PIN_READ_LOGIC_LEVEL_M(keypad_rows_PORT,row_port_pins[l_row_counter]);
			if(PIN_LOW==buttonn)
			{
				_delay_ms(50);
				*button_pos_=button_pos[l_row_counter][l_column_counter];
				DIO_PIN_WRITE_LOGIC_M(keypad_columns_PORT,column_port_pins[l_column_counter],PIN_HIGH);

				break;
			}
			else
			{}
		}
	}
}

/******************/
void keypad_read_2(char *button_pos_ )
{
	u8 l_row_counter=0;
	u8 l_column_counter=0;
	u8 buttonn =0;
	*button_pos_=0;
	u8 flag=0;

	for(l_column_counter=0 ;l_column_counter<keypad_columns;l_column_counter++)
	{

		DIO_PIN_WRITE_LOGIC_M(keypad_columns_PORT,column_port_pins[l_column_counter],PIN_LOW);

		for(l_row_counter=0 ; l_row_counter<keypad_rows;l_row_counter++)
		{
			buttonn= DIO_PIN_READ_LOGIC_LEVEL_M(keypad_rows_PORT,row_port_pins[l_row_counter]);
			if(PIN_LOW==buttonn)
			{
				flag=1;
				*button_pos_=button_pos[l_row_counter][l_column_counter];
				break;
			}
			else
			{}
		}
		DIO_PIN_WRITE_LOGIC_M(keypad_columns_PORT,column_port_pins[l_column_counter],PIN_HIGH);

		if(1==flag)
		{
			break;
		}

	}
}

/******************/
void keypad_read_4(char *button_pos_ )
{
	u8 l_row_counter=0;
	u8 l_column_counter=0;

	u8 buttonn =0;
	*button_pos_=0;

	for(l_column_counter=0 ;l_column_counter<keypad_columns;l_column_counter++)
	{
		DIO_PIN_WRITE_LOGIC_M(keypad_columns_PORT,column_port_pins[l_column_counter],PIN_LOW);

		for(l_row_counter=0 ; l_row_counter<keypad_rows;l_row_counter++)
		{
			buttonn=DIO_PIN_READ_LOGIC_LEVEL_M(keypad_rows_PORT,row_port_pins[l_row_counter]);
			if(PIN_LOW==buttonn)
			{
				while(PIN_LOW!=buttonn)
				{
					buttonn=DIO_PIN_READ_LOGIC_LEVEL_M(keypad_rows_PORT,row_port_pins[l_row_counter]);
				}
				*button_pos_=button_pos[l_row_counter][l_column_counter];
				break;
			}
			else
			{}
		}
		DIO_PIN_WRITE_LOGIC_M(keypad_columns_PORT,column_port_pins[l_column_counter],PIN_HIGH);

	}

}

/************************/

/******************/
button_state_t keypad_readd(char *button_pos_ )
{
	button_state_t button_state=BUTTON_RELEASED;
	u8 l_row_counter=0;
	u8 l_column_counter=0;

	u8 buttonn =0;
	*button_pos_=0;
	u8 flag=0;
	for(l_column_counter=0 ;l_column_counter<keypad_columns;l_column_counter++)
	{
		DIO_PIN_WRITE_LOGIC_M(keypad_columns_PORT,column_port_pins[l_column_counter],PIN_LOW);
		for(l_row_counter=0 ; l_row_counter<keypad_rows;l_row_counter++)
		{
			buttonn=DIO_PIN_READ_LOGIC_LEVEL_M(keypad_rows_PORT,row_port_pins[l_row_counter]);
			if(0==buttonn)
			{
				button_state=BUTTON_PRESSED;
				flag=1;
				while(0==buttonn)
				{
					buttonn=DIO_PIN_READ_LOGIC_LEVEL_M(keypad_rows_PORT,row_port_pins[l_row_counter]);
				}
				*button_pos_=button_pos[l_row_counter][l_column_counter];
				break;
			}
			else
			{ button_state=BUTTON_RELEASED;}

		}
		DIO_PIN_WRITE_LOGIC_M(keypad_columns_PORT,column_port_pins[l_column_counter],PIN_HIGH);
		if(1==flag)
		{

			break;
		}
	}

	return button_state;
}
/*****************************************debug*********************************/
