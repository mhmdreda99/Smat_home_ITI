/*
 * MCAL_UART_PRIVATE.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_UART_MCAL_UART_PRIVATE_H_
#define MCAL_UART_MCAL_UART_PRIVATE_H_

/**************MACRO DECLERATION SECTION********/
//selecting the UART modes
#define UART_ENABLE_SYNCHRONOUS_MODE     1
#define UART_ENABLE_ASYNCHRONOUS_MODE    2

//set baud rate cnfg
#define UART_BAUDRATE_USE_ASYNCH_NORMAL_SPEED 	     1
#define UART_BAUDRATE_USE_ASYNCH_DOUBLE_SPEED   	 2
#define UART_BAUDRATE_USE_SYNCH_MASTER_MODE  		 3
//set format size
#define UART_5BIT_FRAME_FORMAT            1
#define UART_6BIT_FRAME_FORMAT			  2
#define UART_7BIT_FRAME_FORMAT			  3
#define UART_8BIT_FRAME_FORMAT			  4
#define UART_9BIT_FRAME_FORMAT			  5
//SET STOP BITS NUMBER
#define UART_1STOP_BIT                    1
#define UART_2STOP_BITS                   2
// SET FORMAT for PARITY  BITS
#define UART_PARAITY_DISABLED             1
#define UART_PARAITY_EVEN			      2
#define UART_PARAITY_ODD				  3
//TX mode
#define UART_TX_MODE_ENABLED			  1
#define UART_TX_MODE_DISABLED			  2
//RX mode
#define UART_RX_MODE_ENABLED			  3
#define UART_RX_MODE_DISABLED			  4
//TX interrupt
#define UART_TX_INT_ENABLED				  1
#define UART_TX_INT_DISABLED			  2
//RX interrupt
#define UART_RX_INT_ENABLED				  3
#define UART_RX_INT_DISABLED			  4
//DRE INTERRUPT
#define UART_DRE_INT_ENABLED			  5
#define UART_DRE_INT_DISABLED			  6
/*********function deceleration section************/
static inline void Set_BRG_VAL(const u16 val);
static inline void UART_CALLBACK(u8 INT_NUMBER,void (*ptr)(void));
#endif /* MCAL_UART_MCAL_UART_PRIVATE_H_ */
