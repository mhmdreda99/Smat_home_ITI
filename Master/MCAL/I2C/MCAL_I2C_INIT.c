/*
 * MCAL_I2C_INIT.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: m
 */

/************include section***************/
#include "../std_types.h"
#include "../Std_Library.h"
#include "../macros.h"
#include"../GLOBAL_INTERRUPT/GLOBAL_INT_REG.h"
#include "MCAL_I2C_PRIVATE.h"
#include "MCAL_I2C_CNFG.h"
#include "MCAL_I2C_REG.h"
#include "MCAL_I2C_INT.h"

/*********************************************************/

 static void (*I2C_CALLBACK)(void)=NULL;
/*********************************************************/
 /***
  * @brief this function is used to initialize the I2C(TWI)
  *
  * @param I2C_Callback_Ptr  is a ptr to the call back function
  * if you have interrupt pass the address of ur called function
  * if you have no interrupt SET it by (NULL)
  */
void I2C_INIT(void(*I2C_Callback_Ptr)(void))
{
	/*****SET MASTER |SLAVE ADDRESS */
TWAR=I2C_ADDRESS<<1;
/*set I2C SPEED*/
I2C_SETSPEED();
/*********ENABLE ACK***********/
I2C_ENABLE_GENERATING_ACK();

#if I2C_INTERRUPT_STATE==I2C_INTERRUPT_STATE_ENABLE
/*enable global interrupt*/
Enable_Global_Interrupt();
/*set interrupt call back*/
I2C_CALLBACK=I2C_Callback_Ptr;
/*enable the i2c interrupt*/
I2C_INTERRUPT_ENABLE();
#endif
/**********ENABLE I2C**********/
I2C_ENABLE();
}
/*********************************************************/

/***
 * @brief this function is used to send start condition on i2C bus
 */
void I2C_START(void)
{
/*SET TWSTA &TWEN &TWINT to start condition*/
I2C_SEND_START();
//busy wait
while(I2C_READ_FLAG()==0);
}

/***************************************************/
/***
 * @brief this function is used to write data, address on i2C bus
 * @param Data
 */
void I2C_WRITE(u8 Data)
{
/*SET DATA | Address to TWD*/
TWDR=Data;
/*CLEAR  start condition*/
I2C_CLEAR_START_LOGIC();
/*CLEAR FLAG*/
I2C_CLEAR_FLAG();
/*****ENABLE I2C********/
I2C_ENABLE();
/*busy wait*/
while(I2C_READ_FLAG()==0);


}
/***************************************************/
/***
 * @brief this function is used to read the data from i2C bus
 * @return
 */
u8 I2C_READ_WITH_ACK(void)
{
	/*CLEAR  start condition*/
	I2C_CLEAR_START_LOGIC();
	/*CLEAR FLAG*/
	I2C_CLEAR_FLAG();
	/*****ENABLE I2C********/
	I2C_ENABLE();
	/*busy wait*/
	while(I2C_READ_FLAG()==0);
return TWDR;
}

/***************************************************/

/***
 * @brief this function is used to Send STOP ON i2C bus
 */
void I2C_STOP(void)
{
	I2C_SEND_STOP();

}
u8 I2C_GETSTATUS(void)
{
return (TWSR&0xF8);
}


 static inline void I2C_SETSPEED(void)
{
#if I2C_SPEED_MODE==I2C_STANDART_MODE_400kb_s
I2C_PRESCALER_DIV_1();
TWBR=2;
#elif I2C_SPEED_MODE==I2C_STANDART_MODE_100kb_s
I2C_PRESCALER_DIV_4();
TWBR=2;
#elif I2C_SPEED_MODE==I2C_STANDART_MODE_25kb_s
I2C_PRESCALER_DIV_16();
TWBR=2;
#elif I2C_SPEED_MODE==I2C_STANDART_MODE_6250kb_s
I2C_PRESCALER_DIV_64();
TWBR=2;
#else
#error "INVALID PRESCALER FOR I2C"


#endif
}

 void __vector_19(void)  __attribute__((signal));
 void __vector_19(void)
 {
 	I2C_CALLBACK();
 }
