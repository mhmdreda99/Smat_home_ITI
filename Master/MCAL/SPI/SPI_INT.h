/*
 * SPI_INT.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_



/************************MACRO FUNCTIONS SECTION****************************/
//SPE: SPI Enable
#define SPI_ENABLE()   SET_BIT(SPCR,SPCR_SPE)
#define SPI_DISABLE()  CLEAR_BIT(SPCR,SPCR_SPE)


// DORD: Data Order
#define SPI_SEND_LSB_FIRST()    SET_BIT(SPCR,SPCR_DORD)
#define SPI_SEND_MSB_FIRST()    CLEAR_BIT(SPCR,SPCR_DORD)


//MSTR: Master/Slave Select
#define SPI_ENABLE_MASTER_MODE()   SET_BIT(SPCR,SPCR_MSTR)
#define SPI_ENABLE_SLAVE_MODE()    CLEAR_BIT(SPCR,SPCR_MSTR)


//CLOCK POLARITY
#define SPI_ENABLE_IDLE_HIGH()     SET_BIT(SPCR,SPCR_CPOL)
#define SPI_ENABLE_ILDE_LOW()      CLEAR_BIT(SPCR,SPCR_CPOL)


//Clock Phase
#define SPI_SAMPLE_AT_LEADING()    CLEAR_BIT(SPCR,SPCR_CPHA)
#define SPI_SAMPLE_AT_TRAILLING()  SET_BIT(SPCR,SPCR_CPHA)
/********************************SELECTING CLOCK********************************/
#define SPI_SET_FOSC_4()                         do{\
											       CLEAR_BIT(SPCR,SPCR_SPR0);\
											       CLEAR_BIT(SPCR,SPCR_SPR1);\
											       CLEAR_BIT(SPSR,SPSR_I2X);}\
												 while(0)

#define SPI_SET_FOSC_16()                         do{\
											       SET_BIT(SPCR,SPCR_SPR0);\
											       CLEAR_BIT(SPCR,SPCR_SPR1);\
											       CLEAR_BIT(SPSR,SPSR_I2X);}\
												 while(0)

#define SPI_SET_FOSC_64()                         do{\
											       CLEAR_BIT(SPCR,SPCR_SPR0);\
											       SET_BIT(SPCR,SPCR_SPR1);\
											       CLEAR_BIT(SPSR,SPSR_I2X);}\
												 while(0)

#define SPI_SET_FOSC_128()                         do{\
											       SET_BIT(SPCR,SPCR_SPR0);\
											       SET_BIT(SPCR,SPCR_SPR1);\
											       CLEAR_BIT(SPSR,SPSR_I2X);}\
												 while(0)

#define SPI_SET_FOSC_2_I2X()                         do{\
											       CLEAR_BIT(SPCR,SPCR_SPR0);\
											       CLEAR_BIT(SPCR,SPCR_SPR1);\
											       SET_BIT(SPSR,SPSR_I2X);}\
												 while(0)

#define SPI_SET_FOSC_8_I2X()                         do{\
											       SET_BIT(SPCR,SPCR_SPR0);\
											       CLEAR_BIT(SPCR,SPCR_SPR1);\
											       SET_BIT(SPSR,SPSR_I2X);}\
												 while(0)


#define SPI_SET_FOSC_32_I2X()                         do{\
											       CLEAR_BIT(SPCR,SPCR_SPR0);\
											       SET_BIT(SPCR,SPCR_SPR1);\
											       SET_BIT(SPSR,SPSR_I2X);}\
												 while(0)

#define SPI_SET_FOSC_64_I2X()                         do{\
											       SET_BIT(SPCR,SPCR_SPR0);\
											       SET_BIT(SPCR,SPCR_SPR1);\
											       SET_BIT(SPSR,SPSR_I2X);}\
												 while(0)


/***************SPI Interrupt cnfg****************/
#define SPI_ENABLE_INTERRUPT()  SET_BIT(SPCR,SPCR_SPIE)
#define SPI_DISABLE_INTERRUPT() CLEAR_BIT(SPCR,SPCR_SPIE)

/******************FUNCTION DECLERATION*********************/

/***
 * @brief this function is used to initialize the spi for both master and slave
 * @param ptr is the call back function if interrupt is used if not just send (NULL)
 */
void MSPI_Init(void (*ptr)(void));

/***
 * brief this function is used to send and receive data neither you act as master or slave
 * (blocking means with out interrupts)
 * @param Data is the data the device going to send
 * @return the value which is received
 */
u8 MSPI_TRANSCIEVE_BLOCKING(u8 Data);

/***
 * @brief this function is used to transcieve data using interrupt
 *  (you have to send dummy data before while(1) to fire the interrupt
 * @param Data is data going to send
 * @return return the received data
 */
u8 SPI_TRANSCIEVE(u8 Data);

#endif /* MCAL_SPI_SPI_INT_H_ */
