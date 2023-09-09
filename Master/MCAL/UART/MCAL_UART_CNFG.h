/*
 * MCAL_UART_CNFG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_UART_MCAL_UART_CNFG_H_
#define MCAL_UART_MCAL_UART_CNFG_H_

/**************MACRO DECLERATION SECTION********/
//select UART mode (synch or asynch)
#define UART_MODE    				UART_ENABLE_ASYNCHRONOUS_MODE
//select between asynch normal speed or doublespeed or asynchronous master

#define UART_BAUD_RATE_CNFG			UART_BAUDRATE_USE_ASYNCH_NORMAL_SPEED
//set the required baud rate value
#define UART_BAUDRATE_VALUE    		 9600
//select the frame data size in bits
#define UART_FRAME_FORMAT_SIZE       UART_8BIT_FRAME_FORMAT
//select stop bits number
#define UART_STOP_BITS_NUMBER        UART_1STOP_BIT
//select parity mode
#define UART_SELECT_PARITY_MODE      UART_PARAITY_DISABLED
// enable or disable transmitter
#define UART_TX_MODE  				 UART_TX_MODE_DISABLED
//interrupt state select
#define UART_RX_MODE		    	 UART_RX_MODE_ENABLED

//TX interrupt state select
#define UART_TX_INTTERUPT			 UART_TX_INT_DISABLED
//RX interrupt state select
#define UART_RX_INTTERUPT			 UART_RX_INT_DISABLED
//DRE INTERRUPT state Select
#define UART_DRE_INTERRUPT           UART_DRE_INT_DISABLED

/***************DATA TYPES SECTION**************/



#endif /* MCAL_UART_MCAL_UART_CNFG_H_ */
