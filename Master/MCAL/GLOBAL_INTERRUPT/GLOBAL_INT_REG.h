/*
 * GLOBAL_INT_REG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_GLOBAL_INTERRUPT_GLOBAL_INT_REG_H_
#define MCAL_GLOBAL_INTERRUPT_GLOBAL_INT_REG_H_

#define SREG         	  *((volatile u8*)(0x5F))
#define SREG_I         7

#define Enable_Global_Interrupt()       SET_BIT(SREG,SREG_I)

#define Disable_Global_Interrupt()     CLEAR_BIT(SREG,SREG_I)

#endif /* MCAL_GLOBAL_INTERRUPT_GLOBAL_INT_REG_H_ */
