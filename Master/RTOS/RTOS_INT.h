/*
 * RTOS_INT.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef RTOS_RTOS_INT_H_
#define RTOS_RTOS_INT_H_


/************FUNCTION DECLERATION SECTION**************/
Std_ReturnType Create_Task(u8 Priority, u16 periodicity,u8 First_delay ,void(*ptr)(void));
void RTOS_START(void);
#endif /* RTOS_RTOS_INT_H_ */
