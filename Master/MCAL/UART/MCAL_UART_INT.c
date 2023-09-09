/*
 * MCAL_UART_INT.c

 *
 *  Created on: ??þ/??þ/
 *      Author: Karim_Zidan
 */
/*********************INCLUDE SECTION *****************/

#include"../Std_Library.h"
#include"../std_types.h"
#include"../macros.h"
#include"../DIO/MCAL_DIO_REGISTERS.h"
#include"MCAL_UART_PRIVATE.h"
#include"MCAL_UART_CNFG.h"
#include"MCAL_UART_REG.h"
#include"MCAL_UART_INT.h"
#include"../GLOBAL_INTERRUPT/GLOBAL_INT_REG.h"
/*********************interrupt call backs*************************/
//static call back PTR
static void (*UART_RX_CALLBACK)(void)=NULL;
//static call back PTR
static void (*UART_DRE_CALLBACK)(void)=NULL;
//static call back PTR
static void (*UART_TX_CALLBACK)(void)=NULL;


/*******************************************************/
/***
 * @brief This function is used to initiallize the uart in asynchronous or synchronous mode and init the interrupts
 * @param TX_Callback  The call back function send by the user fired when transmitting is done
 * @param RX_Callback  The call back function send by the user fired when Receiving is done
 * @param EDR_Callback  The call back function send by the user fired when the data register is empty
 */
void MUART_INIT(void(*TX_Callback)(void),void(*RX_Callback)(void),void(*EDR_Callback)(void))
{
	u16 L_UBBR =0;
	u8 L_SETTINGS=0;

	/**********************BAUD RATE CONFIGURATIONS**********************/
#if UART_BAUD_RATE_CNFG==UART_BAUDRATE_USE_ASYNCH_NORMAL_SPEED
	L_UBBR=(u16)((u32)F_CPU/((u32)16*UART_BAUDRATE_VALUE))-1;
	Set_BRG_VAL(L_UBBR);
#elif UART_BAUD_RATE_CNFG==UART_BAUDRATE_USE_ASYNCH_DOUBLE_SPEED
	L_UBBR=(u16)(((u32)F_CPU/((u32)8*UART_BAUDRATE_VALUE))-1);
	Set_BRG_VAL(L_UBBR);
#elif UART_BAUD_RATE_CNFG==UART_BAUDRATE_USE_SYNCH_MASTER_MODE
	L_UBBR=(u16)(((u32)F_CPU/((u32)2*UART_BAUDRATE_VALUE))-1);
	Set_BRG_VAL(L_UBBR);
#else
#error "WRONG SELECTION OF BAUDRATE CONFIGURATIONS CHECK UART CONFIGURATIONS"
#endif
	/*******************enable writing to control register******/

	/************check transmitting mode**********/
#if UART_TX_MODE==UART_TX_MODE_ENABLED
	UART_TRANSMITTER_ENABLE();
#elif UART_TX_MODE==UART_TX_MODE_DISABLED
	UART_TRANSMITTER_DISABLE();
#else
#error "Wrong UART TRANSMITTER MODE CHECK UART CONFIG"
#endif
	/************check receiving mode**********/
#if UART_RX_MODE==UART_RX_MODE_ENABLED
	UART_RECEIVER_ENABLE();
#elif UART_RX_MODE==UART_RX_MODE_DISABLED
	UART_RECEIVER_DISABLE();
#else
#error "Wrong UART TRANSMITTER MODE CHECK UART CONFIG"
#endif
	UART_ENABLE_WRITE_UCSRC(L_SETTINGS);
	/***************select UART mode***********/
#if UART_MODE==UART_ENABLE_SYNCHRONOUS_MODE
	UART_ENABLE_SYNCH_MODE(L_SETTINGS);
#elif UART_MODE==UART_ENABLE_ASYNCHRONOUS_MODE
	UART_ENABLE_ASYNCH_MODE(L_SETTINGS);
#else
#error "Wrong Selection of UART MODE Check UART CONFIGURATIONS"
#endif
	/****************setting frame format**************/
	/****************stop bits format**************/
#if UART_STOP_BITS_NUMBER == UART_2STOP_BITS
	UART_SET_2b_STOP(L_SETTINGS);
#elif UART_STOP_BITS_NUMBER == UART_1STOP_BIT
	UART_SET_1b_STOP(L_SETTINGS);
#else
#error "WRONG STOP BITS CONFIGURATION FOR UART"
#endif
	/**********************setting parity bits mode***************/
#if UART_SELECT_PARITY_MODE == UART_PARAITY_DISABLED
	UART_DISABLE_PARITYMOOD(L_SETTINGS);
#elif UART_SELECT_PARITY_MODE == UART_PARAITY_EVEN
	UART_ENABLE_EVEN_PARITYMOOD(L_SETTINGS);
#elif UART_SELECT_PARITY_MODE == UART_PARAITY_ODD
	UART_ENABLE_ODD_PARITYMOOD(L_SETTINGS);
#else
#error "WRONG PARAITY BITS CONFIGURATION FOR UART"
#endif
	/**********************setting frame bits mode***************/
#if UART_FRAME_FORMAT_SIZE==UART_5BIT_FRAME_FORMAT
	UART_ENABLE_5bit_DATAMODE(L_SETTINGS);
#elif UART_FRAME_FORMAT_SIZE==UART_6BIT_FRAME_FORMAT
	UART_ENABLE_6bit_DATAMODE(L_SETTINGS);
#elif UART_FRAME_FORMAT_SIZE==UART_7BIT_FRAME_FORMAT
	UART_ENABLE_7bit_DATAMODE(L_SETTINGS);
#elif UART_FRAME_FORMAT_SIZE==UART_8BIT_FRAME_FORMAT
	UART_ENABLE_8bit_DATAMODE(L_SETTINGS);
#elif UART_FRAME_FORMAT_SIZE==UART_9BIT_FRAME_FORMAT
	UART_ENABLE_9bit_DATAMODE(L_SETTINGS);
#else
#error "Wrong Frame Size Selection Check UART CONFIGURATIONS"
#endif
	UCSRC=L_SETTINGS;
	/************************interrupt configurations**************/

	//disable the global interrupt during initializing
	Disable_Global_Interrupt();
#if UART_TX_INTTERUPT==UART_TX_INT_ENABLED

	UART_CALLBACK(TX_INT,TX_Callback);
	//enable TX interrupt feature
	UART_ENABLE_TX_INTERRUPT();
	//clear TX flag
	UART_TX_CLEAR_FLAG();
	Enable_Global_Interrupt();

#elif UART_TX_INTTERUPT==UART_TX_INT_DISABLED

	//clear TX flag
	UART_TX_CLEAR_FLAG();
	//disable RX interrupt
	UART_DISABLE_TX_INTERRUPT();
#else
#error "WRONG CONFIGURATION OF UART TX INTERRUPT"
#endif

	/***********RX interrupt configurations***********/
#if UART_RX_INTTERUPT==UART_RX_INT_ENABLED

	UART_CALLBACK(RX_INT,RX_Callback);
	//enable RX interrupt feature
	UART_ENABLE_RX_INTERRUPT();
	//clear RX flag
	UART_RX_CLEAR_FLAG();
	Enable_Global_Interrupt();

#elif UART_RX_INTTERUPT==UART_RX_INT_DISABLED
	//clear RX flag
	UART_RX_CLEAR_FLAG();
	//disable RX interrupt
	UART_DISABLE_RX_INTERRUPT();
#else
#error "WRONG CONFIGURATION OF UART RX INTERRUPT"
#endif
	/***********DRE interrupt configurations***********/
#if UART_DRE_INTERRUPT==UART_DRE_INT_ENABLED

	UART_CALLBACK(DRE_INT,EDR_Callback);

	//enable DRE interrupt feature
	UART_ENABLE_DRE_INTERRUPT();
	//clear DRE flag
	UART_SET_DATA_REG_EMPTYFLAG();
	Enable_Global_Interrupt();

#elif UART_DRE_INTERRUPT==UART_DRE_INT_DISABLED
	//clear DRE flag
	UART_SET_DATA_REG_EMPTYFLAG();
	//disable RX interrupt
	UART_DISABLE_DRE_INTERRUPT();
#else
#error "WRONG CONFIGURATION OF UART RX INTERRUPT"
#endif
}
/*******************************************************/
/***
 * @desc-> this function is used to send data with out interrupt
 * @param data
 */
void UART_SEND_CHAR_BLOCKING(u8 data)
{
	while(!(UART_DATA_REG_EMPTYFLAG_READ()));
	UDR=data;
}
/*******************************************************/
/***
 * @brief this function is used to send string with out interrupt
 * @param str
 */
void UART_SEND_STRING_BLOCKING(u8 *str)
{
	while(*str)
	{
		UART_SEND_CHAR_BLOCKING(*str++);
	}
}
/*******************************************************/
/***
 * @this function is used to receive data with out interrupt
 * @return
 */
u8 UART_RECEIVE_CHAR_BLOCKING(void)
{
	while(!(UART_RX_FLAG_READ()));
	return UDR;
}
/**************************************/
u8 UART_RECEIVE_CHAR_POOLING(void)
{
	if(1==UART_RX_FLAG_READ())
	{
		return UDR;
	}
	else
	{

	}

}
/************helper functions***************/
/**********this function is called by init function used to set the BAUDRATE*********/
static inline void Set_BRG_VAL(const u16 val)
{
	UBRRH=(u8)(val>>8);
	UBRRL=(u8)val;
}



/***
 * @brief this function is called by init function used to set the call backs when inerrupt is on
 * @param INT_NUMBER
 * @param ptr
 */
static inline void UART_CALLBACK(u8 INT_NUMBER,void (*ptr)(void))
{
	switch(INT_NUMBER)
	{
	case RX_INT :
		UART_RX_CALLBACK =ptr;
		break;
	case DRE_INT:
		UART_DRE_CALLBACK =ptr;
		break;
	case TX_INT :
		UART_TX_CALLBACK =ptr;
		break;
	default :break;
	}
}
/***********************************************/





/***********************************************/
//UART RX COMPLETE
void __vector_13(void)  __attribute__((signal));
void __vector_13(void)
{
	UART_RX_CALLBACK();
}
//UART DATA REGISTER EMPTY
void __vector_14(void)  __attribute__((signal));
void __vector_14(void)
{
	UART_DRE_CALLBACK();
}
//UART TX COMPLETE

void __vector_15(void)  __attribute__((signal));
void __vector_15(void)
{
	UART_TX_CALLBACK();
}

