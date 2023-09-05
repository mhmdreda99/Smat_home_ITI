/**
 * @file LCD_private.h
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

#define POSITION_FIXED_ADDRES 		0x40
/*Function Set definitions*/
#define Function_Set_Command		0b110000
#define TwoLines_ON 				0b1000
#define TwoLines_OFF	 			0
#define R8C5						0
#define R11C5						(1<<2)
/*Display definitions*/
#define Display_Set_Command			0x0C
#define ON						    1
#define OFF							0
/*Sending command Function*/
static void HLCD_voidSendCommands(u8 Copy_u8Command) ;


#endif
