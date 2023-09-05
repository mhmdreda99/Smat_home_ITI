/**
 * @file EXIT_config.h
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef EXIT_CONFIG_H
#define EXIT_CONFIG_H

/*
        Options   ENABLE / DISABLE
*/

/*
	Options:
				ENABLE 			DISABLE
*/
#define		EXTI_INT0_ENABLE			ENABLE
#define		EXTI_INT1_ENABLE			DISABLE


/*
	Options:
				FALLING_EDGE	RISING_EDGE		ON_CHANGE	LOW_LEVEL
*/
#define		EXTI_INT0_SENSE_SIGNAL		FALLING_EDGE
#define		EXTI_INT1_SENSE_SIGNAL		LOW_LEVEL

#endif
