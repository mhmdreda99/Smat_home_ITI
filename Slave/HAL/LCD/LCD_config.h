/**
 * @file LCD_config.h
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#define LCD_DATA_PORT       PORTC
#define LCD_CTRL_PORT       PORTB

#define LCD_EN_PIN          PIN0
#define LCD_RW_PIN          PIN1
#define LCD_RS_PIN          PIN2


/*Function set configurations */
#define TwoLines 			TwoLines_ON			 	/*TwoLines_ON or TwoLines_OFF*/
#define FontSize 	 		R8C5    				/*R8C5 or R11C5				 */
/*Display set configurations */
#define Cursor 	 			OFF						/*ON or OFF	 	     */
#define Blink				OFF						/*ON or  OFF		 */

#endif
