/*
 * MCAL_I2C_PRIVATE.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_I2C_MCAL_I2C_PRIVATE_H_
#define MCAL_I2C_MCAL_I2C_PRIVATE_H_
/*********PRESCALER VALUES**********/
#define I2C_DIV_1        			1
#define I2C_DIV_4        			2
#define I2C_DIV_16        			3
#define I2C_DIV_64        			4
/************SELECT I2C SPEED************/
#define I2C_STANDART_MODE_100kb_s     1
#define I2C_FAST_MODE_400kb_s   	  2
#define I2C_STANDART_MODE_25kb_s      3
#define I2C_STANDART_MODE_6250kb_s    4

/***********INTERRUPT STATE**********************/
#define I2C_INTERRUPT_STATE_ENABLE      1
#define I2C_INTERRUPT_STATE_DISABLE     2
/*******HELPER FUNCTIONS DECLERATIONS************/
static inline void I2C_SETSPEED(void);

#endif /* MCAL_I2C_MCAL_I2C_PRIVATE_H_ */
