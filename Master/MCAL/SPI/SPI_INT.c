/*
 * SPI_INT.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_SPI_SPI_INT_C_
#define MCAL_SPI_SPI_INT_C_
#include"../std_types.h"
#include"../Std_Library.h"
#include"../macros.h"
#include"../../MCAL/DIO/MCAL_DIO_INTERFACE.h"
#include"../../MCAL/DIO/MCAL_DIO_REGISTERS.h"
#include"../../MCAL/GLOBAL_INTERRUPT/GLOBAL_INT_REG.h"
#include"SPI_CNFG.h"
#include"SPI_PRIVATE.h"
#include"SPI_INT.h"
#include"SPI_REG.h"

#if SPI_STATE==SPI_STATE_ENABLE
/*********************interrupt call back*************************/
//static call back PTR
 static void (*UART_SPI_CALLBACK)(void)=NULL;
 /*********************interrupt call back*************************/

/***
 * @brief this function is used to initialize the spi for both master and slave
 * @param ptr is the call back function if interrupt is used if not just send (NULL)
 */
void MSPI_Init(void (*ptr)(void))
{
/**********SET PIN DIRECTION DEPEND ON CONFIGURATIONS IN CNFG.h*************/
SET_DIRECTIONS();

/********selecting mode depend on previous cnfg (CHECK SPI_CNFG.h)***********/
#if SPI_MODE==MASTER
/***********SET MASTER MODE CLOCK SPEED *********/
#if SPI_MASTER_CLOCK_SPEED_PRESCALER==SPI_FOSC_4
SPI_SET_FOSC_4();
#elif SPI_MASTER_CLOCK_SPEED_PRESCALER==SPI_FOSC_16
SPI_SET_FOSC_16();
#elif SPI_MASTER_CLOCK_SPEED_PRESCALER==SPI_FOSC_64
SPI_SET_FOSC_64();
#elif SPI_MASTER_CLOCK_SPEED_PRESCALER==SPI_FOSC_128
SPI_SET_FOSC_128();
#elif SPI_MASTER_CLOCK_SPEED_PRESCALER==SPI_FOSC_2_I2X
SPI_SET_FOSC_2_I2X();
#elif SPI_MASTER_CLOCK_SPEED_PRESCALER==SPI_FOSC_8_I2X
SPI_SET_FOSC_8_I2X();
#elif SPI_MASTER_CLOCK_SPEED_PRESCALER==SPI_FOSC_32_I2X
SPI_SET_FOSC_32_I2X();
#elif SPI_MASTER_CLOCK_SPEED_PRESCALER==SPI_FOSC_64_I2X
SPI_SET_FOSC_64_I2X();
#else
#error "WRONG CONFIGURATION FOR SPI CLOCK SPEED"
#endif
#elif SPI_MODE==SLAVE
SPI_ENABLE_SLAVE_MODE();
#else
#error "WRONG SPI MODE"
#endif
SPI_ENABLE_MASTER_MODE();

/*********select LSB***********/
#if SPI_SEND_FORMAT==SPI_SEND_LSB_BIT_FIRST
SPI_SEND_LSB_FIRST();
#elif SPI_SEND_FORMAT==SPI_SEND_MSB_BIT_FIRST
SPI_SEND_MSB_FIRST();
#else
#error "WRONG SPI DATA FORMAT"
#endif

/***********select clock polarity as leading edge raising*********/
#if SPI_CLOCK_POLARITY==SPI_ENABLE_IDLE_LOGIC_LOW
SPI_ENABLE_ILDE_LOW();
#elif SPI_CLOCK_POLARITY==SPI_ENABLE_IDLE_LOGIC_HIGH
SPI_ENABLE_IDLE_HIGH();
#else
#error "WRONG SPI CLOCK POLARITY CONFIG"
#endif
/***********select clock phase as leading Setup*********/
#if SPI_SAMPLE_CNFG==SPI_SAMPLE_AT_TRAILLING_EDGE
SPI_SAMPLE_AT_TRAILLING();
#elif SPI_SAMPLE_CNFG==SPI_SAMPLE_AT_LEADING_EDGE
SPI_SAMPLE_AT_LEADING();
#else
#error "WRONG SPI CLOCK PHASE CNFG"
#endif
/**********************INTERRUPT CNFG***********************/
#if SPI_INTERRUPT==SPI_INTERRUPT_ENABLE
/**********set the SPI call back***********/
	if(NULL!=ptr)
	{
	UART_SPI_CALLBACK=ptr;
	}
	else{}
/**********enable the global interrupt************/
Enable_Global_Interrupt();
/*************enable SPI interrupt****************/
SPI_ENABLE_INTERRUPT();
#elif SPI_INTERRUPT==SPI_INTERRUPT_DISABLE
SPI_DISABLE_INTERRUPT();
#else
#error "WRONG SPI INTERRUPT CNFG"
#endif
//clearing the wcol
/*********Enable SPi***********/
SPI_ENABLE();
}


/***
 * brief this function is used to send and receive data neither you act as master or slave (blocking means with out interrupts)
 * @param Data is the data the device going to send
 * @return the value which is received
 */
u8 MSPI_TRANSCIEVE_BLOCKING(u8 Data)
{
SPDR=Data;
while(!(GET_BIT(SPSR,SPSR_SPIF)));
return SPDR;
}
/***
 * @brief this function is used to transcieve data using interrupt
 * @param Data is data going to send
 * @return return the received data
 */
u8 SPI_TRANSCIEVE(u8 Data)
{
u8 L_READ=0;
//interrupt happen when transmitting first time is already happen
L_READ=SPDR;
//after we read the received data we set the new data into the data line
SPDR=Data;
return L_READ;
}
void SPI_INIT(void)
{

	/* Set MOSI and SCK output, all others input */
	DDRB = (1<<5)|(1<<7);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPCR_SPE)|(1<<SPCR_MSTR)|(1<<SPCR_SPR0);



}



/***
 * @brief this function is used to initiallize the direction of pins master or slave
 */
static inline void SET_DIRECTIONS(void)
{
	switch(SPI_MODE)
	{
	case MASTER :
				//set the SCK as OUTPUT
				DIO_PIN_DIRECTION_INIT_M(PORTB_,pin7,DIRECTION_OUTPUT);
				//set the MOSI as OUTPUT
				DIO_PIN_DIRECTION_INIT_M(PORTB_,pin5,DIRECTION_OUTPUT);
				//set the SS as output
				DIO_PIN_DIRECTION_INIT_M(PORTB_,pin4,DIRECTION_OUTPUT);
				//set the MISO as INPUT
				DIO_PIN_DIRECTION_INIT_M(PORTB_,pin6,DIRECTION_INPUT);
				break;
	case SLAVE  :
				//set the SCK as DIRECTION_INPUT
				DIO_PIN_DIRECTION_INIT_M(PORTB_,pin7,DIRECTION_INPUT);
				//set the MOSI as DIRECTION_INPUT
				DIO_PIN_DIRECTION_INIT_M(PORTB_,pin5,DIRECTION_INPUT);
				//set the SS as DIRECTION_INPUT
				DIO_PIN_DIRECTION_INIT_M(PORTB_,pin4,DIRECTION_INPUT);
				//set the MISO as DIRECTION_OUTPUT
				DIO_PIN_DIRECTION_INIT_M(PORTB_,pin6,DIRECTION_OUTPUT);
				break;
	default :break;
	}
}
/***
 *
 * @param Data
 * @return
 */


void __vector_12(void)  __attribute__((signal));
void __vector_12(void)
{

	UART_SPI_CALLBACK();
}

#endif
#endif /* MCAL_SPI_SPI_INT_C_ */
