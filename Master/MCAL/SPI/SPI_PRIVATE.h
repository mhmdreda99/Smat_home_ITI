/*
 * SPI_PRIVATE.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

//macro deceleration

/***********Enable or Disable SPI**************/
#define SPI_STATE_ENABLE      1
#define SPI_STATE_DISABLE     2

/***********select master or slave mode*********/
#define MASTER    1
#define SLAVE     2
/****************select master transmitting speed*************/
#define SPI_FOSC_4         0
#define SPI_FOSC_16        1
#define SPI_FOSC_64        2
#define SPI_FOSC_128       3
#define SPI_FOSC_2_I2X     4
#define SPI_FOSC_8_I2X     5
#define SPI_FOSC_32_I2X    6
#define SPI_FOSC_64_I2X    7
/****************SELECT SENDING FORMAT**************/
#define SPI_SEND_LSB_BIT_FIRST   1
#define SPI_SEND_MSB_BIT_FIRST   2
/****************SPI CLOCK POLARITY**************/
#define SPI_ENABLE_IDLE_LOGIC_HIGH    1
#define SPI_ENABLE_IDLE_LOGIC_LOW     2
/***********select clock phase as leading Setup*********/
#define SPI_SAMPLE_AT_LEADING_EDGE       1
#define SPI_SAMPLE_AT_TRAILLING_EDGE     2
/*********************INTERRUPT CNFG*****************/
#define SPI_INTERRUPT_ENABLE   1
#define SPI_INTERRUPT_DISABLE   2
/*************Static helper functions****************/
static inline void SET_DIRECTIONS(void);

#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
