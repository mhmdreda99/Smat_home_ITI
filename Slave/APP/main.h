/**
 * @file main.h
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef APP_MAIN_H_
#define APP_MAIN_H_


#define	ON				1
#define	OFF				0

#define	TURN_LIGHT_ON	0
#define	TURN_LIGHT_OFF	1
#define TURN_FAN_ON		2
#define	TURN_FAN_OFF    3
#define	GARAGE_ON		4
#define	GARAGE_OFF      5
#define	SYSTEM_OFF		8
#define	SYSTEM_ON		9
#define DOOR_OPEN       11
#define DOOR_CLOSE      12
#define	DEFAULT_STATE	10
#define		SPDR 		*((volatile u8 *)0x2F)



#endif /* APP_MAIN_H_ */
