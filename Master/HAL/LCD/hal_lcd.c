/*
 * hal_lcd.c


 *
 *  Created on:2023/8/1
 *      Author: Karim_Zidan
 */

#include "../../MCAL/DIO/MCAL_DIO_INTERFACE.h"
#include"../../MCAL/macros.h"
#include"../../MCAL/Std_Library.h"
#include"../../MCAL/std_types.h"
#include"hal_lcd_cnfg.h"
#include "HAL_LCD_PRIVATE.h"
#include"hal_lcd_interface.h"







void HLCD_Send_Command_8bit( u8 command)
{

	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,Rs,PIN_LOW);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,R_W,PIN_LOW);
	DIO_PORT_WRITE_LOGIC_M(LCD_PORT_DATA,command);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,En,PIN_HIGH);
	_delay_ms(2);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,En,PIN_LOW);

}
/***********************************/
void HLCD_INIT_8bit(void)
{

	_delay_ms(30);
	HLCD_Send_Command_8bit(FUNCTION_SET_8bit_Mode_2row_8_line);
	_delay_ms(1);
	HLCD_Send_Command_8bit(LCD_CMD_DISPLAY_ON_CURSOR_ON_BC_ON);
	_delay_ms(1);
	HLCD_Send_Command_8bit(LCD_CMD_CLEAR_DISPLAY);

}
void HLCD_Send_char_8bit( u8 data)
{
	/*clear rs to select command*/
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,Rs,PIN_HIGH);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,R_W,PIN_LOW);
	DIO_PORT_WRITE_LOGIC_M(LCD_PORT_DATA,data);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,En,PIN_HIGH);
	_delay_ms(2);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,En,PIN_LOW);

}
/*****************************************/

Std_ReturnType HLCD_Send_String_Position_8bit(u8 *string,u8 row , u8 column)
{
	Std_ReturnType status =E_OK;
	switch(row)
	{
	case LCD_GO_ROW1 : HLCD_Send_Command_8bit(LCD_GO_ROW1+column);status =E_OK;
	HLCD_Send_String_8bit(string); break;

	case LCD_GO_ROW2 : HLCD_Send_Command_8bit(LCD_GO_ROW2+column);status =E_OK;
	HLCD_Send_String_8bit(string); break;

	case LCD_GO_ROW3 : HLCD_Send_Command_8bit(LCD_GO_ROW3+column);status =E_OK;
	HLCD_Send_String_8bit(string); break;

	case LCD_GO_ROW4 : HLCD_Send_Command_8bit(LCD_GO_ROW4+column);status =E_OK;
	HLCD_Send_String_8bit(string); break;

	default :status =E_NOT_OK; break;
	}
	return status ;
}

/********************************/
Std_ReturnType HLCD_Send_CursorPosition_8bit(u8 row , u8 column)
{
	Std_ReturnType status =E_OK;
	switch(row)
	{
	case LCD_GO_ROW1 : HLCD_Send_Command_8bit(LCD_GO_ROW1+column);status =E_OK;
	break;

	case LCD_GO_ROW2 : HLCD_Send_Command_8bit(LCD_GO_ROW2+column);status =E_OK;
	break;

	case LCD_GO_ROW3 : HLCD_Send_Command_8bit(LCD_GO_ROW3+column);status =E_OK;
	break;

	case LCD_GO_ROW4 : HLCD_Send_Command_8bit(LCD_GO_ROW4+column);status =E_OK;
	break;

	default :status =E_NOT_OK; break;
	}
	return status ;
}
/**************************************/
Std_ReturnType HLCD_Send_char_Position_8bit(u8 data,u8 row , u8 column)
{
	Std_ReturnType status =E_OK;
	switch(row)
	{
	case LCD_GO_ROW1 : HLCD_Send_Command_8bit(LCD_GO_ROW1+column);status =E_OK;
	HLCD_Send_char_8bit(data);break;

	case LCD_GO_ROW2 : HLCD_Send_Command_8bit(LCD_GO_ROW2+column);status =E_OK;
	HLCD_Send_char_8bit(data); break;

	case LCD_GO_ROW3 : HLCD_Send_Command_8bit(LCD_GO_ROW3+column);status =E_OK;
	HLCD_Send_char_8bit(data); break;

	case LCD_GO_ROW4 : HLCD_Send_Command_8bit(LCD_GO_ROW4+column);status =E_OK;
	HLCD_Send_char_8bit(data); break;

	default :status =E_NOT_OK; break;
	}
	return status ;
}
/*********************************************/
void HLCD_Send_String_8bit( u8 *data)
{
	/*clear rs to select command*/
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,Rs,PIN_HIGH);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,R_W,PIN_LOW);
	while(*data)
	{
		DIO_PORT_WRITE_LOGIC_M(LCD_PORT_DATA,*data++);
		DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,En,PIN_HIGH);
		_delay_ms(2);
		DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,En,PIN_LOW);
	}
}
/************************/
void HLCD_Send_Float1(const float data) {
	char *str=NULL;
	int integerPart = (int)data;
	int decimalPart = (int)((data - integerPart) * 100); // Get two decimal places

	// Print the integer part
	convert_uint32_to_string(integerPart,str);
	HLCD_Send_String_8bit(str);

	// Print the decimal point
	HLCD_Send_char_8bit('.');

	// Print the decimal part with leading zeros if necessary
	if (decimalPart < 10) {
		HLCD_Send_char_8bit('0'); // Leading zero
	}
	convert_uint32_to_string(decimalPart,str);
	HLCD_Send_String_8bit(str);
	//    _delay_ms(1000);
}


/**********************************************************/


void HLCD_INIT_4bit(void)
{
	_delay_ms(20);
	HLCD_Send_Command_4bit(FUNCTION_SET_8bit_Mode_2row_11_line);
	_delay_ms(5);
	HLCD_Send_Command_4bit(FUNCTION_SET_8bit_Mode_2row_11_line);
	_delay_us(150);
	HLCD_Send_Command_4bit(FUNCTION_SET_8bit_Mode_2row_11_line);

	HLCD_Send_Command_4bit(LCD_CMD_CLEAR_DISPLAY);
	HLCD_Send_Command_4bit(LCD_CMD_CURSOR_HOME);
	HLCD_Send_Command_4bit(_LCD_ENTRY_MODE_INC_SHIFT_OFF);
	HLCD_Send_Command_4bit(LCD_CMD_DISPLAY_ON_CURSOR_OFF_BC_OFF);
	HLCD_Send_Command_4bit(FUNCTION_SET_4bit_Mode_2row_11_line);
	HLCD_Send_Command_4bit( 0x80);

}
/****************************************/
void HLCD_Send_Command_4bit(const u8 command)
{
	/*clear rs to select command*/
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,Rs,PIN_LOW);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,R_W,PIN_LOW);

	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_DATA,LCD_4bit_DATA_PIN0,(command>>4)&0x01); //lowest bit on highst nipple 4 ->4
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_DATA,LCD_4bit_DATA_PIN1,(command>>5)&0x01);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_DATA,LCD_4bit_DATA_PIN2,(command>>6)&0x01);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_DATA,LCD_4bit_DATA_PIN3,(command>>7)&0x01);

	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,En,PIN_HIGH);
	_delay_ms(2);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,En,PIN_LOW);

	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_DATA,LCD_4bit_DATA_PIN0,(command>>0)&0x01);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_DATA,LCD_4bit_DATA_PIN1,(command>>1)&0x01);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_DATA,LCD_4bit_DATA_PIN2,(command>>2)&0x01);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_DATA,LCD_4bit_DATA_PIN3,(command>>3)&0x01);

	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,En,PIN_HIGH);
	_delay_ms(2);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,En,PIN_LOW);
}
/***********************/
#if LCD_MODE==LCD_4bit_MODE
void HLCD_Send_char_4bit(const u8  data)
{

	/*clear rs to select command*/
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,Rs,PIN_HIGH);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,R_W,PIN_LOW);

	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_DATA,LCD_4bit_DATA_PIN0,(data>>4)&0x01);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_DATA,LCD_4bit_DATA_PIN1,(data>>5)&0x01);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_DATA,LCD_4bit_DATA_PIN2,(data>>6)&0x01);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_DATA,LCD_4bit_DATA_PIN3,(data>>7)&0x01);

	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,En,PIN_HIGH);
	_delay_ms(2);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,En,PIN_LOW);

	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_DATA,LCD_4bit_DATA_PIN0,(data>>0)&0x01);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_DATA,LCD_4bit_DATA_PIN1,(data>>1)&0x01);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_DATA,LCD_4bit_DATA_PIN2,(data>>2)&0x01);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_DATA,LCD_4bit_DATA_PIN3,(data>>3)&0x01);

	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,En,PIN_HIGH);
	_delay_ms(2);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,En,PIN_LOW);

}
/*********************************************/
void HLCD_Send_String_4bit( u8 *data)
{
	/*clear rs to select command*/
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,Rs,PIN_HIGH);
	DIO_PIN_WRITE_LOGIC_M(LCD_PORT_CTRL,R_W,PIN_LOW);
	while(*data)
	{
		HLCD_Send_char_4bit(*data++);
	}
}
/*****************************************/

Std_ReturnType HLCD_Send_String_Position_4bit(u8 *string,u8 row , u8 column)
{
	Std_ReturnType status =E_OK;
	switch(row)
	{
	case LCD_GO_ROW1 : HLCD_Send_Command_4bit(LCD_GO_ROW1+column);status =E_OK;
	HLCD_Send_String_4bit(string); break;

	case LCD_GO_ROW2 : HLCD_Send_Command_4bit(LCD_GO_ROW2+column);status =E_OK;
	HLCD_Send_String_4bit(string); break;

	case LCD_GO_ROW3 : HLCD_Send_Command_4bit(LCD_GO_ROW3+column);status =E_OK;
	HLCD_Send_String_4bit(string); break;

	case LCD_GO_ROW4 : HLCD_Send_Command_4bit(LCD_GO_ROW4+column);status =E_OK;
	HLCD_Send_String_4bit(string); break;

	default :status =E_NOT_OK; break;
	}
	return status ;
}

/********************************/
Std_ReturnType HLCD_Send_CursorPosition_4bit(u8 row , u8 column)
{
	Std_ReturnType status =E_OK;
	switch(row)
	{
	case LCD_GO_ROW1 : HLCD_Send_Command_4bit(LCD_GO_ROW1+column);status =E_OK;
	break;

	case LCD_GO_ROW2 : HLCD_Send_Command_4bit(LCD_GO_ROW2+column);status =E_OK;
	break;

	case LCD_GO_ROW3 : HLCD_Send_Command_4bit(LCD_GO_ROW3+column);status =E_OK;
	break;

	case LCD_GO_ROW4 : HLCD_Send_Command_4bit(LCD_GO_ROW4+column);status =E_OK;
	break;

	default :status =E_NOT_OK; break;
	}
	return status ;
}
/**************************************/
Std_ReturnType HLCD_Send_char_Position_4bit(u8 data,u8 row , u8 column)
{
	Std_ReturnType status =E_OK;
	switch(row)
	{
	case LCD_GO_ROW1 : HLCD_Send_Command_4bit(LCD_GO_ROW1+column);status =E_OK;
	HLCD_Send_char_4bit(data);break;

	case LCD_GO_ROW2 : HLCD_Send_Command_4bit(LCD_GO_ROW2+column);status =E_OK;
	HLCD_Send_char_4bit(data); break;

	case LCD_GO_ROW3 : HLCD_Send_Command_4bit(LCD_GO_ROW3+column);status =E_OK;
	HLCD_Send_char_4bit(data); break;

	case LCD_GO_ROW4 : HLCD_Send_Command_4bit(LCD_GO_ROW4+column);status =E_OK;
	HLCD_Send_char_4bit(data); break;

	default :status =E_NOT_OK; break;
	}
	return status ;
}
/*********************************************/
#endif
/********************** helper functions ***********************/

/***********************/
Std_ReturnType convert_uint32_to_string(u32 value, u8 *str){
	Std_ReturnType ret = E_OK;
	if(NULL == str){
		ret = E_NOT_OK;
	}
	else{
		memset((u8 *)str, '\0', 11);
		sprintf(str, "%i", value);
	}
	return ret;
}
/**************************************************************/
Std_ReturnType convert_uint8_to_string(u8 value, u8 *str){
	Std_ReturnType ret = E_NOT_OK;
	if(NULL == str){
		ret = E_NOT_OK;
	}
	else{
		memset((char *)str, '\0', 4);
		sprintf(str, "%i", value);
		ret=E_OK;
	}
	return ret;
}
/***************************************/
Std_ReturnType convert_uint16_to_string(u16 value, u8 *str){
	Std_ReturnType ret = E_NOT_OK;
	if(NULL == str){
		ret = E_NOT_OK;
	}
	else{
		memset((char *)str, '\0', 8);
		sprintf(str, "%i", value);
		ret=E_OK;
	}
	return ret;
}
/***
 * @brief this function is used to send u16 data to lcd in 8bit mode
 * @param value u16 value we want to send
 * @param row the required row
 * @param column  the required column
 */
/*************************************/
void SEND_U16_8BIT(u16 value,u8 row ,u8 column)
{
	u8 arr[8];
	convert_uint16_to_string(value,arr);
	HLCD_Send_String_Position_8bit(arr,row ,column);
}
/***
 * @brief this function is used to send u16 data to lcd in 4bit mode
 * @param value u16 value we want to send
 * @param row the required row
 * @param column  the required column
 */
/*************************************/
void SEND_U16_4BIT(u16 value,u8 row ,u8 column)
{
	u8 arr[8];
	convert_uint16_to_string(value,arr);
	HLCD_Send_String_Position_4bit(arr,row ,column);
}
