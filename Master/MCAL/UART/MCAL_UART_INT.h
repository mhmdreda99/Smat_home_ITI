/*
 * MCAL_UART_INT.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_UART_MCAL_UART_INT_H_
#define MCAL_UART_MCAL_UART_INT_H_

/**************MACRO DECLERATION SECTION********/
#define RX_INT  1
#define DRE_INT 2
#define TX_INT  3
/***************FUNCTION LIKE MACRO SECTION*****/
// enable access UBRRH REG
#define UART_ENABLE_WRITE_UBRRH(x)				 CLEAR_BIT(x,UCSRC_URSEL)

//enable access UCSRC  REG
#define UART_ENABLE_WRITE_UCSRC(x)				 SET_BIT(x,UCSRC_URSEL)

//Enable Receiver Mode
#define UART_RECEIVER_ENABLE()  	 	 	  SET_BIT(UCSRB,UCSRB_RXEN)

//DISABLE Receiver Mode
#define UART_RECEIVER_DISABLE() 	 	 	  CLEAR_BIT(UCSRB,UCSRB_RXEN)

//Enable Transmitter Mode
#define UART_TRANSMITTER_ENABLE() 		 	  SET_BIT(UCSRB,UCSRB_TXEN)

//DISABLE Transmitter Mode
#define UART_TRANSMITTER_DISABLE()		 	  CLEAR_BIT(UCSRB,UCSRB_TXEN)

//ENABLE Asynchronous mode
#define UART_ENABLE_ASYNCH_MODE(x)  		       CLEAR_BIT(x,UCSRC_UMSEL)


//ENABLE synchronous mode
#define UART_ENABLE_SYNCH_MODE(x) 		      SET_BIT(x,UCSRC_UMSEL)

//Paraity mode disable
#define UART_DISABLE_PARITYMOOD(x)              do{\
												CLEAR_BIT(x,UCSRC_UPM0);\
												CLEAR_BIT(x,UCSRC_UPM1);}\
											   while(0)
//enable even parity
#define UART_ENABLE_EVEN_PARITYMOOD(x)         do{\
												CLEAR_BIT(x,UCSRC_UPM0);\
												SET_BIT(x,UCSRC_UPM1);}\
											  while(0)
//enable odd parity
#define UART_ENABLE_ODD_PARITYMOOD(x)          do{\
												SET_BIT(x,UCSRC_UPM0);\
												SET_BIT(x,UCSRC_UPM1);}\
											  while(0)

//STOP BIT 1b SELECT
#define UART_SET_1b_STOP(x)  				  CLEAR_BIT(x,UCSRC_USBS)

//STOP BIT 2b SELECT
#define UART_SET_2b_STOP(x)  			      SET_BIT(x,UCSRC_USBS)

// enable 5 bit mode
#define UART_ENABLE_5bit_DATAMODE(x)           do{\
												CLEAR_BIT(x,UCSRC_UCSZ0);\
												CLEAR_BIT(x,UCSRC_UCSZ1);\
												CLEAR_BIT(UCSRB,UCSRB_UCSZ2);}\
										      while(0)
//enable 6 bit mode
#define UART_ENABLE_6bit_DATAMODE(x)           do{\
												SET_BIT(x,UCSRC_UCSZ0);\
												CLEAR_BIT(x,UCSRC_UCSZ1);\
												CLEAR_BIT(x,UCSRB_UCSZ2);}\
											 while(0)
//enable 7 bit mode
#define UART_ENABLE_7bit_DATAMODE(x)          do{\
												CLEAR_BIT(x,UCSRC_UCSZ0);\
												SET_BIT(x,UCSRC_UCSZ1);\
												CLEAR_BIT(UCSRB,UCSRB_UCSZ2);}\
											 while(0)
//enable 8 bit mode
#define UART_ENABLE_8bit_DATAMODE(x)          do{\
												SET_BIT(x,UCSRC_UCSZ0);\
												SET_BIT(x,UCSRC_UCSZ1);\
												CLEAR_BIT(UCSRB,UCSRB_UCSZ2);}\
											 while(0)
//enable 9bit mode
#define UART_ENABLE_9bit_DATAMODE(x)          do{\
												SET_BIT(x,UCSRC_UCSZ0);\
												SET_BIT(x,UCSRC_UCSZ1);\
												SET_BIT(UCSRB,UCSRB_UCSZ2);}\
											 while(0)
// UART synch TX at raising
#define UART_SYNCH_TX_AT_RISING_SAMP_AT_FALL(x)   CLEAR_BIT(x,UCSRC_UCPOL)

// UART synch TX at falling
#define UART_SYNCH_TX_AT_FALL_SAMP_AT_RISING(x)   SET_BIT(x,UCSRC_UCPOL)



//frame error flag
#define UART_FRAME_ERROR_READ()     		     GET_BIT(USCRA,UCSRA_FrameE)

//over run error flag
#define UART_OVERRUN_ERROR_READ()     	         GET_BIT(USCRA,UCSRA_DOR)

//UART parity error read
#define UART_PARITY_ERROR_READ()                 GET_BIT(USCRA,UCSRA_PE)

//double the asynchro speed
#define UART_CONVERT_ASYNCH_TO_DOUBLESPEED() 	 SET_BIT(USCRA,UCSRA_U2X)

//enable multi processor communication mode
#define UART_ENABLE_MULTI_PROCESSOR_MODE()		 SET_BIT(USCRA,UCSRA_MPCM)

/************interrupt configurations*********/

//USART Data Register Empty Interrupt Enable
/******************RX INTERRUPT CONFIG ********************/
//enable RX interrupt
#define UART_ENABLE_RX_INTERRUPT() 		  		 SET_BIT(UCSRB,UCSRB_RXCIE)
//disable RX INTERRUPT
#define UART_DISABLE_RX_INTERRUPT() 			 CLEAR_BIT(UCSRB,UCSRB_RXCIE)
// UART receive complete flag (RO)
#define UART_RX_FLAG_READ()   		    	     GET_BIT(UCSRA,UCSRA_RXC)

//clear rx flag
#define UART_RX_CLEAR_FLAG()   			 	     SET_BIT(UCSRA,UCSRA_TXC)
/******************TX INTERRUPT CONFIG ********************/

//enable TX interrupt
#define UART_ENABLE_TX_INTERRUPT()  	 SET_BIT(UCSRB,UCSRB_TXCIE)
//disable TX interrupt
#define UART_DISABLE_TX_INTERRUPT()   	 CLEAR_BIT(UCSRB,UCSRB_TXCIE)

// UART TRANS complete flag (RW)
#define UART_TX_FLAG_READ()   			  GET_BIT(UCSRA,UCSRA_TXC)

//clear tx flag
#define UART_TX_CLEAR_FLAG()   			  SET_BIT(UCSRA,UCSRA_TXC)
/******************USART Data Register Empty Interrupt Enable********************/
#define UART_ENABLE_DRE_INTERRUPT()       SET_BIT(UCSRB,UCSRB_UDRIE)
//disable the DRE interrupt
#define UART_DISABLE_DRE_INTERRUPT()      CLEAR_BIT(UCSRB,UCSRB_UDRIE)


// data buffer is empty
#define UART_DATA_REG_EMPTYFLAG_READ()    GET_BIT(UCSRA,UCSRA_UDRE)
//clear flag
#define UART_SET_DATA_REG_EMPTYFLAG()    SET_BIT(UCSRA,UCSRA_UDRE)


/**************FUNCTION DECLERATION SECTION*****/
void MUART_INIT(void(*Tx_Callback)(void),void(*Rx_Callback)(void),void(*EDR_Callback)(void));

void UART_SEND_CHAR_BLOCKING(u8 data);
void UART_SEND_STRING_BLOCKING(u8 * str);

u8 UART_RECEIVE_CHAR_BLOCKING(void);

#endif /* MCAL_UART_MCAL_UART_INT_H_ */
