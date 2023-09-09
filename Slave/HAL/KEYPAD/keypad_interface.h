/*
 * keypad.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_

/************include section************/

/************Macro section* ***********/


/************Macro Function section************/


/************Data type section************/
typedef enum
{
BUTTON_RELEASED,
BUTTON_PRESSED,
}button_state_t;

/************Function Declaration section************/

void keypad_read(char *button_pos_ );
void keypad_read1(char *button_pos_);
button_state_t keypad_readd(char *button_pos_ );

#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
