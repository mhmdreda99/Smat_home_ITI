/*
 * hal_lcd_cnfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: karim_zidan
 */


#ifndef HAL_LCD_HAL_LCD_CNFG_H_
#define HAL_LCD_HAL_LCD_CNFG_H_

#define LCD_PORT_DATA   PORTB_
#define LCD_PORT_CTRL   PORTC_

#define LCD_4bit_MODE     2
#define LCD_8bit_MODE     1

#define LCD_MODE         LCD_4bit_MODE

#define  Rs              pin7
#define  R_W             pin5
#define  En              pin6

#if LCD_MODE == LCD_8bit_MODE

#define LCD_8bit_DATA_PIN0    pin0
#define LCD_8bit_DATA_PIN1    pin1
#define LCD_8bit_DATA_PIN2    pin2
#define LCD_8bit_DATA_PIN3    pin3
#define LCD_8bit_DATA_PIN4    pin4
#define LCD_8bit_DATA_PIN5    pin5
#define LCD_8bit_DATA_PIN6    pin6
#define LCD_8bit_DATA_PIN7    pin7

#elif LCD_MODE == LCD_4bit_MODE

#define LCD_4bit_DATA_PIN0    pin0
#define LCD_4bit_DATA_PIN1    pin1
#define LCD_4bit_DATA_PIN2    pin2
#define LCD_4bit_DATA_PIN3    pin3

#else
#error"wrong lcd config"
#endif
#endif /* HAL_LCD_HAL_LCD_CNFG_H_ */
