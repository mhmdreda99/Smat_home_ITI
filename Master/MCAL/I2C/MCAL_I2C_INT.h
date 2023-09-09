/*
 * MCAL_I2C_INT.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

#ifndef MCAL_I2C_MCAL_I2C_INT_H_
#define MCAL_I2C_MCAL_I2C_INT_H_

/******************MACRO FUNCTION SECTION************************/
//Enable I2C
#define I2C_ENABLE()  SET_BIT(TWCR,TWCR_TWEN)
//Disable I2C
#define I2C_DISABLE() CLEAR_BIT(TWCR,TWCR_TWEN)
//Disconnect your slave from the bus temporarily and reconnect it by setting the ACK feature
#define I2C_DISCONNECT_DEVICE()            CLEAR_BIT(TWCR,TWCR_TWEA)

/******************Frame Section***************/
//IF YOU WANT TO USE ENABLE ACK AFTER EVERY RECEVING
#define I2C_ENABLE_GENERATING_ACK()        SET_BIT(TWCR,TWCR_TWEA)
//I2C_SEND_START
#define I2C_SEND_START()  		  TWCR = (1<<TWCR_TWINT)|(1<<TWCR_TWSTA)|(1<<TWCR_TWEN)
//CLEARING START IS MUST AFTER START CONDITION IS COMPLETLEY ON THE BUS
#define I2C_CLEAR_START_LOGIC()   CLEAR_BIT(TWCR,TWCR_TWSTA)
//I2C SEND STOP *NOTE* AUTOMATIC CLEARING IS PROVIDED BY HARDWARE
#define I2C_SEND_STOP()			  TWCR=(1<<TWCR_TWINT)|(1<<TWCR_TWEN)| (1<<TWCR_TWSTO);

/********************ENABLE GENERAL CALL***************/
#define I2C_ENABLE_GENERAL_CALL()   SET_BIT(TWAR,TWAR_TWGCE)
/********************SPEED CNFG SECTION *****************/
//you could select between 4 speeds from CNFG.h
// you could customize another speed by this macro functions for TWPS and set the required speed in
//and using this equation TWBR = (F_CPU / Required_Frequency - 16.0) / (2.0 * pow(4, TWPS));
#define I2C_PRESCALER_DIV_1()     do{\
 	 	 	 	 	 	 	 	 	 CLEAR_BIT(TWSR,TWSR_TWPS0);\
 	 	 	 	 	 	 	 	 	 CLEAR_BIT(TWSR,TWSR_TWPS1);}\
								  while(0)

#define I2C_PRESCALER_DIV_4()     do{\
 	 	 	 	 	 	 	 	 	 SET_BIT(TWSR,TWSR_TWPS0);\
 	 	 	 	 	 	 	 	 	 CLEAR_BIT(TWSR,TWSR_TWPS1);}\
								  while(0)

#define I2C_PRESCALER_DIV_16()     do{\
 	 	 	 	 	 	 	 	 	 CLEAR_BIT(TWSR,TWSR_TWPS0);\
 	 	 	 	 	 	 	 	 	 SET_BIT(TWSR,TWSR_TWPS1);}\
								  while(0)

#define I2C_PRESCALER_DIV_64()     do{\
 	 	 	 	 	 	 	 	 	 SET_BIT(TWSR,TWSR_TWPS0);\
 	 	 	 	 	 	 	 	 	 SET_BIT(TWSR,TWSR_TWPS1);}\
								  while(0)
/**********INTERRUPT SECTION************/
//Enable I2C INTERRUPT
#define I2C_INTERRUPT_ENABLE()         SET_BIT(TWCR,TWCR_TWIE)
//DISABLE I2C INTERRUPT
#define I2C_INTERRUPT_DISABLE()        CLEAR_BIT(TWCR,TWCR_TWIE)
//clear interrupt flag is must after every process
#define I2C_CLEAR_FLAG()               SET_BIT(TWCR,TWCR_TWINT)
#define I2C_READ_FLAG()                GET_BIT(TWCR,TWCR_TWINT)

/**************DATA TYPE SECTION****************/


/**************FUNCTION DECLERATIONS*****************/
void I2C_INIT(void(*I2C_Callback_Ptr)(void));
void I2C_START(void);
void I2C_WRITE(u8 Data);
u8 I2C_READ_WITH_ACK(void);
void I2C_STOP(void);
u8 I2C_GETSTATUS(void);
void I2C_START1(void);


#endif /* MCAL_I2C_MCAL_I2C_INT_H_ */
