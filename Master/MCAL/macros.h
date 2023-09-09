/*
 * macros.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_MACROS_H_
#define MCAL_MACROS_H_

#define SET_BIT(register_,position)  	 register_|=(1<<position)
#define CLEAR_BIT(register_,position)    register_&=~(1<<position)
#define TOGGLE_BIT(register_,position)   register_^=(1<<position)
#define GET_BIT(register_,position)      (((register_)>>(position))&0x01)

#endif /* MCAL_MACROS_H_ */
