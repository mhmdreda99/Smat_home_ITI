/*
 * RTOS_INT.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */
/****************include section****************/
#include "../MCAL/std_types.h"
#include "../MCAL/Std_Library.h"
#include"../MCAL/macros.h"
#include"../MCAL/GLOBAL_INTERRUPT/GLOBAL_INT_REG.h"
#include "../MCAL/DIO/MCAL_DIO_INTERFACE.h"
#include"../MCAL/Timer_0/MCAL_TIMER0_INT.h"
#include "RTOS_PRIVATE.h"
#include "RTOS_CNFG.h"
#include "RTOS_INT.h"


TASK_T Tasks[5]={{NULL}};
/***
 * @brief this function is used to create a task
 * @param Priority priority of task depend on its position of array of structures
 * @param periodicity periodicity time of the task
 * @param PTR call back function
 * @return Std_ReturnType function executed correctly or not
 */
Std_ReturnType Create_Task(u8 Priority, u16 periodicity,u8 First_delay ,void(*ptr)(void))
{
	Std_ReturnType Status=E_NOT_OK;
	if(Tasks[Priority].pf!=NULL)
	{
		Status=E_RESERVED;
	}
	else
	{
		Tasks[Priority].periodicity= periodicity;
		Tasks[Priority].pf=ptr;
		Tasks[Priority].priority=Priority;
		Tasks[Priority].F_Delay=First_delay;
		Tasks[Priority].state=TASK_IDLE;
		Status=E_OK;
	}
	return Status;
}

void RTOS_START(void)
{
	TIMER0_SETCALLBACK(&Schedular);
	Enable_Global_Interrupt();
	MTIMER0_VoidInit();
}
/***************************************/
void Task_Suspend(u8 Priority)
{
	Tasks[Priority].state=TASK_SUSPENDED;
}
/***************************************/
void Task_Resume(u8 Priority)
{
	Tasks[Priority].state=TASK_IDLE;
}
/***************************************/
void Task_Delete(u8 Priority)
{
	Tasks[Priority].pf=NULL;
}
/***************************************/

void Schedular(void)
{
 	u8 Task_Counter=0;

	for(Task_Counter=0;Task_Counter<TASK_MAX_NUMBER;Task_Counter++)
	{
		if(Tasks[Task_Counter].state==TASK_IDLE)
		{
			if(NULL!=Tasks[Task_Counter].pf)
			{
				// if(counter_ticks%Tasks[Task_Counter].periodicity==0)
				if(Tasks[Task_Counter].F_Delay==0)
				{
					Tasks[Task_Counter].pf();
					Tasks[Task_Counter].F_Delay=Tasks[Task_Counter].periodicity;
				}
				else
				{
					Tasks[Task_Counter].F_Delay--;
				}
			}
			else
			{
				/*DO NOTHING*/
			}

		}

		else{
			/*DO NOTHING*/
		}


	}
}
