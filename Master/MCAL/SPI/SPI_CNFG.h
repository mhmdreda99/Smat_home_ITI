/*
 * SPI_CNFG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_SPI_SPI_CNFG_H_
#define MCAL_SPI_SPI_CNFG_H_

/*SELECT (SPI_STATE_ENABLE) or (SPI_STATE_DISABLE)*/
#define SPI_STATE								     SPI_STATE_ENABLE
/*SELECT (MASTER) or (SLAVE)*/
#define SPI_MODE      								 MASTER
/**********SELECT MASTER SPEED************/
#define SPI_MASTER_CLOCK_SPEED_PRESCALER             SPI_FOSC_128
/**************SELECTING MSB OR LSB SHIFTED FIRST*************/
#define SPI_SEND_FORMAT     					 	 SPI_SEND_LSB_BIT_FIRST
/**************SELECT CLOCK POLARITY******************/
#define SPI_CLOCK_POLARITY                           SPI_ENABLE_IDLE_LOGIC_LOW
/*****************SELECT CLOCK PHASE *********************/
#define SPI_SAMPLE_CNFG								SPI_SAMPLE_AT_LEADING_EDGE
/**************************INTERRUPT CNFG***********************/
#define SPI_INTERRUPT                                SPI_INTERRUPT_DISABLE
#endif /* MCAL_SPI_SPI_CNFG_H_ */
