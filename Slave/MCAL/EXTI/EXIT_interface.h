/**
 * @file EXIT_interface.h
 * @author mhmdreda99 (Moreda491999@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef EXIT_INTERFACE_H
#define EXIT_INTERFACE_H

#define		  INT0			  0
#define		  INT1			  1
#define		  INT2			  2

#define       ENABLE          1
#define       DISABLE         0





void MEXTI_voidInit() ;
s8 MEXTI_voidInturrupt(u8 Copy_u8InterruptValue,u8 Copy_u8State) ;



#endif
