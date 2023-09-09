/*
 * MCAL_I2C_CNFG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_I2C_MCAL_I2C_CNFG_H_
#define MCAL_I2C_MCAL_I2C_CNFG_H_
/****I2C PRESCALER >>I2C_DIV_1
				 * >>I2C_DIV_4
				 * >>I2C_DIV_16
				 * >>I2C_DIV_64*******/

#define I2C_PRESCALER         I2C_DIV_4


#define I2C_SPEED_MODE        I2C_STANDART_MODE_100kb_s

#define I2C_ADDRESS            0x01

#define I2C_INTERRUPT_STATE    I2C_INTERRUPT_STATE_DISABLE
#endif /* MCAL_I2C_MCAL_I2C_CNFG_H_ */
