/*
 * RTOS_PRIVATE.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef RTOS_RTOS_PRIVATE_H_
#define RTOS_RTOS_PRIVATE_H_
/*************** data type Section****************/
typedef struct
{
void(*pf)(void);
u8 priority;
u16 periodicity;
u8 state;
u8 F_Delay;
}TASK_T;

typedef enum
{
TASK_IDLE,
TASK_SUSPENDED,
TASK_RUNNING,
}TASK_STATE_T;

/********FUNCTION DECLERATION*********/
void Schedular(void);

#endif /* RTOS_RTOS_PRIVATE_H_ */
