/*
 * hal_lcd.h
 *
 *  Created on: 2023/8/1
 *      Author: Karim_Zidan
 */

#ifndef HAL_LCD_HAL_LCD_INTERFACE_H_
#define HAL_LCD_HAL_LCD_INTERFACE_H_

/************include section************/


/************Macro section************/
#define LCD_CMD_CLEAR_DISPLAY 					  		0x01
#define LCD_CMD_CURSOR_HOME   							0x02
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF  					0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON   				    0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF 					0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON   					0x07
#define LCD_CMD_DISPLAY_ON_CURSOR_ON_BC_ON              0x0F
#define LCD_CMD_DISPLAY_ON_CURSOR_ON_BC_OFF  			0x0E
#define LCD_CMD_DISPLAY_ON_CURSOR_OFF_BC_OFF			0x0C
#define LCD_CMD_DISPLAY_OFF 							0x08
#define LCD_CMD_DISPLAY_ON_BL_OFF_CURSOR_ON     	    0x0D
#define MOVE_CURSOR_SHIFT_RIGHT 				     	0x1C
#define MOVE_CURSOR_SHIFT_LEFT 					        0x18
#define FUNCTION_SET_8bit_Mode_2row_11_line				0x3C
#define FUNCTION_SET_8bit_Mode_2row_8_line				0x38
#define FUNCTION_SET_4bit_Mode_2row_11_line				0x2C
#define FUNCTION_SET_4bit_Mode_2row_8_line	 			0x28
#define _LCD_CGRAM_START             				    0x40

#define LCD_GO_ROW1               					    0x80
#define LCD_GO_ROW2                                     0xC0
#define LCD_GO_ROW3                                     0x94
#define LCD_GO_ROW4                                     0xD4


/************Macro Function section************/


/************Data type section************/


/************Function Declaration section************/
void HLCD_INIT_8bit(void);
void HLCD_Send_String_8bit( u8 *data);
void HLCD_Send_Command_8bit( u8 command);
void HLCD_Send_char_8bit( u8  data);
Std_ReturnType HLCD_Send_String_Position_8bit(u8 *string,u8 row , u8 column);
Std_ReturnType HLCD_Send_char_Position_8bit(u8 data,u8 row , u8 column);
Std_ReturnType HLCD_Send_CursorPosition_8bit(u8 row , u8 column);
void SEND_U16_8BIT(u16 value,u8 row ,u8 column);

Std_ReturnType convert_uint32_to_string(u32 value, u8 *str);
void decimalToHexadecimal(int decimalNumber, char *hexadecimalResult);
Std_ReturnType convert_uint8_to_string(u8 value, u8 *str);
void HLCD_Send_Float1(const float data);
Std_ReturnType convert_uint16_to_string(u16 value, u8 *str);
Std_ReturnType convert_uint8_to_string(u8 value, u8 *str);


void HLCD_INIT_4bit(void);
void HLCD_Send_Command_4bit(const u8 command);
void HLCD_Send_char_4bit(const u8  data);
void HLCD_Send_String_4bit( u8 *data);
Std_ReturnType HLCD_Send_String_Position_4bit(u8 *string,u8 row , u8 column);
Std_ReturnType HLCD_Send_CursorPosition_4bit(u8 row , u8 column);
Std_ReturnType HLCD_Send_char_Position_4bit(u8 data,u8 row , u8 column);
void SEND_U16_4BIT(u16 value,u8 row ,u8 column);


Std_ReturnType convert_uint32_to_string(u32 value, u8 *str);
Std_ReturnType convert_uint8_to_string(u8 value, u8 *str);
#endif /* HAL_LCD_HAL_LCD_INTERFACE_H_ */
