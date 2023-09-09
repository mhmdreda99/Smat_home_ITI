/*
 * MCAL_UART_REG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_UART_MCAL_UART_REG_H_
#define MCAL_UART_MCAL_UART_REG_H_



/**************MACRO DECLERATION SECTION********/
//UDR REGISTER (DATA REGISTER)
#define UDR    *((volatile u8*)(0x2C))

//Control and Status Register A – UCSRA

#define UCSRA  *((volatile u8*)(0x2B))

// UART receive complete flag (RO)
//RXCIE
#define UCSRA_RXC   7

// UART TRANS complete flag (RW)

#define UCSRA_TXC   6
//The UDRE Flag indicates if the transmit buffer (UDR) is ready to receive new data.If UDRE is one, the buffer is empty

#define UCSRA_UDRE  5

//This bit (ro) is set if the next character in the receive buffer had a Frame Error

#define UCSRA_FrameE   4
//This bit is set if a Data OverRun condition is detected. A Data OverRun occurs when the
//receive buffer is full (two characters)

#define UCSRA_DOR  3

//This bit(ro) is set if the next character in the receive buffer had a Parity Error

#define UCSRA_PE   2
//Double the USART Transmission Speed This bit only has effect for the asynchronous operation

#define UCSRA_U2X  1

//This bit enables the Multi-processor Communication mode.

#define UCSRA_MPCM  0

/****************************USART Control and Status Register B – UCSRB*****************/
#define UCSRB  *((volatile u8*)(0x2A))
//RX Complete Interrupt Enable
#define UCSRB_RXCIE 7

//TX Complete Interrupt Enable
#define UCSRB_TXCIE 			 6

//USART Data Register Empty Interrupt Enable
#define UCSRB_UDRIE   			 5


//Enable Receiver Mode
#define UCSRB_RXEN   			 4
//Enable Transmitter  Mode
#define UCSRB_TXEN 				 3
//sel frame size with ucsz0 , ucsz1
#define  UCSRB_UCSZ2 			 2
//enable ninth data bit of the received character
#define  UCSRB_RXB8 			 1
//enable ninth data bit of the transmitter character
#define  UCSRB_TXB8 			 0
/****************************USART Control and Status Register C – UCSRC*****************/
//The UCSRC Register shares the same I/O location as the UBRRH Register
#define UCSRC      *((volatile u8 *) (0x40))
//This bit selects between accessing the UCSRC or the UBRRH Register
//The URSEL must be one when writing the UCSRC.
#define UCSRC_URSEL  			 	 7
//USART Mode Select
#define UCSRC_UMSEL  				 6
//Paraity mode select
#define UCSRC_UPM0   				 4
#define UCSRC_UPM1  				 5
//STOP BIT SELECT
#define UCSRC_USBS   			     3
//selecting data frame size
#define UCSRC_UCSZ1  		 	     2

#define UCSRC_UCSZ0     			 1
//select clock polarity
//This bit is used for Synchronous mode only
//Write this bit to zero when Asynchronous mode is used.
//The UCPOL bit sets the relationship between data output change and data input sample, and the synchronous clock (XCK).
#define UCSRC_UCPOL    				 0
//USART Baud Rate Registers
#define UBRRL    *((volatile u8 *)(0x29))
#define UBRRL_UBBRR0   0

#define UBRRL_UBBRR1   1

#define UBRRL_UBBRR2   2

#define UBRRL_UBBRR3   3

#define UBRRL_UBBRR4   4

#define UBRRL_UBBRR5   5

#define UBRRL_UBBRR6   6

#define UBRRL_UBBRR7   7

#define UBRRH    *((volatile u8 *)(0x40))
#define UBRRH_UBBRR8 	  0

#define UBRRH_UBBRR9  	  1

#define UBRRH_UBBRR10 	  2

#define UBRRH_UBBRR11     3
//This bit selects between accessing the UBRRH or the UCSRC Register.
//It is read as zero when reading UBRRH. The URSEL must be zero when writing the UBRRH.
/***************FUNCTION LIKE MACRO SECTION*****/

/***************DATA TYPES SECTION**************/

/**************FUNCTION DECLERATION SECTION*****/







#endif /* MCAL_UART_MCAL_UART_REG_H_ */
